// File 	   : DominantPathsProtocols/NonRestartingProtocol/NonRestartingProtocolCode.cpp

#include "DominantPathsProtocols/NonRestartingProtocol/NonRestartingProtocolCode.h"

namespace DominantPathsProtocols
{
	namespace NonRestartingProtocol
	{
		std::uniform_real_distribution < double > dist(0.01, 1);

		template < typename S, typename Ext >
		void Extension(		
			const 				  			  S    & attrWeight , 
			const Advert 					< S >  & advert 	, 
			DomEntry       					< S >  & domTab		) 
		{
			Ext ext;

			domTab.clear();

			for( auto item  = advert.begin() ; 
					  item != advert.end()   ; item ++ )
			{	
				S 	attr 	= item->first  ;
				int hops  	= item->second ;
				
				hops ++;								
				S 	cand	= ext( attrWeight, attr );	

				if( hops < 15 and cand != Ext :: Null )
				{	domTab.insert( { cand, hops } ); }
			}
			return;
		}

		template < typename S, typename Ord >
		bool Election(		
			std::unordered_map < int, 
								 DomEntry < S > >  	&  domTabs 	,
			DomEntry < S >    					  	&  dom 	 	)
		{
			Ord ord;

			DomEntry 	< S > prevDom = dom;
			dom.clear();

			for( auto it1  = domTabs.begin() 			; 
					  it1 != domTabs.end() 	 			; it1 ++ )
			{
				DomEntry < S > domTab1 = it1->second; 

				for ( auto 	item1     = domTab1.begin() 	; 
							item1    != domTab1.end() 	; item1 ++ )
				{
					S   cand1		  = item1->first;
					int hops1  		  = item1->second;

					bool isDominant   = true;

					for( auto   it2   = domTabs.begin() 			; 
					  			it2  != domTabs.end() 			; it2 ++ )
					{
						DomEntry < S > domTab2 = it2->second; 

						for ( auto 	item2  = domTab2.begin() 	; 
									item2 != domTab2.end() 		; item2 ++ )
						{ 
							S 	cand2 = item2->first;
							int hops2 = item2->second;

							if( ( ord( cand2, cand1 ) ) or ( cand2 == cand1 and hops2 < hops1 ) )
							{
								isDominant = false;
								goto EndTest;
							}
						}
					}

					EndTest:
					if( isDominant == true )
					{					
						dom.insert( { cand1, hops1 } );					
					}
				}
			}
			return ( dom != prevDom );
		}

		template < 	typename S, typename Ord, typename Ext	>
		void DestinationAnnouncement( 
			const Graph 	   < S > & graph 		,
				  RoutingState < S > & routingState ,
				  std::mt19937 		 & gen			,
			const int 				 & t   			)
		{
			routingState.dom[t][t].insert( { { Ord :: Neutral, 0 } } );

			DomEntry < S > outAdv;
			outAdv.insert( { Ord :: Neutral, 0 } );

			for( auto it  = graph.adjListIn[t].begin() 	; 
					  it != graph.adjListIn[t].end() 	; it ++ )
			{
				int 	  w = it->first;
				bool active = it->second.first;
			
				if( active )
				{
					std::pair < int, int > l  = { w, t };
					double at = dist( gen );
					routingState.routeQueue.push( { l, { at, { t, outAdv } } } );
				}
			}
		}

		template < 	typename S, typename Ord, typename Ext	>
		void IntermediateNode(	
			const Graph 		< S > 		& graph 		,
				  RoutingState 	< S > 		& routingState 	,
				  std::mt19937  			& gen			,
			const double 					& ct 			,
			const int 						& u 			,
			const int 						& v 			,
			const int 						& t 			, 
			const Advert 		< S > 		& inAdv 		)
		{
			if( u == t )
			{	
				return;	
			}

			S weight = graph.adjListOut[u].at(v).second;

			Extension < S, Ext > ( 			weight 						 , 
											inAdv 						 , 
											routingState.domTab[u][t][v] );

			bool changed;
			changed = Election < S, Ord > ( routingState.domTab[u][t]	 , 
											routingState.dom[u][t] 		 );

			if( changed == true )
			{
				double qt;

				Advert < S > outAdv = routingState.dom[u][t];
			
				for( auto it  = graph.adjListIn[u].begin() 	; 
					  	  it != graph.adjListIn[u].end() 	; it ++ )
				{
					int 	  w = it->first;
					bool active = it->second.first;
				
					if( active )
					{
						std::pair < int, int > l = { w, u };
						if( routingState.routeQueue.count(l) == 1 )	
						{	
							qt = routingState.routeQueue.at(l).first; 	
						}
						else												
						{	
							qt = 0; 										
						}
						double at = std::max( qt, ct + dist(gen) 	);					
						routingState.routeQueue.push( { l, { at, { t, outAdv } } } );
					}
				}
			}

			return;
		}

		template < 	typename S, typename Ord, typename Ext	>
		void LinkFailure( 						
			Graph 		 < S > 			  	& graph 		,
			RoutingState < S > 			  	& routingState  ,
			std::vector  < std::mt19937 > 	& gens			,
	  	  const int 						& u  			,
	  	  const int 						& v  			)
		{	
			graph.deactivate( u, v );

			for( int t = 0 ; t < graph.V ; t ++ )
			{
				if( u == t )
				{	
					continue;	
				}

				routingState.domTab[u][t][v].clear(); 

				bool changed;
				changed = Election < S, Ord > ( routingState.domTab[u][t], 
												routingState.dom[u][t]   );

				if( changed == true )
				{
					double qt;

					Advert < S > outAdv = routingState.dom[u][t];

					for( auto it  = graph.adjListIn[u].begin() 	; 
							  it != graph.adjListIn[u].end() 	; it ++ )
					{
						int 	  w = it->first;
						bool active = it->second.first;
				
						if( active )
						{
							std::pair < int, int > l = { w, u };
							if( routingState.routeQueue.count(l) == 1 )	
							{	
								qt = routingState.routeQueue.at(l).first; 	
							}
							else												
							{	
								qt = 0; 										
							}
							double at = std::max( qt, dist(gens[t]) );					
							routingState.routeQueue.push( { l, { at, { t, outAdv } } } );
						}
					}
				}
			}
		}
	}
}

#include "DominantPathsProtocols/NonRestartingProtocol/NonRestartingProtocolCodeInstances.h"



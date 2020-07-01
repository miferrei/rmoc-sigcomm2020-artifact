// File : DominantPathsProtocols/NonRestartingProtocol/NonRestartingRoutingState.h

// Description: 

#ifndef _NONRESTARTINGPROTOCOLROUTINGSTATE_H_
#define _NONRESTARTINGPROTOCOLROUTINGSTATE_H_

#include <boost/functional/hash.hpp>
#include <unordered_map>
#include <unordered_set>
#include <utility>

// My Library
#include "DataStructures/AugmentedPriorityQueue.h"

using namespace DataStructures;

namespace DominantPathsProtocols
{
	namespace NonRestartingProtocol
	{	
		template < class S >
		using Advert 	= std::unordered_set < std::pair < S, int >, 		 
							     boost::hash < std::pair < S, int > > >;

		template < class S >
		using DomEntry 	= Advert < S >;
							 
		template < class S >
		struct Route
		{
			int t;
			Advert < S > adv;
		
		   	Route(){};
		   	Route( int,  Advert < S > );
		   	Route( const Route & 	  );

			friend void swap( Route & l, 
							  Route & r )
			{
				std::swap( l.t,   r.t );
				std::swap( l.adv, r.adv );
			}

			Route & operator= ( Route );		
		};

		template < class S >
		struct RoutingState 
		{	
			std::unordered_map < int, 
								 std::unordered_map < int, 
								 					  std::unordered_map < int, 
								 					  					   DomEntry < S > > > > domTab;
			std::unordered_map < int, 
								 std::unordered_map < int, 
								 					  DomEntry  < S > > > 					   	   dom;
			AugmentedPriorityQueue 	< 
		   		std::pair < int, int >, 
		   		double, 
		   		Route < S > > routeQueue;

		   	RoutingState(){};
		   	RoutingState( int );
		   	RoutingState( const RoutingState & );

			friend void swap( RoutingState & l, RoutingState & r )
			{	
				std::swap( l.domTab, 	 r.domTab 		);
				std::swap( l.dom, 		 r.dom 			);
				std::swap( l.routeQueue, r.routeQueue 	);			
			}

			RoutingState & operator = ( RoutingState );
		};
	}
}

#endif
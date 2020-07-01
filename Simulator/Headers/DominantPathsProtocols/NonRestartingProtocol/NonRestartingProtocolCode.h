// File 	   : DominantPathsProtocols/NonRestartingProtocol/NonRestartingProtocolCode.cpp

#ifndef _NONRESTARTINGPROTOCOLPROTOCOLCODE_H_
#define _NONRESTARTINGPROTOCOLPROTOCOLCODE_H_

#include <random>
#include <vector>

#include "DominantPathsProtocols/NonRestartingProtocol/NonRestartingRoutingState.h"
#include "Graphs/Graphs.h"

using namespace Graphs;

namespace DominantPathsProtocols
{	
	namespace NonRestartingProtocol
	{
		template < typename S, typename Ext >
		void Extension 							(	
			const 				  	  S     			&  	,
			const Advert 			< S > 				&  	,	
			DomEntry   				< S > 				& 	);

		template < typename S, typename Ord >
		bool Election 				(		
			std::unordered_map < int, 
								 DomEntry < S > >  		&   ,
			DomEntry < S >    					  		&  	);

		template < 	typename S, typename Ord, typename Ext	>
		void IntermediateNode 					(				
			const Graph 			< S > 				&  	,
	  			RoutingState 		< S > 				&  	,
	  			std::mt19937  							& 	,
			const double 								&  	,
			const int 									&  	,
			const int 									&  	,
			const int 									&  	, 
			const Advert 			< S > 				&  	);

		template < 	typename S, typename Ord, typename Ext	>
		void DestinationAnnouncement 			( 	
			const Graph 	 		< S > 				& 	,
				RoutingState 		< S > 				& 	,
				std::mt19937  							& 	,
		  	const int 									&	);

		template < 	typename S, typename Ord, typename Ext	>
		void LinkFailure 						( 				 	
				  Graph 	 	 	< S > 				&  	,
				RoutingState 		< S > 				& 	,
				std::vector  < std::mt19937 > 			& 	,
	  	  	const int 									& 	,
	  	  	const int 									&   );
	}
}

#endif

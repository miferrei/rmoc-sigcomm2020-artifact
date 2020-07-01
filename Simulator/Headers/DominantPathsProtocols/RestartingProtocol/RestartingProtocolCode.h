// File 	   : DominantPathsProtocols/RestartingProtocol/RestartingProtocolCode.cpp

#ifndef _RESTARTINGPROTOCOLCODE_H_
#define _RESTARTINGPROTOCOLCODE_H_

#include <random>
#include <vector>

#include "DominantPathsProtocols/RestartingProtocol/RestartingRoutingState.h"
#include "Graphs/Graphs.h"

using namespace Graphs;

namespace DominantPathsProtocols
{	
	namespace RestartingProtocol
	{
		template < 	typename S, typename Ord, typename Ext	>
		void DestinationAnnouncement 					( 	
			const Graph 	 		< S > 				& 	,
				RoutingState 		< S > 				& 	,
				std::mt19937  							& 	,
		  	const int 									&	);

		template < 	typename S, typename Ord, typename Ext	>
		void IntermediateNodeDestinationAnnouncement 	(				
			const Graph 			< S > 				&  	,
	  			RoutingState 		< S > 				&  	,
	  			std::mt19937  							& 	,
			const double 								&  	,
			const int 									&  	,
			const int 									&  	,
			const int 									&  	, 
			const Advertisement 	< S > 				&  	);

		template < 	typename S, typename Ord, typename Ext	>
		void LinkFailure 								( 				 	
				  Graph 	 	 	< S > 				&  	,
				RoutingState 		< S > 				& 	,
				std::vector  < std::mt19937 > 			& 	,
	  	  	const int 									& 	,
	  	  	const int 									&   );

		template < 	typename S, typename Ord, typename Ext	>
		void IntermediateNodeLinkFailure 				(				
			const Graph 			< S > 				&  	,
	  			RoutingState 		< S > 				&  	,
	  			std::mt19937  							& 	,
			const double 								&  	,
			const int 									&  	,
			const int 									&  	,
			const int 									&  	, 
			const Advertisement 	< S > 				&  	);
	}
}

#endif

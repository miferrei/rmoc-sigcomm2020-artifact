// File : DominantPathsVectoringProtocols/RestartingProtocol/RestartingRoutingSimulator.cpp

// Project Library 
#include "DominantPathsProtocols/RestartingProtocol/RestartingRoutingSimulator.h"
#include "DominantPathsProtocols/RestartingProtocol/RestartingProtocolCode.h"

namespace DominantPathsProtocols
{	
	namespace RestartingProtocol
	{
		template < typename S, typename Ord, typename Ext >
		double RoutingSimulator( 	
			const Graph  < S > 			  & graph 		,
			RoutingState < S > 			  & routingState,
			std::vector  < std::mt19937 > & gens		,
			const int 					  & event 		)
		{
			double ct = 0.0;

			while( not routingState.routeQueue.empty() )
			{				
				int u, v, t;
				std::pair < int, int > l;

				l  = routingState.routeQueue.top().first;
				ct = routingState.routeQueue.top().second.first;
				Route 		 	< S > route = routingState.routeQueue.top().second.second;

				u  = l.first;
				v  = l.second;
				t  = route.t;
				Advertisement 	< S > adv = route.adv;

				routingState.routeQueue.pop();

				if( event == 0 )
				{
					IntermediateNodeDestinationAnnouncement  < S, Ord, Ext > ( graph, routingState, gens[t], ct, u, v, t, adv );
				}
				if( event == 1 )
				{
					IntermediateNodeLinkFailure   			 < S, Ord, Ext > ( graph, routingState, gens[t], ct, u, v, t, adv );
				}
			}
			return ct;
		}
	}
}

#include "DominantPathsProtocols/RestartingProtocol/RestartingRoutingSimulatorInstances.h"

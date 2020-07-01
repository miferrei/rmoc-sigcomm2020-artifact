// File : DominantPathsProtocols/NonRestartingProtocol/RoutingSimulator.cpp

#include "DominantPathsProtocols/NonRestartingProtocol/NonRestartingRoutingSimulator.h"
#include "DominantPathsProtocols/NonRestartingProtocol/NonRestartingProtocolCode.h"

namespace DominantPathsProtocols
{	
	namespace NonRestartingProtocol
	{
		template < typename S, typename Ord, typename Ext >
		double RoutingSimulator( 	
			const Graph  < S > 			  & graph 		,
			RoutingState < S > 			  & routingState,
			std::vector  < std::mt19937 > & gens		)
		{
			double ct = 0.0;

			while( not routingState.routeQueue.empty() )
			{				
				int u, v, t;
				std::pair < int, int > l;

				l  = routingState.routeQueue.top().first;
				ct = routingState.routeQueue.top().second.first;
				Route  < S > route = routingState.routeQueue.top().second.second;

				u  = l.first;
				v  = l.second;
				t  = route.t;
				Advert < S > inAdvert = route.adv;

				routingState.routeQueue.pop();

				IntermediateNode < S, Ord, Ext > ( graph, routingState, gens[t], ct, u, v, t, inAdvert );
			}
			return ct;
		}
	}
}

#include "DominantPathsProtocols/NonRestartingProtocol/NonRestartingRoutingSimulatorInstances.h"

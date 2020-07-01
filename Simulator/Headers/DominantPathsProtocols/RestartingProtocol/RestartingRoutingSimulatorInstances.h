// file : DominantPathsProtocols/RestartingProtocol/RestartingRoutingSimulatorInstances.h

// My Libraries
#include "RoutingAlgebras/Orders/Orders.h"
#include "RoutingAlgebras/Extensions/Extensions.h"
#include "Utils/AugmentedStd.h"

using namespace RoutingAlgebras;

namespace DominantPathsProtocols
{
	namespace RestartingProtocol
	{
		template double RoutingSimulator < std::pair < int, int >, POHL,  HL 		> ( 
			const Graph   	< std::pair < int, int > > 			&, 
			RoutingState 	< std::pair < int, int > > 			&,
			std::vector 	< std::mt19937 > 					&, 
			const 			int									& );

		template double RoutingSimulator < std::pair < int, int >, POWH,  WH 		> ( 
			const Graph   	< std::pair < int, int > > 			&, 
			RoutingState 	< std::pair < int, int > > 			&,
			std::vector 	< std::mt19937 > 					&, 
			const 			int									& );

		template double RoutingSimulator < std::pair < int, int >, POWL,  WL 		> ( 
			const Graph   	< std::pair < int, int > > 			&, 
			RoutingState 	< std::pair < int, int > > 			&,
			std::vector 	< std::mt19937 > 					&, 
			const 			int									& );

		template double RoutingSimulator < std::tuple < int, int, int >, POWHL, WHL > ( 
			const Graph   	< std::tuple < int, int, int > > 	&, 
			RoutingState 	< std::tuple < int, int, int > > 	&,
			std::vector 	< std::mt19937 > 					&, 
			const 			int									& );
	}
}

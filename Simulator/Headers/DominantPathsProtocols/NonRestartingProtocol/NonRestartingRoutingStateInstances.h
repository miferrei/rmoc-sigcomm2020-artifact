// File : DominantPathsProtocols/NonRestartingProtocol/NonRestartingRoutingStateInstances.h

// Description : 

namespace DominantPathsProtocols
{
	namespace NonRestartingProtocol
	{
		template struct Route  			< std::pair  < int, int > >;
		template struct Route  			< std::tuple < int, int, int > >;
		template struct RoutingState 	< std::pair  < int, int > >;
		template struct RoutingState 	< std::tuple < int, int, int > >;
	}
}
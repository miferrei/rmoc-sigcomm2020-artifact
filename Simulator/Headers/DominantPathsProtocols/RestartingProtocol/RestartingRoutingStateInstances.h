// File : DominantPathsProtocols/RestartingProtocol/RestartingRoutingStateInstances.h

// Description : 

namespace DominantPathsProtocols
{
	namespace RestartingProtocol
	{
		template struct Route  			< std::pair  < int, int > >;
		template struct Route  			< std::tuple < int, int, int > >;
		template struct RoutingState 	< std::pair  < int, int > >;
		template struct RoutingState 	< std::tuple < int, int, int > >;
	}
}
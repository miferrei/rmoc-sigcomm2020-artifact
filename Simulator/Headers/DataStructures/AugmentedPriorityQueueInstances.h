// File 	   : DataStructures/AugmentedPriorityQueueInstances.h

// Description : 

#include "DominantPathsProtocols/NonRestartingProtocol/NonRestartingRoutingState.h"
#include "DominantPathsProtocols/RestartingProtocol/RestartingRoutingState.h"

using namespace DominantPathsProtocols;

namespace DataStructures
{
	template class AugmentedPriorityQueue < std::pair < int, int >, double, NonRestartingProtocol::Route < std::pair  < int, int > > >;
	template class AugmentedPriorityQueue < std::pair < int, int >, double, NonRestartingProtocol::Route < std::tuple < int, int, int > > >;
	template class AugmentedPriorityQueue < std::pair < int, int >, double,    RestartingProtocol::Route < std::pair  < int, int > > >;
	template class AugmentedPriorityQueue < std::pair < int, int >, double,    RestartingProtocol::Route < std::tuple < int, int, int > > >;
}

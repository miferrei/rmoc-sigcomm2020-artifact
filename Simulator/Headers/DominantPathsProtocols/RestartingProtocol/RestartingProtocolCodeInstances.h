// file : DominantPathsProtocols/RestartingProtocol/RestartingProtocolCodeInstances.h

// My Libraries
#include "RoutingAlgebras/Orders/Orders.h"
#include "RoutingAlgebras/Extensions/Extensions.h"
#include "Utils/AugmentedStd.h"

using namespace RoutingAlgebras;

namespace DominantPathsProtocols
{
	namespace RestartingProtocol
	{
		template void DestinationAnnouncement 					< std::pair < int, int >, POHL, HL 			> (	
			const Graph  		< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::mt19937 			   								&  	,	
		 	const int 				   								&	);

		template void DestinationAnnouncement 					< std::pair < int, int >, POWH, WH 			> (	
			const Graph  		< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::mt19937 			   								&  	,	
		 	const int 				   								&	);

		template void DestinationAnnouncement 					< std::pair < int, int >, POWL, WL 			> (	
			const Graph  		< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::mt19937 			   								&  	,	
		 	const int 				   								&	);

		template void DestinationAnnouncement 					< std::tuple < int, int, int >, POWHL, WHL 	> (	
			const Graph  		< std::tuple < int, int, int > > 	& 	, 
		 	RoutingState  		< std::tuple < int, int, int > > 	&  	, 
			std::mt19937 			   								&  	,	
		 	const int 				   								&	);

		template void IntermediateNodeDestinationAnnouncement 	< std::pair < int, int >, POHL, HL 		> ( 
			const Graph 		< std::pair < int, int > > 			& 	, 
				RoutingState 	< std::pair < int, int > > 			& 	,
				std::mt19937  										& 	, 
				const double 										& 	,
			const int 												& 	,
			const int 												& 	,
			const int 												& 	, 
			const Advertisement < std::pair < int, int > > 			& 	);

		template void IntermediateNodeDestinationAnnouncement 	< std::pair < int, int >, POWH, WH 		> ( 
			const Graph 		< std::pair < int, int > > 			& 	, 
				RoutingState 		< std::pair < int, int > > 		& 	,
				std::mt19937  										& 	, 
				const double 										& 	,
			const int 												& 	,
			const int 												& 	,
			const int 												& 	, 
			const Advertisement < std::pair < int, int > > 			& 	);

		template void IntermediateNodeDestinationAnnouncement 	< std::pair < int, int >, POWL, WL 		> ( 
			const Graph 		< std::pair < int, int > > 			& 	, 
				RoutingState 	< std::pair < int, int > > 			& 	,
				std::mt19937  										& 	, 
				const double 										& 	,
			const int 												& 	,
			const int 												& 	,
			const int 												& 	, 
			const Advertisement < std::pair < int, int > > 			& 	);

		template void IntermediateNodeDestinationAnnouncement 	< std::tuple < int, int, int >, POWHL, WHL > ( 
			const Graph 		< std::tuple < int, int, int > > 	& 	, 
				RoutingState 	< std::tuple < int, int, int > > 	& 	,
				std::mt19937  										& 	, 
				const double 										& 	,
			const int 												& 	,
			const int 												& 	,
			const int 												& 	, 
			const Advertisement < std::tuple < int, int, int > > 	& 	);

		template void LinkFailure 					< std::pair < int, int >, POHL, HL 			> (	
			Graph  				< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::vector  		< std::mt19937 > 					&  	,	
			const int 												& 	,
			const int 												& 	);


		template void LinkFailure 					< std::pair < int, int >, POWH, WH 			> (	
			Graph  				< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::vector  		< std::mt19937 > 					&  	,	
			const int 												& 	,
			const int 												& 	);


		template void LinkFailure 					< std::pair < int, int >, POWL, WL 			> (	
			Graph  				< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::vector  		< std::mt19937 > 					&  	,	
			const int 												& 	,
			const int 												& 	);


		template void LinkFailure 					< std::tuple < int, int, int >, POWHL, WHL 	> (	
			Graph  				< std::tuple < int, int, int > > 	& 	, 
		 	RoutingState  		< std::tuple < int, int, int > > 	&  	, 
			std::vector  		< std::mt19937 > 					&  	,	
			const int 												& 	,
			const int 												& 	);

		template void IntermediateNodeLinkFailure 	< std::pair < int, int >, POHL, HL 		> ( 
			const Graph 		< std::pair < int, int > > 			& 	, 
				RoutingState 	< std::pair < int, int > > 			& 	,
				std::mt19937  										& 	, 
				const double 										& 	,
			const int 												& 	,
			const int 												& 	,
			const int 												& 	, 
			const Advertisement < std::pair < int, int > > 			& 	);

		template void IntermediateNodeLinkFailure 	< std::pair < int, int >, POWH, WH 		> ( 
			const Graph 		< std::pair < int, int > > 			& 	, 
				RoutingState 	< std::pair < int, int > > 			& 	,
				std::mt19937  										& 	, 
				const double 										& 	,
			const int 												& 	,
			const int 												& 	,
			const int 												& 	, 
			const Advertisement < std::pair < int, int > > 			& 	);

		template void IntermediateNodeLinkFailure 	< std::pair < int, int >, POWL, WL 		> ( 
			const Graph 		< std::pair < int, int > > 			& 	, 
				RoutingState 	< std::pair < int, int > > 			& 	,
				std::mt19937  										& 	, 
				const double 										& 	,
			const int 												& 	,
			const int 												& 	,
			const int 												& 	, 
			const Advertisement < std::pair < int, int > > 			& 	);

		template void IntermediateNodeLinkFailure 	< std::tuple < int, int, int >, POWHL, WHL > ( 
			const Graph 		< std::tuple < int, int, int > > 	& 	, 
				RoutingState 	< std::tuple < int, int, int > > 	& 	,
				std::mt19937  										& 	, 
				const double 										& 	,
			const int 												& 	,
			const int 												& 	,
			const int 												& 	, 
			const Advertisement < std::tuple < int, int, int > > 	& 	);
	}
}

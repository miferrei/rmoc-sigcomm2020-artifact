// file : DominantPathsProtocols/NonRestartingProtocol/NonRestartingProtocolCodeInstances.h

// My Libraries
#include "DominantPathsProtocols/NonRestartingProtocol/NonRestartingProtocolCode.h"
#include "RoutingAlgebras/Orders/Orders.h"
#include "RoutingAlgebras/Extensions/Extensions.h"
#include "Utils/AugmentedStd.h"

using namespace RoutingAlgebras;

namespace DominantPathsProtocols
{
	namespace NonRestartingProtocol
	{

		template void Extension < std::pair < int, int >, 		HL > (		
			const 				  	  std::pair < int, int >     					&  	,
			const Advert 			< std::pair < int, int > > 						&  	,	
			DomEntry   				< std::pair < int, int > > 						& 	);

		template void Extension < std::pair < int, int >, 		WH 	> (		
			const 				  	  std::pair < int, int >     					&  	,
			const Advert 			< std::pair < int, int > > 						&  	,	
			DomEntry   				< std::pair < int, int > > 						& 	);

		template void Extension < std::pair < int, int >, 		WL 	> (				
			const 				  	  std::pair < int, int >     					&  	,
			const Advert 			< std::pair < int, int > > 						&  	,	
			DomEntry   				< std::pair < int, int > >	 					& 	);

		template void Extension < std::tuple < int, int, int >, WHL > (		
			const 				  	  std::tuple < int, int, int >     				&  	,
			const Advert 			< std::tuple < int, int, int > > 				&  	,	
			DomEntry   				< std::tuple < int, int, int > > 				& 	);

		template bool Election < std::pair < int, int >, 		SWO 	> (		
			std::unordered_map < int, 
								 DomEntry < std::pair < int, int > > >  			&   ,
			DomEntry < std::pair < int, int > >    					  				&   );

		template bool Election < std::pair < int, int >, 		WSO 	> (		
			std::unordered_map < int, 
								 DomEntry < std::pair < int, int > > >  			&   ,
			DomEntry < std::pair < int, int > >    					  				&  	);

		template bool Election < std::pair < int, int >, 		POHL 	> (		
			std::unordered_map < int, 
								 DomEntry < std::pair < int, int > > >  			&   ,
			DomEntry < std::pair < int, int > >    					  				&  	);

		template bool Election < std::pair < int, int >, 		POWH 	> (		
			std::unordered_map < int, 
								 DomEntry < std::pair < int, int > > >  			&   ,
			DomEntry < std::pair < int, int > >    					  				&  	);

		template bool Election < std::pair < int, int >, 		POWL 	> (		
				std::unordered_map < int, 
								 DomEntry < std::pair < int, int > > >  			&   ,
			DomEntry < std::pair < int, int > >    					  				&  	);

		template bool Election < std::tuple < int, int, int >,  POWHL 	> (		
			std::unordered_map < int, 
								 DomEntry < std::tuple < int, int, int > > >  		&   ,
			DomEntry < std::tuple < int, int, int > >    					  		&  	);

		template void IntermediateNode 			< std::pair < int, int >, SWO, WL 			> ( 
			const Graph 		< std::pair < int, int > > 							& 	, 
				RoutingState 	< std::pair < int, int > > 							& 	,
				std::mt19937  														& 	, 
			const double 															& 	,
			const int 																& 	,
			const int 																& 	,
			const int 																& 	, 
			const Advert < std::pair < int, int > > 								& 	);

		template void IntermediateNode 			< std::pair < int, int >, WSO, WL 			> ( 
			const Graph 		< std::pair < int, int > > 			& 	, 
				RoutingState 	< std::pair < int, int > > 			& 	,
				std::mt19937  										& 	, 
				const double 										& 	,
			const int 												& 	,
			const int 												& 	,
			const int 												& 	, 
			const Advert < std::pair < int, int > > 				& 	);

		template void IntermediateNode 			< std::pair < int, int >, POHL, HL 			> ( 
			const Graph 		< std::pair < int, int > > 			& 	, 
				RoutingState 	< std::pair < int, int > > 			& 	,
				std::mt19937  										& 	, 
				const double 										& 	,
			const int 												& 	,
			const int 												& 	,
			const int 												& 	, 
			const Advert < std::pair < int, int > > 				& 	);

		template void IntermediateNode 			< std::pair < int, int >, POWH, WH 			> ( 
			const Graph 		< std::pair < int, int > > 			& 	, 
				RoutingState 		< std::pair < int, int > > 			& 	,
				std::mt19937  											& 	, 
				const double 											& 	,
			const int 												& 	,
			const int 												& 	,
			const int 												& 	, 
			const Advert < std::pair < int, int > > 				& 	);

		template void IntermediateNode 			< std::pair < int, int >, POWL, WL 			> ( 
			const Graph 		< std::pair < int, int > > 			& 	, 
				RoutingState 	< std::pair < int, int > > 			& 	,
				std::mt19937  										& 	, 
				const double 										& 	,
			const int 												& 	,
			const int 												& 	,
			const int 												& 	, 
			const Advert < std::pair < int, int > > 				& 	);

		template void IntermediateNode 			< std::tuple < int, int, int >, POWHL, WHL > ( 
			const Graph 		< std::tuple < int, int, int > > 	& 	, 
				RoutingState 	< std::tuple < int, int, int > > 	& 	,
				std::mt19937  										& 	, 
				const double 										& 	,
			const int 												& 	,
			const int 												& 	,
			const int 												& 	, 
			const Advert 		< std::tuple < int, int, int > > 	& 	);

		template void DestinationAnnouncement 	< std::pair < int, int >, SWO, WL 			> (	
			const Graph  		< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::mt19937 			   								&  	,	
		 	const int 				   								&	);

		template void DestinationAnnouncement 	< std::pair < int, int >, WSO, WL 			> (	
			const Graph  		< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::mt19937 			   								&  	,	
		 	const int 				   								&	);

		template void DestinationAnnouncement 	< std::pair < int, int >, POHL, HL 			> (	
			const Graph  		< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::mt19937 			   								&  	,	
		 	const int 				   								&	);

		template void DestinationAnnouncement 	< std::pair < int, int >, POWH, WH 			> (	
			const Graph  		< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::mt19937 			   								&  	,	
		 	const int 				   								&	);

		template void DestinationAnnouncement 	< std::pair < int, int >, POWL, WL 			> (	
			const Graph  		< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::mt19937 			   								&  	,	
		 	const int 				   								&	);

		template void DestinationAnnouncement 	< std::tuple < int, int, int >, POWHL, WHL 	> (	
			const Graph  		< std::tuple < int, int, int > >	& 	, 
		 	RoutingState  		< std::tuple < int, int, int > > 	&  	, 
			std::mt19937 			   								&  	,	
		 	const int 				   								&	);

		template void LinkFailure 				< std::pair < int, int >, SWO, WL 			> (	
			Graph  				< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::vector  		< std::mt19937 > 					&  	,	
			const int 												& 	,
			const int 												& 	);

		template void LinkFailure 				< std::pair < int, int >, WSO, WL 			> (	
			Graph  				< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::vector  		< std::mt19937 > 					&  	,	
			const int 												& 	,
			const int 												& 	);

		template void LinkFailure 				< std::pair < int, int >, POHL, HL 			> (	
			Graph  				< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::vector  		< std::mt19937 > 					&  	,	
			const int 												& 	,
			const int 												& 	);


		template void LinkFailure 				< std::pair < int, int >, POWH, WH 			> (	
			Graph  				< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::vector  		< std::mt19937 > 					&  	,	
			const int 												& 	,
			const int 												& 	);


		template void LinkFailure 				< std::pair < int, int >, POWL, WL 			> (	
			Graph  				< std::pair < int, int > > 			& 	, 
		 	RoutingState  		< std::pair < int, int > > 			&  	, 
			std::vector  		< std::mt19937 > 					&  	,	
			const int 												& 	,
			const int 												& 	);

		template void LinkFailure 				< std::tuple < int, int, int >, POWHL, WHL 	> (	
			Graph  				< std::tuple < int, int, int > > 	& 	, 
		 	RoutingState  		< std::tuple < int, int, int > > 	&  	, 
			std::vector  		< std::mt19937 > 					&  	,	
			const int 												& 	,
			const int 												& 	);
	}
}

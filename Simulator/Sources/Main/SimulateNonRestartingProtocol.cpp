// File 	   : Main/SimulateNonRestartingProtocol.cpp

#include <iomanip> 
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <time.h>

#include "Graphs/Graphs.h"
#include "RoutingAlgebras/Extensions/Extensions.h"
#include "RoutingAlgebras/Orders/Orders.h"
#include "DominantPathsProtocols/NonRestartingProtocol/NonRestartingRoutingState.h"
#include "DominantPathsProtocols/NonRestartingProtocol/NonRestartingProtocolCode.h"
#include "DominantPathsProtocols/NonRestartingProtocol/NonRestartingRoutingSimulator.h"
#include "Utils/AugmentedStd.h"

using namespace Graphs;
using namespace RoutingAlgebras;
using namespace DominantPathsProtocols;

template < typename S, typename Ord, typename Ext >
void RunnerSimulateNonRestartingProtocol( 
	std::string fNetwork 	,	 
	std::string fOrder  	,
	int 	    fTrails 	)
{
	std::string fileNameNetwork 	= "NetworkDataSets/" + fNetwork + ".tsv";

	std::ifstream fileNetwork   	= std::ifstream( fileNameNetwork );
	if( fileNetwork.fail()  	) 
	{	exit(1);				}

	std::cout << "\n> Test Network             = " 	<<  fNetwork   << std::endl;
	std::cout << "> Optimality Criterion     = " 	<<  fOrder     << std::endl;

	int u, v, V; 
	S attrWeight;	

	fileNetwork >> V;
	
	Graph < S > graph( V );
	while( fileNetwork >> u >> v >> attrWeight )
	{	graph.addEdge( u, v, attrWeight ); 	   }

	std::cout << std::endl;
	std::cout << "> Announcements of Destinations" 	<< std::endl;	
	std::cout << std::endl;

	std::string fileNameStableState 				 = "OutputDataSets/" + fNetwork + "/" + fOrder + "/Stable_State.tsv";

	std::ofstream fileStableState   				 = std::ofstream( fileNameStableState );
	if( fileStableState.fail()  					 )
	{	exit(1); 		   							 }

	std::string fileNameTerminationTimesAnnouncement = "OutputDataSets/" + fNetwork + "/" + fOrder + "/Termination_Times_Announcement.tsv";

	std::ofstream fileTerminationTimesAnnouncement   = std::ofstream( fileNameTerminationTimesAnnouncement );
	if( fileTerminationTimesAnnouncement.fail()  	 )
	{	exit(1); 		   						 	 }

	NonRestartingProtocol::RoutingState < S > routingState;

	int simulationsCompleted = 0;
	int simulationsTotal 	 = fTrails * graph.V;

	for( int t = 0 ; t < graph.V ; t ++ )
	{	fileTerminationTimesAnnouncement << "\t" << t;	}
	fileTerminationTimesAnnouncement 	 << "\n";

	for( int i = 0 ; i < fTrails ; i ++ )
	{
		routingState = NonRestartingProtocol::RoutingState < S >( graph.V );
		
		unsigned seed = rand();

		fileTerminationTimesAnnouncement << seed;

		std::vector < std::mt19937 > gens;
		std::mt19937 gen = std::mt19937( seed );		
		gens.clear();			
		for( int t = 0 ; t < graph.V ; t ++ )
		{	gens.push_back( std::mt19937( gen() ) ); }

		for( int t = 0 ; t < graph.V ; t ++ )
		{
			std::cout << "\r\t+ Progress = " << simulationsCompleted << " Out Of " << simulationsTotal << " Simulations Completed.";
			std::cout.flush();

			NonRestartingProtocol::DestinationAnnouncement 					  			  < S, Ord, Ext >(  graph, routingState, gens[t], t );
			double terminationTimesAnnouncement = NonRestartingProtocol::RoutingSimulator < S, Ord, Ext >(  graph, routingState, gens 	    );

			fileTerminationTimesAnnouncement << "\t" << std::setprecision(4) << terminationTimesAnnouncement;

			simulationsCompleted ++;
		}
		fileTerminationTimesAnnouncement   << "\n";
	}

	std::cout << "\r\t+ Progress = "     			  << simulationsCompleted << " Out Of "    << simulationsTotal << " Simulations Completed.";
	std::cout.flush();

	for( int t = 0 ; t < graph.V ; t ++ )
	{	fileStableState  << "\t" << t;	}
	fileStableState 	 << "\n";

	for( int s = 0 ; s < graph.V ; s ++ )
	{
		fileStableState  << s;
		
		for( int t = 0 ; t < graph.V ; t ++ )
		{
			fileStableState << "\t";

			for( auto item  = routingState.dom[s][t].begin() ; 
					  item != routingState.dom[s][t].end()   ; item ++ )
			{	
				fileStableState << " " << item->first;
			}
		}
		fileStableState << "\n";
	}

	std::cout << std::endl;
	std::cout << "\n\t+ Saving Data Set to File '"    << fileNameStableState  			       << "'." << std::endl;
	std::cout << "\n\t+ Saving Data Set to File '"    << fileNameTerminationTimesAnnouncement  << "'." << std::endl;



	std::cout << std::endl;
	std::cout << "> Failure of Links" 	   << std::endl;	
	std::cout << std::endl;

	std::string fileNameTerminationTimesFailure = "OutputDataSets/" + fNetwork + "/" + fOrder + "/Termination_Times_Failure.tsv";

	std::ofstream fileTerminationTimesFailure   = std::ofstream( fileNameTerminationTimesFailure );
	if( fileTerminationTimesFailure.fail()  )
	{	exit(1); 		   					}

	for( u = 0 ; u < graph.V ; u ++ )
	{	for( auto it  = graph.adjListOut[u].begin() ;
				  it != graph.adjListOut[u].end()	; it ++ )
		{	v = it->first;
			fileTerminationTimesFailure << "\t" << std::make_pair(u, v) ;	
		}
	}
	fileTerminationTimesFailure << "\n";

	simulationsCompleted = 0;
	simulationsTotal 	 = fTrails * graph.E ;

	for( int i = 0 ; i < fTrails ; i ++ )
	{
		unsigned seed = rand();

		fileTerminationTimesFailure << seed;

		for( u = 0 ; u < graph.V ; u ++ )
		{	for( auto it  = graph.adjListOut[u].begin() ;
				  	  it != graph.adjListOut[u].end()	; it ++ )
			{
			 	v = it->first;

				std::mt19937 gen = std::mt19937( seed );	

				std::vector < std::mt19937 > gens;
				gens.clear();				
				for( int t = 0 ; t < graph.V ; t ++ )
				{	gens.push_back( std::mt19937( gen() ) ); }

				std::cout << "\r\t+ Progress = " << simulationsCompleted << " Out Of " << simulationsTotal << " Simulations Completed.";
				std::cout.flush();

				NonRestartingProtocol::RoutingState < S > newRoutingState = routingState;

				NonRestartingProtocol::LinkFailure 						   		 		  < S, Ord, Ext >(  graph, newRoutingState, gens, u, v ); 
				double failureTerminationTimes = NonRestartingProtocol::RoutingSimulator  < S, Ord, Ext >(  graph, newRoutingState, gens 	   );

				fileTerminationTimesFailure << "\t" << std::setprecision(4) << failureTerminationTimes;
		
				simulationsCompleted ++;

				graph.activate( u, v );
			}
		}
		fileTerminationTimesFailure << "\n";
	} 

	std::cout << "\r\t+ Progress = "   			    << simulationsCompleted << " Out Of " << simulationsTotal << " Simulations Completed.";
	std::cout.flush();

	std::cout << std::endl;
	std::cout << "\n\t+ Saving Data Set to File '"  << fileNameTerminationTimesFailure    << "'." << std::endl;
	std::cout << std::endl;

	return;
}

int main( int argc, char *argv[] )
{
	std::cout << "\n--- Simulation of the Non-Restarting Protocol" << std::endl;

	int opt;

	std::string fNetwork, fOrder;
	int fTrails = 0;

	while( ( opt = getopt( argc, argv, "n:o:r:" ) ) != -1 ) 
	{
		switch( opt )
		{	case 'n':
				fNetwork    = std::string( optarg );
				break;
			case 'o':
				fOrder 		= std::string( optarg );
				break;		
			case 'r':
				fTrails 	= atoi( optarg );
				break;
			default	:
				break;
		}
	}
	
	if( 	 fOrder.compare( "ShortestWidestOrder"  			)  == 0 )
	{	RunnerSimulateNonRestartingProtocol < std::pair < int, int >, SWO,  WL > ( fNetwork, fOrder, fTrails );	
	}
	else if( fOrder.compare( "WidestShortestOrder"  			)  == 0 )
	{	RunnerSimulateNonRestartingProtocol < std::pair < int, int >, WSO,  WL > ( fNetwork, fOrder, fTrails );	
	}
	else if( fOrder.compare( "ProductOrderHopsLengths" 			) == 0 )
	{	RunnerSimulateNonRestartingProtocol < std::pair < int, int >, POHL, HL > ( fNetwork, fOrder, fTrails );	
	}
	else if( fOrder.compare( "ProductOrderWidthHops" 			) == 0 )
	{	RunnerSimulateNonRestartingProtocol < std::pair < int, int >, POWH, WH > ( fNetwork, fOrder, fTrails );	
	}
	else if( fOrder.compare( "ProductOrderWidthLengths" 		) == 0 )
	{	RunnerSimulateNonRestartingProtocol < std::pair < int, int >, POWL, WL > ( fNetwork, fOrder, fTrails );	
	}	
	else if( fOrder.compare( "ProductOrderWidthHopsLengths" 	) == 0 )
	{	RunnerSimulateNonRestartingProtocol < std::tuple < int, int, int >, POWHL, WHL > ( fNetwork, fOrder, fTrails );	
	}
}

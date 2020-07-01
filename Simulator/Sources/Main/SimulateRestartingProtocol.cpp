// File 	   : Main/SimulateRestartingProtocol.cpp

#include <iomanip> 
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <time.h>

#include "Graphs/Graphs.h"
#include "RoutingAlgebras/Extensions/Extensions.h"
#include "RoutingAlgebras/Orders/Orders.h"
#include "DominantPathsProtocols/RestartingProtocol/RestartingRoutingState.h"
#include "DominantPathsProtocols/RestartingProtocol/RestartingProtocolCode.h"
#include "DominantPathsProtocols/RestartingProtocol/RestartingRoutingSimulator.h"
#include "Utils/AugmentedStd.h"

using namespace Graphs;
using namespace RoutingAlgebras;
using namespace DominantPathsProtocols;

template < typename S, typename Ord, typename Ext >
void RunnerSimulateRestartingProtocol( 
	std::string fNetwork 	,	 
	std::string fOrder  	,
	int 	    fTrails 	)
{
	std::string fileNameNetwork 	= "NetworkDataSets/" + fNetwork + ".tsv";

	std::ifstream fileNetwork   	= std::ifstream( fileNameNetwork );
	if( fileNetwork.fail()  	) 
	{	exit(1);				}

	std::cout << "\n> Test Network             = " 	<<  fNetwork   << std::endl;
	std::cout << "> Optimality Criterion     = " 	<<  fOrder << std::endl;

	int u, v, V; 
	S attrWeight;	

	fileNetwork >> V;
	
	Graph < S > graph( V );
	while( fileNetwork >> u >> v >> attrWeight )
	{	graph.addEdge( u, v, attrWeight ); 	   }

	RestartingProtocol::RoutingState < S > routingState;

	std::vector  < std::mt19937 > gens;
	for( int t = 0 ; t < graph.V ; t ++ )
	{	gens.push_back( std::mt19937( 0 ) ); }

	routingState = RestartingProtocol::RoutingState < S >( graph.V );

	for( int t = 0 ; t < graph.V ; t ++ )
	{
		RestartingProtocol::DestinationAnnouncement < S, Ord, Ext >(  graph, routingState, gens[t], t );
	}
	RestartingProtocol::RoutingSimulator 		    < S, Ord, Ext >(  graph, routingState, gens, 0 	  );



	std::cout << std::endl;
	std::cout << "> Failure of Links" 	   << std::endl;	
	std::cout << std::endl;

	std::string fileNameTimePropagateUnreachability = "OutputDataSets/" + fNetwork + "/" + fOrder + "/Times_Propagate_Unreachability.tsv";

	std::ofstream fileTimePropagateUnreachability   = std::ofstream( fileNameTimePropagateUnreachability );
	if( fileTimePropagateUnreachability.fail()  )
	{	exit(1); 		   					}

	for( u = 0 ; u < graph.V ; u ++ )
	{	for( auto it  = graph.adjListOut[u].begin() ;
				  it != graph.adjListOut[u].end()	; it ++ )
		{	v = it->first;
			fileTimePropagateUnreachability << "\t" << std::make_pair(u, v) ;	
		}
	}
	fileTimePropagateUnreachability << "\n";

	int simulationsCompleted = 0;
	int simulationsTotal 	 = fTrails * graph.E;

	for( int i = 0 ; i < fTrails ; i ++ )
	{
		unsigned seed = rand();

		fileTimePropagateUnreachability << seed;
		
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

				RestartingProtocol::RoutingState < S > newRoutingState = routingState;

				RestartingProtocol::LinkFailure 						   		 	      < S, Ord, Ext >(  graph, newRoutingState, gens, u, v ); 
				double timePropagateUnreachability = RestartingProtocol::RoutingSimulator < S, Ord, Ext >(  graph, newRoutingState, gens, 1    );

				fileTimePropagateUnreachability   << "\t" << std::setprecision(4) << timePropagateUnreachability;
		
				simulationsCompleted ++;

				graph.activate( u, v );
			}
		}
		fileTimePropagateUnreachability << "\n";
	} 

	std::cout << "\r\t+ Progress = "     		    << simulationsCompleted << " Out Of " << simulationsTotal << " Simulations Completed.";
	std::cout.flush();

	std::cout << std::endl;
	std::cout << "\n\t+ Saving Data Set to File '"  << fileNameTimePropagateUnreachability    << "'." << std::endl;
	std::cout << std::endl;

	return;
}

int main( int argc, char *argv[] )
{
	std::cout << "\n--- Simulation of the Restarting Protocol" << std::endl;

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
	
	if( 	 fOrder.compare( "ProductOrderHopsLengths"  	) == 0 )
	{	RunnerSimulateRestartingProtocol < std::pair < int, int >, POHL, HL > ( fNetwork, fOrder, fTrails );	
	}
	else if( fOrder.compare( "ProductOrderWidthHops"  		) == 0 )
	{	RunnerSimulateRestartingProtocol < std::pair < int, int >, POWH, WH > ( fNetwork, fOrder, fTrails );	
	}
	else if( fOrder.compare( "ProductOrderWidthLengths"  	) == 0 )
	{	RunnerSimulateRestartingProtocol < std::pair < int, int >, POWL, WL > ( fNetwork, fOrder, fTrails );	
	}	
	else if( fOrder.compare( "ProductOrderWidthHopsLengths" ) == 0 )
	{	RunnerSimulateRestartingProtocol < std::tuple < int, int, int >, POWHL, WHL > ( fNetwork, fOrder, fTrails );	
	}

	std::cout << "---" << std::endl;

}
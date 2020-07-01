// File : Graphs/Graphs.h

// Description : 

#ifndef _GRAPHS_H_
#define _GRAPHS_H_

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

namespace Graphs
{
	template < class S >
	struct Graph
	{
		int V;
		int E;
		std::vector < std::unordered_map < int, std::pair < bool, S > > > adjListIn;
		std::vector < std::unordered_map < int, std::pair < bool, S > > > adjListOut;
		
		Graph(){};
		Graph(int V);

		void addEdge( 	 int, int,   S );
		void removeEdge( int, int );
		void activate(   int, int );
		void deactivate( int, int );
		void clear( );

		friend std::ostream & operator<< (std::ostream& os, 
										  const Graph & graph )
		{
			os << "   < ";
			for( int u = 0 ; u < graph.V ; u ++ )
			{	for( auto v  = graph.adjListIn[u].begin() ; 
						  v != graph.adjListIn[u].end()   ; v ++ )
				{	if( u != 0 or v != graph.adjListIn[u].begin() )
					{	os << "\n     "; 	   	}
					os << "< edge = (" 		<< v->first << ", " 	<< u << ")" << "," ;
					os <<  " active = "  	<< v->second.first     	 	 		<< "," ; 
					os <<  " attribute = "  << v->second.second     	 		<< " >"; 
				}
			}
			os << " > ";
			return os;
		};

	};
}

#endif
// File : Graphs.cpp

#include "Graphs/Graphs.h"

namespace Graphs
{
	template < class S > 
	Graph < S >::Graph( int V )
	{
		this->V = V;
		this->E = 0;
		adjListIn.resize(V);
		adjListOut.resize(V);
	}

	template < class S > 
	void Graph < S >::addEdge( int u, int v, S w )
	{
		if(0 > u or u >= V){ throw std::out_of_range("In-Node  does not exist.");}
		if(0 > u or v >= V){ throw std::out_of_range("Out-Node does not exist.");}
		E++;
		adjListIn[v][u]  = { true, w } ;
		adjListOut[u][v] = { true, w } ;
	}

	template < class S > 
	void Graph < S >::removeEdge( int u, int v )
	{
		if(u < 0 or u >= V){ throw std::out_of_range( "In-Node does not exist.");}
		if(v < 0 or v >= V){ throw std::out_of_range("Out-Node does not exist.");}
		E--;
		adjListIn[v].erase(u);
		adjListOut[u].erase(v);
	}

	template < class S >
	void Graph < S >::activate( int u , int v )
	{
		if( 0 > u or u >= V )
		{	throw std::out_of_range("Out-Node  does not exist.");
		}
		if( 0 > v or v >= V )
		{	throw std::out_of_range("In-Node  does not exist.");
		}
		adjListOut[u][v].first = true;
		adjListIn[v][u].first  = true;	
	}

	template < class S >
	void Graph < S >::deactivate( int u , int v ) 
	{
		if( 0 > u or u > V )
		{	throw std::out_of_range("Out-Node does not exist.");
		}
		if( 0 > v or v > V )
		{	throw std::out_of_range("In-Node  does not exist.");
		}
		adjListOut[u].at(v).first = false;
		adjListIn[v].at(u).first  = false;
	}

	template < class S >
	void Graph < S > :: clear()
	{
		V = 0;
		E = 0;
		adjListIn.clear();
		adjListOut.clear();
	}
}

#include "Graphs/GraphsInstances.h"


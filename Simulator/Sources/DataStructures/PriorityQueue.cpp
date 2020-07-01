// file = DataStructures/PriorityQueue.cpp

// My Library 
#include "DataStructures/PriorityQueue.h"

namespace DataStructures
{
	template < class T1 , 
			   class T2 ,
		   	   typename Compare >
	void PriorityQueue < T1, T2, Compare >::exchange( int p, int c )
	{
		std::pair < T1, T2 > t;
		t 	 = H[p];
		H[p] = H[c];
		H[c] = t;

		I[H[p].first] = p;
		I[H[c].first] = c;
	};

	template < class T1 ,
			   class T2 , 
		   	   typename Compare >
	void PriorityQueue < T1, T2, Compare>::heapifyUp( int c )
	{
		int p = (c-1) / 2;
		if( compare(H[c].second, H[p].second) )
		{	exchange(p, c);
			if( p > 0 )
				heapifyUp(p);
		} 		
	};
	
	template < class T1 ,
			   class T2 , 
		  	   typename Compare >
	void PriorityQueue < T1, T2, Compare>::heapifyDown( int p )
	{
		int c = 2*p+1;
		if( c < this->s )									 
		{	
			if( c + 1 < this->s and 
				compare(H[c+1].second, H[c].second) )
			{	c++; }
			if( compare(H[c].second,   H[p].second) )
			{	exchange(p, c);
				heapifyDown(c);
			}
		}
	};

	template < class T1 ,
			   class T2 ,
			   typename Compare >
	PriorityQueue < T1, T2, Compare>::PriorityQueue( int c )
	{
		this->c = c;
		this->s = 0;
		I = std::unordered_map < T1, int, boost::hash < T1 > >();
		H = std::vector < std::pair < T1, T2 > >();
		if( c >= 0)
		{	H.resize(c); }
	};

	template < class T1 ,
			   class T2 ,
			   typename Compare >
	PriorityQueue < T1, T2, Compare>::PriorityQueue( const PriorityQueue < T1, T2, Compare > & other )
	{
		compare = other.compare;
		c       = other.c;
		s 	    = other.s;
		I  		= other.I;
		H    	= other.H;
	};

	template < class T1 ,
			   class T2 ,
			   typename Compare >
	PriorityQueue < T1, T2, Compare > & PriorityQueue < T1, T2, Compare>::operator= ( PriorityQueue < T1, T2, Compare > other )
	{
		swap(  * this, other );	
		return * this;
	};	

	template < class T1 ,
			   class T2 ,
			   typename Compare >
	int PriorityQueue < T1, T2, Compare>::size( )	const
	{
		return this->s;
	};

	template < class T1 ,
			   class T2 ,
			   typename Compare >
	bool PriorityQueue < T1, T2, Compare>::empty()	const
	{
		if( this->s > 0){ return false; }
		else{		   	  return true;  }
	};

	template < class T1 ,
			   class T2 ,
			   typename Compare >
	bool PriorityQueue < T1, T2, Compare>::full()	const
	{
		if( this->s >= this->c) { return true; 	 }
		else{		   	  		  return false;  }
	};

	template < class T1 ,
			   class T2 , 
			   typename Compare >
	bool PriorityQueue < T1, T2, Compare >::push( T1 val, T2 key )
	{
		int i;

		typename std::unordered_map < T1, int, boost::hash < T1 > >::const_iterator got = I.find( val );

		if( got == I.end()   )
		{	if( this->full() )
			{ 	return false;				}
			else
			{	I[val] = this->s;
				H[this->s ++] = {val, key};	}
		}
		else
		{	i 		= got->second;
			H[i] = {val, key};
		}

		heapifyUp(   I[val] );
		heapifyDown( I[val] );
		return true;
	};

	template < class T1 ,
			   class T2 ,
			   typename Compare >
	std::pair < T1, T2 > PriorityQueue < T1, T2, Compare>::top() const
	{
		return H[0];
	};

	template < class T1 ,
			   class T2 ,
			   typename Compare >
	bool PriorityQueue < T1, T2, Compare>::pop()
	{
		T1 val;
		if( this->s > 0 )
		{ 	val = top().first;
			exchange(0, -- this->s);
			heapifyDown(0);
			I.erase(val);
			return true;
		}
		else
			return false;
	};

	template <  class T1 ,
		  		class T2 , 
		   		typename Compare >
	void PriorityQueue < T1, T2, Compare >::clear()
	{
		this->s     = 0;
		I.clear();
		H.clear();		
	}

	template class PriorityQueue < std::pair < int, int >, double >;

}

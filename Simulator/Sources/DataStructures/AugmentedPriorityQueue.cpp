// File : DataStructures/AugmentedPriorityQueue.h

#include <stdexcept>

// My Library 
#include "DataStructures/AugmentedPriorityQueue.h"
#include "Utils/AugmentedStd.h"

namespace DataStructures
{
	template < class T1, 
			   class T2, 
			   class T3, 
			   typename Compare >
	AugmentedPriorityQueue < T1, T2, T3, Compare > :: AugmentedPriorityQueue ( int c )
	{
		this->c = c;
		this->s = 0;
		P = PriorityQueue    < T1, T2, Compare >( c );
		Q = std::unordered_map < 
				T1, 
				std::queue < std::pair < T2, T3 > >, 
				boost::hash < T1 > >();
	}

	template < class T1, 
			   class T2, 
			   class T3, 
			   typename Compare >
	AugmentedPriorityQueue < T1, T2, T3, Compare > :: AugmentedPriorityQueue( const AugmentedPriorityQueue & other )
	{
		c = other.c;
		s = other.s;
		P = other.P;
		Q = other.Q;
	};

	template < class T1,
			   class T2,
			   class T3, 			   
			   typename Compare >
	AugmentedPriorityQueue < T1, T2, T3, Compare > & AugmentedPriorityQueue < T1, T2, T3, Compare>::operator= ( AugmentedPriorityQueue < T1, T2, T3, Compare > other )
	{
		swap(  * this, other );
		return * this;
	};	

	template < class T1,
			   class T2,
			   class T3,
			   typename Compare >
	int AugmentedPriorityQueue < T1, T2, T3, Compare > :: size()   	const
	{
		return this->s;
	};

	template < class T1,
			   class T2,
			   class T3,
			   typename Compare >
	bool AugmentedPriorityQueue < T1, T2, T3, Compare > :: empty()	const
	{
		if( this->s > 0){ return false; }
		else{		      return true;  }	
	};

	template < class T1,
			   class T2,
			   class T3,
			   typename Compare >
	bool AugmentedPriorityQueue < T1, T2, T3, Compare > :: full()	const
	{
		return P.full();
	};

	template < class T1, 
			   class T2, 
			   class T3, 
			   typename Compare >
	int AugmentedPriorityQueue < T1, T2, T3, Compare >::count( const T1 & u ) const
	{
		if( Q.count(u) == 0	)
		{	return 0; 		}
		else
		{	return 1;		}
	}

	template < class T1, 
			   class T2, 
			   class T3, 
			   typename Compare >
	std::pair < T2, T3 > AugmentedPriorityQueue < T1, T2, T3, Compare >::at( const T1 & u ) const
	{
		if( this->count(u) == 1 )
		{	return Q.at(u).back(); 		  					   }
		else
		{	throw std::out_of_range ("Value does not exist."); }
	}

	template < class T1, 
			   class T2, 
			   class T3, 
			   typename Compare >
	bool AugmentedPriorityQueue < T1, T2, T3, Compare >::push ( const std::pair < T1, 
															 		  std::pair < T2, T3 > > & u )
	{
		if( this->count(u.first) == 0 )
		{	if(	P.full() )
			{	return false;							}
			this->s ++;
			P.push(u.first, 
				   u.second.first); 				
			Q[u.first] = std::queue   < 
						 	std::pair < T2, T3 > >(); 	}
		Q[u.first].push(u.second);	
		return true;
	}

	template < class T1, 
			   class T2, 
			   class T3, 
			   typename Compare >	
	std::pair   < T1, 
		std::pair < T2, T3 > > AugmentedPriorityQueue < T1, T2, T3, Compare >::top() const
	{
		T1 u = P.top().first;
		return {u, Q.at(u).front()};	
	}
 
	template < class T1, 
			   class T2, 
			   class T3, 
			   typename Compare >	
	bool AugmentedPriorityQueue < T1, T2, T3, Compare >::pop  (	)
	{
		T1 u;

		if( this-> s > 0 )
		{	u = P.top().first;
			Q.at(u).pop();
			if( Q.at(u).empty() )
			{	P.pop();
				Q.erase(u);
				this->s --;						 }
			else
			{	P.push( u, 
						Q.at(u).front().first ); }
			return true;						 }
		else
		{	return false;						 }
	}
	
	template <  class T1 ,
		  		class T2 , 
  			    class T3, 
		   		typename Compare >
	void AugmentedPriorityQueue < T1, T2, T3, Compare >::clear()
	{
		this->s = 0;
		P.clear();
   		Q.clear();		
	}
}

#include "DataStructures/AugmentedPriorityQueueInstances.h"

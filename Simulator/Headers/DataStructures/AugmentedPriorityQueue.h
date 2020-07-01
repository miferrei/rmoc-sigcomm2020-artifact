// file : Algorithms/DRVP/AugmentedPriorityQueue.h

#ifndef _DATASTRUCTURESAUGMENTEDPRIORITYQUEUE_H_
#define _DATASTRUCTURESAUGMENTEDPRIORITYQUEUE_H_

// Public Library
#include <boost/functional/hash.hpp>
#include <queue>
#include <unordered_map>
#include <utility>

// Project Library 
#include "DataStructures/PriorityQueue.h"

namespace DataStructures
{
	template < class T1, 
			   class T2, 
			   class T3, 
			   typename Compare = std::less < T2 > >
	class AugmentedPriorityQueue
	{
		int c;
		int s;

		PriorityQueue 	   < T1, T2, Compare > 	  P;
		std::unordered_map < 
			T1, 
			std::queue     < std::pair < T2, T3 > >,
			boost::hash    < T1 > > 			  Q;

		public:

			AugmentedPriorityQueue(){};
			AugmentedPriorityQueue( int );
			AugmentedPriorityQueue( const AugmentedPriorityQueue & );

			AugmentedPriorityQueue & operator =( AugmentedPriorityQueue );

			friend void swap( AugmentedPriorityQueue & l, 	
							  AugmentedPriorityQueue & r )
			{
				std::swap( l.c, r.c );
				std::swap( l.s, r.s );
				std::swap( l.P, r.P );
				std::swap( l.Q, r.Q );
			};

			int  size()  const;
		    bool empty() const;
		    bool full()  const;

			int  count( 			 const T1 & ) const;
			std::pair < T2, T3 > at( const T1 & ) const;

			bool push(   const std::pair < T1, 
					   		   std::pair < T2, T3 > > & );
		 	std::pair   < T1, 
		    	std::pair < T2, T3 > > top()	  const;
			bool pop();						
		    void clear();

	};

}

#endif

// File : DataStructures/PriorityQueue.h

// Description: An implementation of a priority queue as a heap. 

#ifndef _DATASTRUCTURESPRIORITYQUEUE_H_
#define _DATASTRUCTURESPRIORITYQUEUE_H_

// Public Libraries 
#include <algorithm>
#include <boost/functional/hash.hpp>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

namespace DataStructures
{
	template < class Value  ,
			   class Key 	,
			   typename Compare = std::less < Key > >
	class PriorityQueue
	{
		Compare compare;

		int c;
		int s;

		std::vector < std::pair < Value, Key > > H; 
		std::unordered_map < Value, 
							 int, 
							 boost::hash < Value > > I;

		void exchange(		int, int );
		void heapifyUp(   	int 	 );
		void heapifyDown( 	int 	 );

		public:

			PriorityQueue( 		){};
			PriorityQueue( int  );
			PriorityQueue( const PriorityQueue & );			

			friend void swap( PriorityQueue & l , 
							  PriorityQueue & r )
			{
				std::swap( l.compare, r.compare );
				std::swap( l.c, 	  r.c );
				std::swap( l.s, 	  r.s );
				std::swap( l.I, 	  r.I );
				std::swap( l.H, 	  r.H );	
			};

			PriorityQueue & operator = ( PriorityQueue );

			int  size()  const;
			bool full()  const;			
			bool empty() const;

			bool push( Value, Key );
			std::pair < Value, Key > top() const;
			bool pop();
			void clear();

			friend std::ostream & operator<< (std::ostream		  & os, 
											  const PriorityQueue & u)
			{	
				os << "   < ";
				for( std::size_t i = 0 ; i < u.s ; ++ i )
				{	if( i != 0)
					{	os << "\n     "   ; 	 }
					os << "< val = "             ;
					os << u.H[i].first  << ",";
					os <<  " key = "             ;
					os << u.H[i].second;
				}
				os << " >";
			    return os; 
			};
	};
}

#endif
// file : RoutingAlgebras/Orders/ProductOrderHopsLengths.h

#ifndef _PRODUCTORDERHOPSLENGTHS_H_
#define _PRODUCTORDERHOPSLENGTHS_H_

#include <utility>
#include <climits>

namespace RoutingAlgebras
{
	typedef struct ProductOrderHopsLengths
	{
		static inline std::pair < int, int > const Neutral = { 0, 0 };
		
		bool operator() ( 
			const std::pair < int, int > & l, 
			const std::pair < int, int > & r ) 
		{
			if( l.first  <= r.first  and
				l.second <= r.second and
				l != r 					)
			{	return true;	}
			else
			{	return false;	}
		}
	} POHL;
}

#endif


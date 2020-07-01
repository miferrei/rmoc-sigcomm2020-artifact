// file : RoutingAlgebras/Orders/ProductOrderWidthHops.h

#ifndef _PRODUCTORDERWIDTHHOPS_H_
#define _PRODUCTORDERWIDTHHOPS_H_

#include <utility>
#include <climits>

namespace RoutingAlgebras
{
	typedef struct ProductOrderWidthHops
	{
		static inline std::pair < int, int > const Neutral = { INT_MAX, 0 };
		
		bool operator() ( 
			const std::pair < int, int > & l, 
			const std::pair < int, int > & r ) 
		{
			if( l.first  >= r.first  and
				l.second <= r.second and
				l != r 					)
			{	return true;	}
			else
			{	return false;	}
		}
	} POWH;
}

#endif
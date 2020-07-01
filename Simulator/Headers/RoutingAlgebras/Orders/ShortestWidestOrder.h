// file : RoutingAlgebras/Orders/ShortestWidestOrder.h

#ifndef _SHORTESTWIDESTORDER_H_
#define _SHORTESTWIDESTORDER_H_

#include <utility>
#include <climits>

namespace RoutingAlgebras
{
	typedef struct ShortestWidestOrder
	{
		static inline std::pair < int, int > const Neutral = { INT_MAX, 0 };
		
		bool operator() ( 
			const std::pair < int, int > & l, 
			const std::pair < int, int > & r ) 
		{
			if( ( l.first > r.first ) or ( l.first == r.first and l.second < r.second ) )
			{	return true;	}
			else
			{	return false;	}
		}
	} SWO;
}

#endif
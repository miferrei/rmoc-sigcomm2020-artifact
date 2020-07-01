// file : RoutingAlgebras/Orders/WidestShortestOrder.h

#ifndef _WIDESTSHORTESTORDER_H_
#define _WIDESTSHORTESTORDER_H_

#include <utility>
#include <climits>

namespace RoutingAlgebras
{
	typedef struct WidestShortestOrder
	{
		static inline std::pair < int, int > const Neutral = { INT_MAX, 0 };
		
		bool operator() ( 
			const std::pair < int, int > & l, 
			const std::pair < int, int > & r ) 
		{
			if( ( l.second < r.second ) or ( l.second == r.second and l.first > r.first ) )
			{	return true;	}
			else
			{	return false;	}
		}
	} WSO;
}

#endif
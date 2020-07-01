// file : RoutingAlgebras/Orders/ProductOrderWidthHopsLengths.h

#ifndef _PRODUCTORDERWIDTHHOPSLENGTHS_H_
#define _PRODUCTORDERWIDTHHOPSLENGTHS_H_

#include <utility>
#include <climits>

namespace RoutingAlgebras
{
	typedef struct ProductOrderWidthHopsLengths
	{
		static inline std::tuple < int, int, int > const Neutral = { INT_MAX, 0, 0 };
		
		bool operator() (
				const std::tuple < int, int, int > & l, 
				const std::tuple < int, int, int > & r )
		{			
			if( std::get < 0 >( l ) >= std::get < 0 >( r ) and 
				std::get < 1 >( l ) <= std::get < 1 >( r ) and
				std::get < 2 >( l ) <= std::get < 2 >( r ) and
				l != r 										 	)
			{	return true;	}
			else
			{	return false;	}
		}

	} POWHL;
}

#endif
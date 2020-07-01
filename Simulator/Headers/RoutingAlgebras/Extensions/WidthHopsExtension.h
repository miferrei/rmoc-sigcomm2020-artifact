 // file : RoutingAlgebras/Extensions/WidthHopsExtension.h

#ifndef _WIDTHHOPSEXTENSION_H_
#define _WIDTHHOPSEXTENSION_H_

// Public Library
#include <climits>
#include <utility>

namespace RoutingAlgebras
{
	typedef struct WidthHopsExtension
	{
		static inline std::pair < int, int > const Null = { 0, 15 };
	
		std::pair < int, int > operator() ( 
			const std::pair < int, int > & l, 
			const std::pair < int, int > & r )
		{
			std::pair < int, int > o = 
				{ 	std::min( l.first, r.first)	, 
					l.second + r.second 		};

			if( o.first  == 0  		or 
				o.second == 15 )
			{	return { 0, 15 }; 	}
			else
			{	return o; 			}	
		}
	} WH;
}

#endif
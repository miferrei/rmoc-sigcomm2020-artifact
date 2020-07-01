// file : RoutingAlgebras/Extensions/WidthLengthsExtension.h

#ifndef _WIDTHLENGTHSEXTENSION_H_
#define _WIDTHLENGTHSEXTENSION_H_

// Public Library
#include <climits>
#include <utility>

namespace RoutingAlgebras
{
	typedef struct WidthLengthsExtension
	{
		static inline std::pair < int, int > const Null = { 0, INT_MAX };
	
		std::pair < int, int > operator() ( 
			const std::pair < int, int > & l, 
			const std::pair < int, int > & r )
		{
			std::pair < int, int > o = 
				{ 	std::min( l.first,   r.first) 	, 
					          l.second + r.second  	};

			if( o.first  == 0  		or 
				o.second == INT_MAX )
			{	return { 0, INT_MAX }; 	}
			else
			{	return o; 				}	
		}
	} WL;
}

#endif
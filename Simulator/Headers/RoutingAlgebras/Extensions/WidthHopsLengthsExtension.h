// File 	   : RoutingAlgebras/Extensions/WidthHopsLengthsExtension.h

// Description : 

#ifndef _WIDTHHOPSLENGTHSEXTENSION_H_
#define _WIDTHHOPSLENGTHSEXTENSION_H_

// Public Library
#include <climits>
#include <tuple>

namespace RoutingAlgebras
{
	typedef struct WidthHopsLengthsExtension
	{
		static inline std::tuple < int, int, int > const Null = { 0, 15, INT_MAX };
		
		std::tuple < int, int, int > operator() (
				const std::tuple < int, int, int > & l, 
				const std::tuple < int, int, int > & r )
		{

			std::tuple < int, int, int > o = 
			{ 	std::min( std::get < 0 >( l ),  std::get < 0 >( r ) ) 	,
						  std::get < 1 >( l ) + std::get < 1 >( r )		,		
						  std::get < 2 >( l ) + std::get < 2 >( r ) 	};

			if( std::get < 0 >( o ) == 0 			or 
				std::get < 1 >( o ) == 15 			or 
				std::get < 2 >( o ) == INT_MAX 	 	) 
			{	return { 0, 15, INT_MAX };	}
			else
			{	return o; 						}
		}
	} WHL;
}

#endif
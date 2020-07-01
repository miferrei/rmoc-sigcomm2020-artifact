// File 		: RoutingAlgebras/Extensions/HopsLengthsExtension.h

// Description  : 

#ifndef _HOPSLENGTHSEXTENSION_H_
#define _HOPSLENGTHSEXTENSION_H_

#include <climits>
#include <utility>

namespace RoutingAlgebras
{
	typedef struct HopsLengthsExtension
	{
		static inline std::pair < int, int > const Null = { 15, INT_MAX };
	
		std::pair < int, int > operator() ( 
			const std::pair < int, int > & l, 
			const std::pair < int, int > & r )
		{
			std::pair < int, int > o = 
				{ 	l.first  + r.first	 , 
					l.second + r.second  };

			if( o.first  == 15  		or 
				o.second == INT_MAX )
			{	return { 15, INT_MAX };  }
			else
			{	return o; 				 }	
		}
	} HL;
}

#endif
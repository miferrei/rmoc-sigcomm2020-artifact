// File : DominantPathsProtocols/RestartingProtocol/RestartingRoutingState.h

#ifndef _RESTARTINGROUTINGSTATE_H_
#define _RESTARTINGROUTINGSTATE_H_

#include <boost/functional/hash.hpp>
#include <unordered_map>
#include <unordered_set>
#include <utility>

#include "DataStructures/AugmentedPriorityQueue.h"

using namespace DataStructures;

namespace DominantPathsProtocols
{	
	namespace RestartingProtocol
	{
		template < class S >
		using Advertisement = std::unordered_set < std::pair < S, int >,
								     boost::hash < std::pair < S, int > > >;

		template < class S >
		using DomTabEntry 	= std::unordered_map < std::pair < S,   int >,
												   std::pair < int, int >, 
								   	 boost::hash < std::pair < S,   int > > >;

		template < class S >
		struct Route
		{
			int t;
			Advertisement < S > adv;
		
		   	Route(){};
		   	Route( int,  Advertisement < S > );
		   	Route( const Route & 	  );

			friend void swap( Route & l, 
							  Route & r )
			{
				std::swap( l.t,   r.t );
				std::swap( l.adv, r.adv );
			}

			Route & operator= ( Route );		
		};

		template < class S >
		struct RoutingState 
		{	
			std::unordered_map < int, 
							 std::unordered_map < int, 
							 					  DomTabEntry  < S > > > dom;

			std::unordered_map < int, 
						 	std::unordered_map < int, 
						 					     int  > > 			  	 label;

			AugmentedPriorityQueue 	< 
		   		std::pair < int, int >, 
		   		double, 
		   		Route < S > > routeQueue;

		   	RoutingState(){};
		   	RoutingState( int );
		   	RoutingState( const RoutingState & );

			friend void swap( RoutingState & l, RoutingState & r )
			{	
				std::swap( l.dom, 	 	 r.dom 			);
				std::swap( l.label, 	 r.label		);			
				std::swap( l.routeQueue, r.routeQueue 	);			
			}

			RoutingState & operator = ( RoutingState );
		};
	}
}

#endif
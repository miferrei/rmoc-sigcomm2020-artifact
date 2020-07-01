// file : DominantPathsProtocols/NonRestartingProtocol/NonRestartingRoutingState.cpp

// Project Library
#include "DominantPathsProtocols/NonRestartingProtocol/NonRestartingRoutingState.h"

namespace DominantPathsProtocols
{	
	namespace NonRestartingProtocol
	{

		template < class S >
		Route < S > :: Route(	int t,
								Advert < S > adv )
		{	
			this->t = t;
			this->adv = adv;
		};

		template < class S >
		Route < S > :: Route(	const Route < S > & other )
		{
			t = other.t;
			adv = other.adv;
		};

		template < class S >
		Route < S > & Route < S >::operator= ( Route < S > other )
		{
			swap(  * this, other );
			return * this;
		};

		template < class S >
		RoutingState < S > :: RoutingState( int V )
		{	
			routeQueue = AugmentedPriorityQueue < 
										std::pair < int, int >, 
										double, 
										Route < S > > ( V * V );
		};

		template < class S >
		RoutingState <  S > :: RoutingState( const RoutingState < S > & other )
		{
			domTab 		= other.domTab;
			dom 	  	= other.dom;
			routeQueue  = other.routeQueue;
		}

		template < class S >
		RoutingState <  S > & RoutingState < S >::operator=( RoutingState < S > other )
		{
			swap(  * this, other );
			return * this;
		};
	}
}

#include "DominantPathsProtocols/NonRestartingProtocol/NonRestartingRoutingStateInstances.h"

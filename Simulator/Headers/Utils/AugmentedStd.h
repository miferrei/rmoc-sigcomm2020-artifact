// File 	   : UtilsAugmentedStd.h

// Description :  

#ifndef _UTILSAUGMENTEDSTD_H_
#define _UTILSAUGMENTEDSTD_H_

// Public Libraries
#include <boost/functional/hash.hpp>
#include <fstream>
#include <iostream>
#include <list>
#include <unordered_set>
#include <utility>

namespace std
{

	// "------------------------ std::pair ------------------------ //

	template < class T1, class T2 > 
	std::ostream& operator<< (std::ostream& os, const std::pair < T1, T2 > & u) 
	{ 
	    os << "( " << u.first << " " << u.second << " )";
	    return os; 
	} 

	template < class T1, class T2 > 
	std::istream& operator>> (std::istream& is, std::pair < T1, T2 > & u)
	{
		is >> u.first;
		is >> std::skipws;
		is >> u.second;
		return is;
	}	

	// "------------------------ std::tuple ------------------------ //

	template < typename ... T, size_t ... I >
	std::ostream & InsertionOperatorTuple ( std::ostream & os 			   		, 
											const std::tuple 	< T ... > & u 	, 
											std::index_sequence < I ...  > const &  )
	{	
		((os << std::get < I >( u ) << ' ') , ...);
		return os;
	}

	template < typename ... T >
	std::ostream & operator<< ( std::ostream & os, 
								const std::tuple < T ... > & u )
	{
		os << "( ";
		InsertionOperatorTuple( os , u, std::index_sequence_for < T ... >{} );
		os << " )";
		return os;
	}


	template < typename ... T, size_t ... I >
	std::istream & ExtractionOperatorTuple ( 	std::istream & is 			   		, 
												std::tuple 	< T ... > 	& u , 
												std::index_sequence < I ...  > const &  )
	{	
		((is >> std::get < I >( u ) >> std::skipws ) , ...);
		return is;
	}

	template < typename ... T >
	std::istream & operator>> ( std::istream & is, 
								std::tuple < T ... > & u )
	{
		ExtractionOperatorTuple( is , u, std::index_sequence_for < T ... >{} );
		return is;
	}

	// "------------------------ std::unordered_set ------------------------ //

	template < class T > 
	std::ostream& operator<< (std::ostream& os, const std::unordered_set < T, 
													   boost::hash < T > > & U)
	{
		os << "( ";
		for( auto u = U.begin() ; u != U.end() ; u ++ )
		{	if( u == U.begin() )
			{	os << * u;			}
			else
			{	os << ", " << * u;	}
		}
		os << " )";

		return os;
	}	

	// "---------------------------- std::list ---------------------------- //

	template < class T >
	std::ostream& operator<< (std::ostream& os, std::list < T > & U)
	{
		os << "( ";
		for( auto u = U.begin() ; u != U.end() ; u ++ )
		{	if( u == U.begin() )
			{	os << * u;				 }
			else
			{	os << " " << * u;		 }
		}
		os << " ) ";

		return os;
	}



}

#endif
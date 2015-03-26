//
// CST 136 - Assignment #5
//
// Author: Leander Rodriguez
//
// File: array.inc
//
// Due date:  Sunday, June 9th by 11:59pm
//


#ifndef  array_i
#define  array_i


#include  <stdlib.h>
#include  <iostream>
#include  "array.h"



//
// Array construtor
//
template<class  ELEMENT_TYPE>
Array<ELEMENT_TYPE>::Array( Index  upperBound, Index  lowerBound )  :
  m_numElements( upperBound - lowerBound + 1 ),
  m_lowerBound( lowerBound )
{

	//
	// Bounds check/exception
	//
	if( upperBound < lowerBound)
	{
		throw ERR_BAD_BOUNDS;
	}
	

	//
	// Memory allocation
	//
	m_values =  new  ELEMENT_TYPE[m_numElements];


	//
	// Memory allocation check/exception
	//
	if  (! m_values)
	{
		throw ERR_MEM_ALLOC;
	}

}
  
  
  
//
// Array destructor
//
template<class  ELEMENT_TYPE>
Array<ELEMENT_TYPE>::~Array()
{
	cleanup();
}



//
// Array::cleanup()
//
// Cleans up reference counter
//
template < class ELEMENT_TYPE >
void Array< ELEMENT_TYPE >::cleanup()
{

	if  ( m_refCounter.onlyInstance() ) 
	{
		delete  []  m_values;
	}

}



//
// Array::copy
//
// Shallow copy of rhs to lhs
//
template < class ELEMENT_TYPE >
void Array<ELEMENT_TYPE>::copy( const Array &rhs )
{
	m_lowerBound  = rhs.lowerBound();
	m_numElements = rhs.m_numElements;
	m_refCounter  = rhs.m_refCounter;
	m_values = rhs.m_values;
}



//
// Array::operator=
//
// Assigns lhs to equal rhs
//
template < class ELEMENT_TYPE >
const Array< ELEMENT_TYPE > &Array< ELEMENT_TYPE >::operator=( const Array &rhs ) 
{
	if( this != &rhs )
	{
		cleanup();
		
		copy(rhs);
	}

	return *this;
}




//
// Array::operator[]
//
// Array indexing
//
template < class ELEMENT_TYPE >
ELEMENT_TYPE &Array< ELEMENT_TYPE >::operator[]( Index index ) 
{
	return m_values[realIndex(index)];
}



//
// Array::operator[] const
//
// Array indexing with const support
//
template < class ELEMENT_TYPE >
const ELEMENT_TYPE &Array< ELEMENT_TYPE >::operator[]( Index index ) const
{
	return m_values[realIndex(index)];
}



//
// SafeArray constructor
//
template<class  ELEMENT_TYPE>
SafeArray<ELEMENT_TYPE>::SafeArray( Index  upperBound, Index  lowerBound )  :
  Array<ELEMENT_TYPE>( upperBound, lowerBound )
{
}
  
  
  
//
// SafeArray::operator[]
//
// Array indexing with bounds checking
//
template < class ELEMENT_TYPE >
ELEMENT_TYPE &SafeArray< ELEMENT_TYPE >::operator[]( Index index ) 
{
	validateIndex(index);

	return Array<ELEMENT_TYPE>::operator[]( index );
}



//
// SafeArray::operator[] const
//
// Array indexing with bounds checking and const support
//
template < class ELEMENT_TYPE >
const ELEMENT_TYPE &SafeArray< ELEMENT_TYPE >::operator[]( Index index ) const
{
	validateIndex(index);

	return Array<ELEMENT_TYPE>::operator[]( index );
}



//
// SafeArray::validateIndex()
//
// Verifies an index value is within the valid range.
//
template<class  ELEMENT_TYPE>
void  SafeArray<ELEMENT_TYPE>::validateIndex( Index  index )  const
{

  if  ( index  <  lowerBound()  ||	index  >  upperBound() )
  {
	 throw ERR_OUT_OF_BOUNDS;
  }

}


#endif
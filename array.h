//
// CST 136 - Assignment #5
//
// Author: Leander Rodriguez
//
// File: array.h
//
// Due date:  Sunday, June 9th by 11:59pm
//


#ifndef  array_H
#define  array_H


#include  "refCounter.h"


//
// Exceptions
//
#define  ERR_BAD_BOUNDS     1
#define  ERR_MEM_ALLOC      2
#define  ERR_OUT_OF_BOUNDS  3


//
// Array class declaration
//
//    Constraints for ELEMENT_TYPE:
//      - must have a default constructor
//      - copyable
//      - assignable
//
template<class ELEMENT_TYPE>
class  Array
{
  public  :

    typedef  int  Index;

	//
	// Constructor
	//
    Array( Index  upperBound, Index  lowerBound = 0 );
    ~Array();


	//
	// Methods
	//
	const Array &operator=( const Array &rhs );

		  ELEMENT_TYPE &operator[]( Index index );
	const ELEMENT_TYPE &operator[]( Index index ) const;

    Index  lowerBound()  const  { return  m_lowerBound; }
    Index  upperBound()  const  { return  m_lowerBound + m_numElements - 1; }

    unsigned  numElements()  const  { return  m_numElements; }
    unsigned  size()		 const  { return  m_numElements * sizeof(ELEMENT_TYPE); }


  private  :

	//
	// Member Variables
	//
    unsigned int   m_numElements;
    Index          m_lowerBound;

    ELEMENT_TYPE  *m_values;

    RefCounter	   m_refCounter;


	//
	// Methods
	//
    Index  realIndex(Index  index)  const  { return  index - m_lowerBound; }

	void  cleanup();  
	void  copy( const Array  &rhs );
                
};




//
// SafeArray class declaration
//
//    Constraints for ELEMENT_TYPE:
//      - same as Array<>
//
template<class  ELEMENT_TYPE>
class  SafeArray  :  public  Array<ELEMENT_TYPE>
{
  public  :

	//
	// Constructor
	//
    SafeArray( Index  upperBound, Index  lowerBound = 0 );


	//
	// Methods
	//
		  ELEMENT_TYPE &operator[]( Index index );
	const ELEMENT_TYPE &operator[]( Index index ) const;


  private  :

	//
	// Methods
	//
    void  validateIndex( Index  index )  const;
};



//
// Implementation of Template file
//
#include  "array.inc"


#endif
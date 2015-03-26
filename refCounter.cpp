//
// CST 136 - Assignment #5
//
// Author: Leander Rodriguez
//
// File: refCounter.cpp
//
// Due date:  Sunday, June 9th by 11:59pm
//




//
// This file contains the member function bodies for the
// reference counter class.
//


#include  <iostream>
#include  "refCounter.h"

using namespace std;


//
// Constructor
//
RefCounter::RefCounter()  :  m_cnt(new int(1))
{
  if  (! m_cnt)
  {
    cerr  <<  "Memory allocation error!"  <<  endl;
    exit(EXIT_FAILURE);
  }
}


//
// Copy constructor
//
RefCounter::RefCounter(const RefCounter  &rhs) :
  m_cnt(rhs.m_cnt)
{
  (*m_cnt)++;
}


//
// Destructor
//
RefCounter::~RefCounter()
{
  if  ( ! --(*m_cnt) )
    delete m_cnt;
}



//
// RefCounter::operator=
//
RefCounter &RefCounter::operator=( const RefCounter  &rhs )
{
	m_cnt = rhs.m_cnt;

	(*m_cnt)++;

	return *this;
}

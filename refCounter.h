//
// CST 136 - Assignment #5
//
// Author: Leander Rodriguez
//
// File: refCounter.h
//
// Due date:  Sunday, June 9th by 11:59pm
//


//
// This file contains the declaration for a
// reference counter class.
//

#ifndef  refCounter_H
#define  refCounter_H


class RefCounter
{
  public  :

    RefCounter();

    RefCounter(const RefCounter  &rhs);

    ~RefCounter();

    bool  onlyInstance() const {  return *m_cnt == 1;  }

	RefCounter &operator=( const RefCounter  &rhs );

  private  :

    int  *m_cnt;
};


#endif

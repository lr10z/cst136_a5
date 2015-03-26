//
// CST 136 - Assignment #5
//
// Author: Leander Rodriguez
//
// File: crypto.cpp
//
// Due date:  Sunday, June 9th by 11:59pm
//


#include  <iostream>
#include  "crypto.h"


//
// This is needed to supress Microsoft's compiler from generating
// annoying C4996 warning messages for strcpy()
//
#define _CRT_SECURE_NO_WARNINGS



//
// Crypto constructor
//
Crypto::Crypto( const string phrase, char minChar, char maxChar ) :
	m_phrase( phrase ),
	m_minChar( minChar ),
	m_maxChar( maxChar )
{

}
	
	
	
//
// Caesar constructor
//
Caesar::Caesar( const string phrase, int numKey, char minChar, char maxChar ) :
	Crypto( phrase, minChar, maxChar ),
	m_numKey( numKey )
{
	
}
	
	
	
//
// Convert the key value to number within the range
// of valid characters.
//
const int Caesar::normalizeKey() const
{
  int  normKey  =  abs( m_numKey );

  normKey  %=  numCharacters();

  if  ( m_numKey < 0)
    normKey  =  numCharacters() - normKey;

  return  normKey;
}



//
// Caesar::encrypt
//
void Caesar::encrypt()
{

	m_numKey  =  normalizeKey();

	size_t  len  =  phrase().length();

	size_t  idx;


	//
	// Process each character
	//
	for( idx=0;  idx < len;  ++idx )
	{
		//
		// Out of range characters are just transfered to
		// the ciphertext
		//
		if  (  phrase()[idx] < min()  ||  phrase()[idx] > max() )
		{
			continue;
		}


		//
		// Determine the alphabet index of the plaintext character
		//
		char  c  =  phrase()[idx] - min();


		//
		// Add the key to the alphabet index to get the ciphertext
		// character. Handle the wrap-around past the last valid
		// character.
		//
		c  +=  m_numKey % numCharacters();
		c  %=  numCharacters();
		c  += min();

		phrase()[idx]  =  c;

	}

}



//
// Caesar::decrypt
//
void Caesar::decrypt()
{
	m_numKey = -m_numKey;

	Caesar::encrypt();

	m_numKey = -m_numKey;
}




//
// Substitution constructor
//
Substitution::Substitution( const string phrase, string strKey, char minChar, char maxChar ) :
	Crypto( phrase, minChar, maxChar ),
	m_strKey( strKey )
{

}



//
// Substitution::encrypt
//
void Substitution::encrypt()
{

	size_t  srcIdx;

	//
	// Process each character
	//
	for( srcIdx = 0;  srcIdx < phrase().length();  ++srcIdx )
	{
		//
		// If the plaintext character is in range, then the plaintext
		// character number as the index into the key string to find
		// the cipher character. Otherwise, the ciphertext character
		// is the plaintext character.
		//
		if  (  phrase()[srcIdx] < min()  ||  phrase()[srcIdx] > max()  )
		{

			phrase()[srcIdx]  =  phrase()[srcIdx];

		}
		else
		{
			//
			// Determine the character number of the plaintext character
			//
			int  keyIdx  =  phrase()[srcIdx] - min();

			phrase()[srcIdx]  =  m_strKey[keyIdx];

		}
	}

}




//
// Returns the index of the first occurance of a character
// within a string. Returns NOT_FOUND if the character is
// not in the string.
//
int  Substitution::findIndexOf( string strKey, char  c ) const
{
	for( unsigned  idx = 0;  idx < numCharacters();  ++idx )
	{
		if (strKey[idx] == c)  return  idx;
	}
	
	return  NOT_FOUND;
}



//
// Substitution::decrypt
//
void Substitution::decrypt() 
{

	size_t  srcIdx;

	//
	// Process each character
	//
	for( srcIdx = 0;  srcIdx < phrase().length();  ++srcIdx )
	{
		//
		// Determine the index of the ciphertext character within the
		// key
		//
		int  keyIdx  =  findIndexOf( m_strKey, phrase()[srcIdx] );


		//
		// If the key index was not found, the plaintext character is
		// the ciphertext character. Otherwise, use the key index
		// as the alphabet offset to determine the plaintext character.
		//
		if  ( keyIdx == NOT_FOUND )
			phrase()[srcIdx]  =  phrase()[srcIdx];
		else
			phrase()[srcIdx]  =  min() + keyIdx;

	}

}
//
// CST 136 - Assignment #5
//
// Author: Leander Rodriguez
//
// File: crypto.h
//
// Due date:  Sunday, June 9th by 11:59pm
//


#ifndef  crypto_H
#define  crypto_H

#include  <string>

using namespace std;


//
// Constant
//
#define  NOT_FOUND  (-1)



//
// Crypto class declaration
//
class  Crypto
{
  public  :

	//
	// Constructor
	//
    Crypto( const string phrase, char minChar, char maxChar );

	//
    // Methods
	//
	string &phrase() { return m_phrase; }

	virtual void encrypt() = 0; 
	virtual void decrypt() = 0; 


  protected	:

	//
	// Methods
	//
	const char min() const { return m_minChar; }
	const char max() const { return m_maxChar; }

	const unsigned numCharacters() const { return max() - min() + 1; }


  private  :
	
	//
	// Member variables
	//
    string m_phrase;
	char  m_minChar;
	char  m_maxChar;

};



//
// Caesar class declaration
//
class  Caesar  :  public  Crypto
{
  public  :

	//
	// Constructor
	//
    Caesar( const string phrase,  int numKey, char minChar, char maxChar );

	//
	// Methods
	//
	virtual void encrypt(); 	 
	virtual void decrypt();


  private  :

	//
	// Member variable
	//
	int m_numKey;


	//
	// Method
	//
	const int normalizeKey() const;
	
};



//
// Substitution class declaration
//
class  Substitution  :  public  Crypto
{
  public  :

	//
	// Constructor
	//
    Substitution( const string phrase, string strKey, char minChar, char maxChar );

	//
	// Methods
	//
	virtual void encrypt();
	virtual void decrypt();


  private  :

	//
	// Member variable
	//
	string m_strKey;


	//
	// Method
	//
	int findIndexOf( string strKey, char  c ) const;
 
};


#endif
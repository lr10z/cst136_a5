//
// CST 136 - Assignment #5 (test program)
//
// Leander Rodriguez
//
// File: main.cpp
//


/*
#include  <math.h>
#include  <iostream>
#include  "array.h"


using  namespace  std;


//
// main() program
//
int  main()
{

	try
	{
		/*
		Array<char> c(15);

		c[3] = 'l';

		cout  <<  c[3]  <<  endl  <<  endl;
		
		Array<char>  a1(15,5);
		Array<char>  a2(20);
		//Array<char>  a3(a2);

		a1[10] = 'e';
		a1[11] = 'o';

		cout  <<  a1[10]  <<  " "  <<  a1[11]  <<  endl  <<  endl;

		a2 = a1;

		cout  <<  a2[10]  <<  " "  <<  a2[11]  <<  endl  <<  endl;
		

		
		//New tests
		SafeArray<int> d(15);

		d[3] = 123;

		cout  <<  d[3]  <<  endl  <<  endl;
		
		SafeArray<int>  a(15,5);
		SafeArray<int>  b(a);
		SafeArray<int>  c(20);

		a[10] = 10;
		a[11] = 20;

		cout  <<  a[10]  <<  " "  <<  a[11]  <<  endl  <<  endl;

		b = c;

		cout  <<  b[10]  <<  " "  <<  b[11]  <<  endl  <<  endl;
		
	}

	catch( int x )
	{
		if( x == ERR_BAD_BOUNDS )
		{
			std::cerr  <<  "Upper bound is less-than lower bound!"  <<  std::endl;
		}
		else if( x == ERR_MEM_ALLOC )
		{
			std::cerr  <<  "Memory allocation error!"  <<  std::endl;
		}
		else if( x == ERR_OUT_OF_BOUNDS  )
		{
			std::cerr  <<  "Index out of range"  <<  std::endl;
		}

	}
	
	

  return  0;
}
*/





//
// CST 136 - Assignment #5 - part 2
//
// Author:  Michael Hoffman
//
// File:  crypto_sample.cpp
//
// Sample program to illustrate the use of the Cypto,
// Caesar, and Substitution classes.
//
// Note: this program only illustrates how to instantiate and use
// the Caesar and Substitution classes.  It does not illustrate the
// the polymorphic features for the classes.
//


#include  <iostream>
#include  "crypto.h"

using  namespace  std;


//
// Given minimum and maximum characters for a range, this function will generate
// a random key string that contains one instance of every character in the range.
// For example, if the range is 'a' to 'c', the key string will be three characters
// long and will contain the characters 'a', 'b', and 'c' in random order.
//
// The randSee parameter is a seed for the random number generator used to create
// the string.
//
// Expected program output is at the bottom of this file.
//
string  generateSubstitutionKey( char  minChar, char  maxChar, unsigned  randSeed )
{
  int     numCharacters  =  maxChar - minChar + 1;
  string  keyStr;
  int     idx = 0;

  //
  // Seed the random number generator
  //
  srand( randSeed );

  //
  // Loop until the key string is full
  //
  while( idx < numCharacters )
  {
    //
    // Pick a random character in the range
    //
    char  nextChar  =  rand() % numCharacters  +  minChar;

    //
    // If the random character is already in the key string then loop to
    // generate another random character.
    //
    if  ( keyStr.find(nextChar) != string::npos )
      continue;

    //
    // The random character isn't in the string, so add it to end of the string.
    //
    keyStr.push_back( nextChar );

    ++idx;
  }

  return  keyStr;
}



//
// Main program
//
int  main()
{
  //
  // Caesar example
  //
  // Uses a valid character range of 'a' to 'z' and
  // a key of 5.
  //
  Caesar  msg1( "This is a secret message!", 5, 'a', 'z' );

  cout  <<  "Original - "  <<  msg1.phrase()  <<  endl;

    //
    // Encrypt
    //
  msg1.encrypt();
  cout  <<  " Encrypt - "  <<  msg1.phrase()  <<  endl;

    //
    // Decyrpt
    //
  msg1.decrypt();
  cout  <<  " Decrypt - "  <<  msg1.phrase()  <<  endl  <<  endl;


  //
  // Substitution example
  //
  // Uses a valid character range of 'A' to 'Z' and
  // a key generated with a seed of 123.
  //
  string  key  =  generateSubstitutionKey( 'A', 'Z', 123 );

  Substitution  msg2( "THIS one IS'T so SECRET.", key, 'A', 'Z' );

  cout  <<  "Original - "  <<  msg2.phrase()  <<  endl;

    //
    // Encrypt
    //
  msg2.encrypt();
  cout  <<  " Encrypt - "  <<  msg2.phrase()  <<  endl;

    //
    // Decrypt
    //
  msg2.decrypt();
  cout  <<  " Decrypt - "  <<  msg2.phrase()  <<  endl;

  return  0;
}


/* Expected output

Original - This is a secret message!
 Encrypt - Tmnx nx f xjhwjy rjxxflj!
 Decrypt - This is a secret message!

Original - THIS one IS'T so SECRET.
 Encrypt - LWKM one KM'L so MTNCTL.
 Decrypt - THIS one IS'T so SECRET.

*/
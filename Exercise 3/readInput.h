/** 
 *	@author  Rafael Pintar Alevato
 *	@date    17/09/2017
 *	@version 1.0 
 *	
 *	@brief Read input from user.
 *
 *	@section DESCRIPTION
 *	
 *	Each function reads a type of input from user and returns
 *	whether it was successfull.
 */

#ifndef READINPUT
#define READINPUT

#include <iostream>

using namespace std;

string getString();

template <typename numberType>
bool readNumber(numberType& output);

bool readString(string& output);

bool readChar(char& output);

#endif			// READINPUT
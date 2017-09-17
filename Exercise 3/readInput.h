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
#include <exception>

using namespace std;

/**
 *	Read an input from user and saves it in an int.
 *	@param	output	Result if input was int
 *	@return	Whether is successfully converted to int
 */
bool readInt(int& output);

/**
 * Read an input from user and saves it in an float.
 * @param	output	Result if input was float
 * @return	Whether is successfully converted to float
 */
bool readFloat(float& output);

/**
 * Read an input from user and saves it in an char.
 * @param	output	Result if input was char
 * @return	Whether is successfully converted to char
 */
bool readChar(char& output);

/**
 * Read an input from user and saves it in an string.
 * @param	output	Result if input was string not empty
 * @return	Whether is successfully converted to char
 */
bool readString(string& output);

#endif			// READINPUT
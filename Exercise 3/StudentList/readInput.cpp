#include <iostream>
#include <exception>
#include "readInput.h"

using namespace std;

/**
 * Read an input from user and saves it in an int.
 * @param	output	Result if input was int
 * @return	Whether is successfully converted to int
 */
bool readInt(int& output) {
	string input;
	bool result = true;

	// Get input in string format
	while (input.empty()) {
		getline(cin, input);
	}

	// Convert to int the string
	try {
		output = stoi(input);
	} catch (exception& e) {
		result = false;
	}

	return result;
}

/**
 * Read an input from user and saves it in an float.
 * @param	output	Result if input was float
 * @return	Whether is successfully converted to float
 */
bool readFloat(float& output) {
	string input;
	bool result = true;

	// Get input in string format
	while (input.empty()) {
		getline(cin, input);
	}

	// Convert to float the string
	try {
		output = stof(input);
	} catch (exception& e) {
		result = false;
	}

	return result;
}

/**
 * Read an input from user and saves it in an char.
 * @param	output	Result if input was char
 * @return	Whether is successfully converted to char
 */
bool readChar(char& output) {
	string input;
	bool result = true;

	// Get input in string format
	while (input.empty()) {
		getline(cin, input);
	}

	// Checks if single char
	if (input.size() > 1) {
		output = '\0';
		result = false;
	} else {
		output = input[0];
	}

	return result;
}

/**
 * Read an input from user and saves it in an string.
 * @param	output	Result if input was string not empty
 * @return	Whether is successfully converted to char
 */
bool readString(string& output) {
	bool result = true;

	while (output.empty()) {
		getline(cin, output);
	}

	return result;
}
#include <iostream>
#include <exception>
#include "readInput.h"

using namespace std;

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

bool readString(string& output) {
	bool result = true;

	while (output.empty()) {
		getline(cin, output);
	}

	return result;
}
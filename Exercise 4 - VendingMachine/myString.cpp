#include <iostream>
#include <sstream>
#include "myString.h"

using namespace std;

template<typename type>
string numberToString(type& input) {
	stringstream ss;
	string output;
	ss << input;
	ss >> output;
	return output;
}
template string numberToString<int>(int& input);
template string numberToString<short int>(short int& input);
template string numberToString<long int>(long int& input);
template string numberToString<long long int>(long long int& input);
template string numberToString<unsigned int>(unsigned int& input);
template string numberToString<unsigned short int>(unsigned short int& input);
template string numberToString<unsigned long int>(unsigned long int& input);
template string numberToString<unsigned long long int>(unsigned long long int& input);
template string numberToString<float>(float& input);
template string numberToString<double>(double& input);
template string numberToString<long double>(long double& input);
template string numberToString<char>(char& input);
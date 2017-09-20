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
template string numberToString<float>(float& input);
template string numberToString<double>(double& input);
template string numberToString<long>(long& input);
template string numberToString<unsigned int>(unsigned int& input);
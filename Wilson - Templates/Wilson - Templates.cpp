#include <iostream>
#include <cctype>
#include <cmath>
#include "WilsonAlecPL.h"

using namespace std;

template <typename numType>
numType half(numType start);

int main() {
	double a = 7.0;
	float b = 5.0f;
	int c = 3;

	cout << half(a) << endl;
	cout << half(b) << endl;
	cout << half(c) << endl;
}

template <typename numType>
numType half(numType start) {
	numType output;

	if (is_same<numType, int>::value) {
		output = (start + (2 / 2)) / 2;
	}
	else if (is_same<numType, float>::value) {
		output = start / 2;
	}
	else if (is_same<numType, double>::value) {
		output = start / 2;
	}
	else {
		throw "ERROR: invalid argument type";
	};

	return output;
};
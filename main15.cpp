#include "stdafx.h"
#include <iostream>

using namespace System;

class Ariphmetic {
public:
	float add(float arg1, float arg2) {
		return arg1 + arg2;
	}

	float subtract(float arg1, float arg2) {
		return arg1 - arg2;
	}

	float multiply(float arg1, float arg2) {
		return arg1 * arg2;
	}

	float divide(float arg1, float arg2) {
		return arg1 / arg2;
	}
};

int main(array<System::String ^> ^args)
{
	using namespace std;

	Ariphmetic test;

	setlocale(LC_ALL, "");

	cout << test.add(1.5, 2.4) << endl;
	cout << test.subtract(5.7, 2.34) << endl;
	cout << test.multiply(12.5, 5.1) << endl;
	cout << test.divide(60.4, 5.1) << endl;

	system("pause");
	return 0;
}

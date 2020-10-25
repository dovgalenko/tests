#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace System;

int main(array<System::String ^> ^args)
{
	using namespace std;

	setlocale(LC_ALL, "");

	cout << "Results for: y=5/(x^2-81) :" << endl;

	for (double x = -20; x <= 20; x = x + 0.5) {
		double y = 5 / (pow(x, 2) - 81);

		cout.precision(3);
		cout << " x:" << x << ", y:" << y << endl;
	}

	system("pause");
	return 0;
}

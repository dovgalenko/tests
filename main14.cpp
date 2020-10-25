#include "stdafx.h"
#include <iostream>

using namespace System;

int minimum(int arg1, int arg2) {
	return arg1 < arg2 ? arg1 : arg2;
}

int main(array<System::String ^> ^args)
{
	using namespace std;

	setlocale(LC_ALL, "");

	int num1, num2;

	cout << "Input array numbers (followed by Enter) :" << endl;

	cout << "Number 1 : ";
	scanf("%d", &num1);

	cout << "Number 2 : ";
	scanf("%d", &num2);

	int min = minimum(num1, num2);

	cout << "The minimum of numbers " << num1 << " and " << num2 << " is " << min << endl;

	system("pause");
	return 0;
}

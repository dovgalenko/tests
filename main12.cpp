#include "stdafx.h"
#include <iostream>

using namespace System;

int main(array<System::String ^> ^args)
{
	using namespace std;

	setlocale(LC_ALL, "");

	int num;
	int temp[10];

	cout << "Input array numbers (followed by Enter) :" << endl;

	for (int i = 0; i < 10; i++) {
		cout << "temp[" << i << "] = ";
		scanf("%d", &num);

		temp[i] = num;
	}

	cout << "Input number (followed by Enter) to search in array - ";
	scanf("%d", &num);

	bool result = false;
	for (int j = 0; j < 10; j++) {
		if (temp[j] == num) {
			result = true;
			break;
		}
	}

	cout << "Number " << num << " " << (result ? "is" : "isn't") << " found." << endl;

	system("pause");
	return 0;
}

#include "stdafx.h"
#include <iterator>
#include <iostream>
#include <set>

using namespace System;

int main(array<System::String ^> ^args)
{
	using namespace std;

	setlocale(LC_ALL, "");

	multiset<int, greater<int>> data = { 5, 10, 11, 12, 5, 31, 11 };
	int count = 0;

	cout << "Изначальное мультимножество" << endl;
	for (multiset<int>::iterator i = data.begin(); i != data.end(); i++) {
		cout.width(4);
		cout << (*i);
	}
	cout << endl;

	multiset<int>::iterator it = data.begin();
	while (it != data.end()) {
		if (*it == 5) {
			data.erase(it);
			count++;
		}
		it = data.find(5);
	}

	cout << "Результирующее мультимножество" << endl;
	for (multiset<int>::iterator i = data.begin(); i != data.end(); i++) {
		cout.width(4);
		cout << (*i);
	}
	cout << endl;

	cout << "Произведено удалений - " << count << endl;

	system("pause");
	return 0;
}

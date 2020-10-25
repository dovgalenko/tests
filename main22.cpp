#include "stdafx.h"
#include <iterator>
#include <iostream>
#include <forward_list>

using namespace System;

int main(array<System::String ^> ^args)
{
	using namespace std;

	setlocale(LC_ALL, "");

	forward_list<int> data = { 5, 6, 7, 8 };

	cout << "����������� ������" << endl;
	for (forward_list<int>::iterator i = data.begin(); i != data.end(); i++) {
		cout.width(4);
		cout << (*i);
	}
	cout << endl;

	data.push_front(3);
	data.push_front(2);
	data.push_front(1);

	cout << "�������� ��� ��������" << endl;
	for (forward_list<int>::iterator i = data.begin(); i != data.end(); i++) {
		cout.width(4);
		cout << (*i);
	}
	cout << endl;

	forward_list<int>::iterator it;
	it = data.begin();
	advance(it, 2);
	data.remove(*it);

	cout << "������� ������ �������" << endl;
	for (forward_list<int>::iterator i = data.begin(); i != data.end(); i++) {
		cout.width(4);
		cout << (*i);
	}
	cout << endl;

	it = find(data.begin(), data.end(), 7);
	it = data.erase_after(it);

	cout << "�������������� ������" << endl;
	for (forward_list<int>::iterator i = data.begin(); i != data.end(); i++) {
		cout.width(4);
		cout << (*i);
	}
	cout << endl;

	system("pause");
	return 0;
}

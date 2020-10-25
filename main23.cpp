#include "stdafx.h"
#include <iterator>
#include <iostream>
#include <time.h>
#include <set>

using namespace System;

int main(array<System::String ^> ^args)
{
	using namespace std;

	setlocale(LC_ALL, "");

	set<int> data;
	int index;
	time_t t;

	// ������������� ����������
	srand((unsigned)time(&t));

	// ��������� 10 �����
	for (int i = 0; i < 10; i++) {
		// ���� ������ ��������� ������� ��  �� 7
		data.insert(rand() % 100);
	}

	// ���� � ������ ����� 5
	set<int>::iterator item = find(data.begin(), data.end(), 15);

	if (item != data.end()) {
		// ����� �����
		index = distance(data.begin(), item);

		cout << "������ ����� :" << index << endl;
	}
	else {
		cout << "����� 15 �� �������" << endl;

		// ��������� ����� � ���
		cout << "��������� ����� 15" << endl;
		set<int>::iterator it = data.begin();
		advance(it, rand() % data.size());
		data.insert(it, 15);

		// ���� � ������ ����� 5
		set<int>::iterator item = find(data.begin(), data.end(), 15);
		if (item != data.end()) {
			// ����� �����
			index = distance(data.begin(), item);

			cout << "������ ������������ ����� :" << index << endl;
		}
	}

	for (set<int>::iterator i = data.begin(); i != data.end(); ++i) {
		cout.width(4);
		cout << (*i);
	}
	cout << endl;

	system("pause");
	return 0;
}

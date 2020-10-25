#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace System;

int main(array<System::String ^> ^args)
{
	using namespace std;

	setlocale(LC_ALL, "");

	time_t t;
	list<int> numbers;
	list<int> empty;
	int index = -1;

	// ������������� ����������
	srand((unsigned)time(&t));

	// ��������� 10 �����
	for (int i = 0; i < 10; i++) {
		// ���� ������ ��������� ������� ��  �� 7
		numbers.push_front(rand() % 7 + 1);
		// ������ ������
		empty.push_front(0);
	}

	// ���� � ������ ����� 5
	list<int>::iterator item = find(numbers.begin(), numbers.end(), 5);

	if (item != numbers.end()) {
		// ����� �����
		index = distance(numbers.begin(), item);

		cout << "������ ����� :" << index << endl;
	}
	else {
		cout << "����� 5 �� �������" << endl;
	}

	cout << "�������������� ������: " << endl;
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	if (index > -1) {
		list<int>::iterator it = numbers.begin();

		advance(it, index);
		for (int j = 0; j < 10; j++) {
			numbers.emplace(it, empty.back());
			empty.pop_back();
		}
	}

	cout << "�������������� ������: " << endl;
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	numbers.sort();

	cout << "��������������� ������: " << endl;
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}

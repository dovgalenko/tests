#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace System;

int main(array<System::String ^> ^args)
{
	using namespace std;

	setlocale(LC_ALL, "");

	time_t t;
	vector<int> numbers;

	// ������������� ����������
	srand((unsigned)time(&t));

	// ��������� 10 �����
	for (int i = 0; i < 10; i++) {
		numbers.push_back(rand() % 100 - 50);
	}

	cout << "�������������� ������: ";
	// ������ ������ �� �����
	for (int i = 0; i < numbers.size(); i++)
	{
		cout.width(4);
		cout << numbers[i];
	}
	cout << endl;

	// ������ ������ ����� ������ ����
	int number = 3;
	for (int j = 0; j < numbers.size(); j++) {
		if (numbers[j] > number) {
			number = numbers[j];
			break;
		}
	}
	vector<int>::iterator item = find(numbers.begin(), numbers.end(), number);

	if (item != numbers.end()) {
		// ����� �����
		int index = std::distance(numbers.begin(), item);

		cout << "������ ����� :" << index << endl;
	} else {
		// ����� �� �����
	}
	system("pause");
	return 0;
}

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

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

	// ������ ������ �� �����
	int num_chet = count_if(numbers.begin(), numbers.end(), [](int i) { return i % 2 == 0; });
	int num_nechet = count_if(numbers.begin(), numbers.end(), [](int i) { return i % 2 != 0; });

	cout << "���������� �������� " << num_nechet << ", ������ " << num_chet << endl;

	system("pause");
	return 0;
}

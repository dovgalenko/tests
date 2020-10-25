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

	// �������� ���������, �� numbers.begin() �� numbers.end() � ������, ���� �������� less ���������� ������
	numbers.resize(remove_if(numbers.begin(), numbers.end(), bind2nd(less<int>(), 0)) - numbers.begin());

	cout << "�������������� ������: ";
	// ������ ������ �� �����
	for (int i = 0; i < numbers.size(); i++)
	{
		cout.width(4);
		cout << numbers[i];
	}
	cout << endl;

	system("pause");
	return 0;
}

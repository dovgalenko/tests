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

	// Инициализация генератора
	srand((unsigned)time(&t));

	// Формируем 10 чисел
	for (int i = 0; i < 10; i++) {
		numbers.push_back(rand() % 100 - 50);
	}

	cout << "Сформированный вектор: ";
	// Выдаем массив на экран
	for (int i = 0; i < numbers.size(); i++)
	{
		cout.width(4);
		cout << numbers[i];
	}
	cout << endl;

	// Удаление элементов, от numbers.begin() до numbers.end() в случае, если предикат less возвращает истину
	numbers.resize(remove_if(numbers.begin(), numbers.end(), bind2nd(less<int>(), 0)) - numbers.begin());

	cout << "Результирующий вектор: ";
	// Выдаем массив на экран
	for (int i = 0; i < numbers.size(); i++)
	{
		cout.width(4);
		cout << numbers[i];
	}
	cout << endl;

	system("pause");
	return 0;
}

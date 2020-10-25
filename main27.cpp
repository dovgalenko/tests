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

	// Найдем первое число больше трех
	int number = 3;
	for (int j = 0; j < numbers.size(); j++) {
		if (numbers[j] > number) {
			number = numbers[j];
			break;
		}
	}
	vector<int>::iterator item = find(numbers.begin(), numbers.end(), number);

	if (item != numbers.end()) {
		// Нашли число
		int index = std::distance(numbers.begin(), item);

		cout << "Индекс числа :" << index << endl;
	} else {
		// Число не нашли
	}
	system("pause");
	return 0;
}

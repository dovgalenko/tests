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

	// Инициализация генератора
	srand((unsigned)time(&t));

	// Формируем 10 чисел
	for (int i = 0; i < 10; i++) {
		// Один список наполняем числами от  до 7
		data.insert(rand() % 100);
	}

	// Ищем в списке число 5
	set<int>::iterator item = find(data.begin(), data.end(), 15);

	if (item != data.end()) {
		// Нашли число
		index = distance(data.begin(), item);

		cout << "Индекс числа :" << index << endl;
	}
	else {
		cout << "Число 15 не найдено" << endl;

		// Вставляем число в сет
		cout << "Вставляем число 15" << endl;
		set<int>::iterator it = data.begin();
		advance(it, rand() % data.size());
		data.insert(it, 15);

		// Ищем в списке число 5
		set<int>::iterator item = find(data.begin(), data.end(), 15);
		if (item != data.end()) {
			// Нашли число
			index = distance(data.begin(), item);

			cout << "Индекс вставленного числа :" << index << endl;
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

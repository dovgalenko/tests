#include "stdafx.h"
#include <iostream>
#include<time.h>

using namespace System;

int main(array<System::String ^> ^args)
{
	using namespace std;

	setlocale(LC_ALL, "");

	time_t t;
	int arr[10][10];

	// Инициализация генератора
	srand((unsigned)time(&t));

	// Формируем массив чисел
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			arr[i][j] = rand() % 100;
		}
	}

	// Выдаем массив на экран
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {

			cout.width(4);
			cout << arr[i][j];
		}
		cout << endl;
	}

	for (int row = 0; row < 10; row++) {
		if (row % 2 == 0) {
			// строка четная, по возрастанию
			for (int col = 0; col < 10; col++) {
				for (int rev = 10; rev > col; rev--) {
					if (arr[row][col] < arr[row][rev]) {
						int elem = arr[row][col];
						arr[row][col] = arr[row][rev];
						arr[row][rev] = elem;
					}				
				}
			}
		}
		else {
			// строка нечетная, по убыванию
			for (int col = 0; col < 10; col++) {
				for (int rev = 10; rev > col; rev--) {
					if (arr[row][col] > arr[row][rev]) {
						int elem = arr[row][col];
						arr[row][col] = arr[row][rev];
						arr[row][rev] = elem;
					}
				}
			}
		}
	}

	// Выдаем массив на экран
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {

			cout.width(4);
			cout << arr[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

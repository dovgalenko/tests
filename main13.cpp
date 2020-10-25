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

	// ������������� ����������
	srand((unsigned)time(&t));

	// ��������� ������ �����
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			arr[i][j] = rand() % 100;
		}
	}

	// ������ ������ �� �����
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
			// ������ ������, �� �����������
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
			// ������ ��������, �� ��������
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

	// ������ ������ �� �����
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

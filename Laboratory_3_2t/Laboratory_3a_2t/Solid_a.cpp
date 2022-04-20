#include "Contents_a.h"
#include <iostream> 
#include <string.h> 
#include <stdio.h> 
#define M 100
#define _CRT_SECURE_NO_WARNINGS 
//#define SUM
using namespace std;
void otn(int* arr, int* size) {
	cout << "Введите размер массива : \n";
	cin >> *size;
	cout << "Массив : \n";
	for (int i = 0; i < *size; i++)
	{
		*(arr + i) = rand() % 201 - 100;
		cout << *(arr + i) << " ";
	}
	cout << endl;

	int count = 0;
	for (int i = 0; i < *size; i++) {
		if (*(arr + i) < 0) {
			count++;
		}
	}
	cout << "Количество отрицательных элементов: " << count << endl;
#ifdef  SUM
	int sum = 0;
	for (int i = 0; i < *size; i++) {
		if (*(arr + i) < 0) {
			sum += *(arr + i);
		}
	}
	cout << "Сумма отрицательных элементов: " << sum << endl;
#endif //  SUM

	
}
void abs(int* arr, int* size) {
	int* narr = arr;
	cout << "Введите размер массива : \n";
	cin >> *size;
	cout << "Массив : \n";
	for (int i = 0; i < *size; i++, arr++)
	{
		*arr = rand() % 201 - 100;
		cout << *arr << " ";
	}
	cout << endl;

	arr = narr;
	int count = 0;
	for (int i = 0; i < *size; i++, arr++) {
		if (*arr < 0) {
			count++;
		}
	}
	cout << "Количество отрицательных элементов: " << count << endl;
	arr = narr;
#ifdef  SUM
	int sum = 0; 
	for (int i = 0; i < *size; i++, arr++) {
		if (*arr < 0) {
			sum += *arr;
		}
	}
	cout << "Сумма отрицательных элементов: " << sum << endl;
#endif //  SUM
}
void noad(int* arr, int* size) {
	int* narr = arr;
	cout << "Введите размер массива : \n";
	cin >> *size;
	cout << "Массив : \n";
	for (; arr < narr + *size; arr++)
	{
		*arr = rand() % 201 - 100;
		cout << *arr << " ";
	}
	cout << endl;

	int count = 0;
	for (arr = narr; arr < narr + *size; arr++) {
		if (*arr < 0) {
			count++;
		}
	}
	cout << "Количество отрицательных элементов: " << count << endl;
#ifdef  SUM
	int sum = 0;
	for (arr = narr; arr < narr + *size; arr++) {
		if (*arr < 0) {
			sum += *arr;
		}
	}
	cout << "Сумма отрицательных элементов: " << sum << endl;
#endif //  SUM
}
void pmas() {
	const int size = 10000;
	int N;
	cout << "Введите размер массива : \n";
	cin >> N;
	int arr[size];

	cout << "Массив : \n";
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 201 - 100;
		cout << arr[i] << " ";
	}

	int* parr[size];
	//инициализация
	for (int i = 0; i < N; i++) {
		parr[i] = &arr[i];
	}

	int count = 0;
	cout << endl;
	for (int i = 0; i < N; i++) {
		if (*parr[i] < 0) {
			count++;
		}
	}
	cout << "Количество отрицательных элементов: " << count << endl;
#ifdef  SUM
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (*parr[i] < 0) {
			sum += *parr[i];
		}
	}
	cout << "Сумма отрицательных элементов:" << sum << endl;
#endif //  SUM

}
void pxp() {
	const int size = 10000;
	int N;
	cout << "Введите размер массива : \n";
	cin >> N;
	int arr[size];

	cout << "Массив : \n";
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 201 - 100;
		cout << arr[i] << " ";
	}

	int* p[size];

	for (int i = 0; i < N; i++) {
		p[i] = &arr[i];
	}
	int** pp = p;
	int count = 0;
	cout << endl;
	for (int i = 0; i < N; i++) {
		if (**pp < 0) {
			count++;
		}
		*(++(*pp));
	}
	cout << "Количество отрицательных элементов: " << count << endl;
#ifdef  SUM
	for (int i = 0; i < N; i++) {
		p[i] = &arr[i];
	}
	pp = p;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (**pp < 0) {
			sum += **pp;
		}
		*(++(*pp));
	}
	cout << "Сумма отрицательных элементов:" << sum << endl;
#endif //  SUM
}
void par(int* arr, int* size, int* sum, int* count) {
	for (int i = 0; i < *size; i++) {
		if (arr[i] < 0) {
			*count += 1;
#ifdef  SUM
			*sum += arr[i];
#endif //  SUM
		}
	}
}
void osn() {
	setlocale(LC_ALL, "Russian");
	while (true) {
		int answer;
		int arr[M];
		int size;
		cout << "Выберите действие:" << endl;
		cout << "(1)Относительный адрес" << endl;
		cout << "(2)Абсолютный адрес" << endl;
		cout << "(3)Не используя адресацию" << endl;
		cout << "(4)Через массив указателей" << endl;
		cout << "(5)Через указатель на указатель" << endl;
		cout << "(6)С параметрами указателя" << endl;
		
		cin >> answer;

		if (answer == 1) {
			otn(arr, &size);
		}
		if (answer == 2) {
			abs(arr, &size);
		}
		if (answer == 3) {
			noad(arr, &size);
		}
		if (answer == 4) {
			pmas();
		}
		if (answer == 5) {
			pxp();
		}
		if (answer == 6) {
			const int razm = 10000;
			int size;
			cout << "Введите размер массива : \n";
			cin >> size;
			int arr[razm];

			cout << "Массив : \n";
			for (int i = 0; i < size; i++) {
				arr[i] = rand() % 201 - 100;
				cout << arr[i] << " ";
			}
			cout << endl;
			int sum = 0;
			int count = 0;
			par(arr, &size, &sum, &count);
			cout << "Количество отрицательных элементов:" << count << endl;
			cout << "Сумма отрицательных элементов:" << sum << endl;
		}
	}
}
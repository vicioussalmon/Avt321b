#include "Contents_b.h"
#include <iostream> 
#include <string.h> 
#include <stdio.h> 
#include <iomanip>
#include <cstdlib>
#define M 100
#define _CRT_SECURE_NO_WARNINGS 
#define ARR
using namespace std;
void zap(int* A, int* size) {
    setlocale(LC_ALL, "Russian");
    cout << "Введите размер массива : \n";
    cin >> *size;
    cout << "Массив : \n";
    for (int i = 0; i < *size; i++)
    {
        *(A + i) = rand() % 201 - 100;
        cout << *(A + i) << " ";
    }
    cout << endl;
}
int b_type(int* A, int* size)S {
	int btype = 0;
	for (int i = 0; i < *size; i++) {
		if (*(A + i) < 0) {
			btype++;
		}
	}
	return btype;
}
int c_type(int* A, int* size) {
	int ctype = 0;
	for (int i = 0; i < *size; i++) {
		if (*(A + i) > 0) {
			ctype++;
		}
	}
	return ctype;
}
int d_type(int* A, int* size) {
	int dtype = 0;
	for (int i = 0; i < *size; i++) {
		if (*(A + i) == 0) {
			dtype++;
		}
	}
	return dtype;
}
void b_arr(int* A, int* B, int* size, int btype) {
#ifdef ARR
	cout << "Отрицательный массив" << endl;
#endif // ARR
	int nul = 0;
	btype = 0;
	for (int i = 0; i < *size; i++) {
		if (*(A + i) < 0) {
			*(B + btype) = *(A + i);
			nul++;
#ifdef ARR
				cout << *(B + btype) << setw(4);
#endif // ARR
				btype++;
				
		}
	}
	cout << endl;
#ifdef ARR
	if (nul == 0) {

		cout << "Отрицательных значений в массиве нет" << endl;

	}
#endif // ARR
}
void c_arr(int* A, int* C, int* size, int ctype) {
#ifdef ARR		
	cout << "Положительный массив" << endl;
#endif // ARR
	int nul = 0;
	ctype = 0;
	for (int i = 0; i < *size; i++) {
		if (*(A + i) > 0) {
			nul++;
			*(C + ctype) = *(A + i);
#ifdef ARR
				cout << *(C + ctype) << setw(4);
				
#endif // ARR
			ctype++;
		}
	}
	cout << endl;
#ifdef ARR
	if (nul == 0) {

		cout << "Положительных значений в массиве нет" << endl;

	}
#endif // ARR
}
void d_arr(int* A, int* D, int* size, int dtype) {
#ifdef ARR
	cout << "Нулевой массив" << endl;
#endif // ARR
	dtype = 0;
	int nul = 0;
	for (int i = 0; i < *size; i++) {
		if (*(A + i) == 0) {
			*(D + dtype) = *(A + i);
			nul++;
#ifdef ARR
				cout << *(D + dtype) << setw(4);
#endif // ARR
			dtype++;
		}
	}
	cout << endl;
#ifdef ARR
	if (nul == 0) {

		cout << "Нулей в массиве нет" << endl;

	}
#endif // ARR
}
void osn() {
	while (true) {
		int A[M];
		int size;
		zap(A, &size);
#ifdef ARR
		cout << "Вывод всех массивов" << endl;
#endif // ARR
		int btype = b_type(A, &size);
		int ctype = c_type(A, &size);
		int dtype = d_type(A, &size);
		int B[M];
		int C[M];
		int D[M];
		b_arr(A, B, &size, btype);
		c_arr(A, C, &size, ctype);
		d_arr(A, D, &size, dtype);
		cout << endl;
		cout << "Переписанный массив" << endl;
		for (int i = 0; i < dtype; i++) {
			*(A + i) = *(D + i);
		}

		for (int i = dtype, j = 0; i < btype, j < btype; i++, j++) {

			*(A + i) = *(B + j);

		}

		for (int i = dtype + btype, j = 0; i < ctype, j < ctype; i++, j++) {

			*(A + i) = *(C + j);

		}

		for (int i = 0; i < size; i++) {
			cout << *(A + i) << " ";
		}
		cout << endl;

	}
}
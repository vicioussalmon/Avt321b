#include <iostream>
#include <string.h> 
#include <stdio.h> 
#include "Contents.h"
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable : 4996) 
using namespace std;
#define CHANGED //изменение массива относительно ключевого числа
void mix(int* arr, int size, int k) {
    for (int i = k; i < size - 1; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
}
void kluch(int* arr, int size) {
    int n;
    cout << "Введите ключевое число : \n";
    cin >> n;

    cout << "Массив относительно ключевого числа: " << endl;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) > n)
        {
#ifdef CHANGED
            zam((arr + i));
#endif // CHANGED
            cout << *(arr + i) << "\t";
        }
        else
        {
            mix(arr, size, i);
            size -= 1;
            i--;

        }
    }
    cout << endl;
}
void zam(int* num) {
    if (*num > 0)
        *num = 200;
    if (*num < 0)
        *num = 100;

}
void osn() {
    while (true) {
        setlocale(LC_ALL, "Russian");
        int size;
    cout << "Введите размер массива : \n";
    cin >> size;
    int* arr = new int[size];
    cout << "Массив : \n";
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 21 - 10;
        cout << *(arr + i) << " ";
    }
    cout << endl;
        kluch(arr, size);
        delete[]arr;
        arr = nullptr;
    }
}
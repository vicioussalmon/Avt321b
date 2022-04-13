#include <iostream> 
#include <string.h> 
#include <stdio.h> 
#include "Contents.h"
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable : 4996) 
using namespace std;
#define M 100
//#define WRITE_ARRAY //поэтапная демонстрация отсеивания относительно ключевого числа
//#define CHANGED //изменение массива относительно ключевого числа
void zap(int* arr, int* size) {
    setlocale(LC_ALL, "Russian");
    cout << "Введите размер массива : \n";
    cin >> *size;
    cout << "Массив : \n";
    for (int i = 0; i < *size; i++)
    {
        *(arr+i) = rand() % 201 - 100;
        cout << *(arr+i) << " " ;
    }
    cout << endl;
}
void mix(int* arr, int size, int k) {
    for (int i = k; i < size - 1; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
}
void WriteMixedArray(int* size, int* arr)
{
    cout << "\nNew Array:\n";
    for (int i = 0; i < *size; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << "\n";
}
void kluch(int* arr, int* size) {
    int n;
    cout << "Введите ключевое число : \n";
    cin >> n;

    cout << "Массив относительно ключевого числа: " << endl;
    for (int i = 0; i < *size; i++) {
        if (*(arr + i) > n) 
        {
#ifdef CHANGED
            zam((arr + i));
#endif // CHANGED
            cout << *(arr + i) << "\t";
        }
        else
        {
            mix(arr, *size, i);
            *size -= 1;
            i--;

#ifdef WRITE_ARRAY
            WriteMixedArray(size, arr);
#endif // WRITE_ARRAY

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
    int arr[M];
    int size;
    while (true) {
        zap(arr, &size);
        kluch(arr, &size);
    }
}
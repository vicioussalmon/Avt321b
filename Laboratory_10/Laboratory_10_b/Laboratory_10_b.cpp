#include <stdio.h>
#include <conio.h> 
#pragma warning(disable : 4996)
#include <iostream>
#include <iomanip>
#define size 100
using namespace std;

void FillPrintArr(int arr[size][size], const int n, const int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 10 - 5;
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
}

int positive(int arr[size][size], int n, int m);

int main() {
    const int n = 3;
    const int m = 4;

    int arr[size][size];
    FillPrintArr(arr, n, m);
    while (true) {
        int c;
        cout << "В какой строке хотите провести исследование на положительные числа?";
        cin >> c;
        if (c > 0 && c < n) {
            /*cout << "Количество положительных: " << positive(arr, c, m);*/
        }
        else
            cout << "В данном массиве нету столько строк";
    }



    return 0;
}

int positive(int arr[size][size], int c, int m) {
    int s = 0;
    for (int j = 0; j < m; j++) {
        if (arr[c - 1][j] >= 0) {
            cout << arr[c - 1][j];
            s++;
        }
        cout << endl;
    }
    return s;
}
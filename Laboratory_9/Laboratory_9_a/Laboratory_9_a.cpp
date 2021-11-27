#include <iostream>
#include <windows.h>
using namespace std;
#pragma warning(disable : 4996)
#include<iomanip>
#define M 5

int main()

{
    setlocale(LC_ALL, "Russian");

    int Ar[M][M];
    int MS[M][M];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            Ar[i][j] = rand() % 10 + 1;
            MS[i][j] = Ar[i][j];
            cout << setw(4) << Ar[i][j];
        }
        cout << endl;
    }
    int max = 0;
    int temp = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Ar[i][j] >= Ar[i][max])
                max = j;

        }
        cout << "Максимальное значение в строке:" << Ar[i][max] << endl;

        temp = Ar[i][0];
        Ar[i][0] = Ar[i][max];
        Ar[i][max] = temp;
        max = 0;
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << setw(4) << Ar[i][j];
        }
        cout << endl;
    }
    cout << "Исходный массив:\n";
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << setw(4) << MS[i][j];
        }
        cout << endl;
    }
    int min = 0;
    int change = 0;
    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < M; i++) {
            if (MS[i][j] <= MS[min][j])
                min = i;
        }
        cout << "Минимальное значение столбца:" << MS[min][j] << endl;
        change = MS[M - 1][j];
        MS[M - 1][j] = MS[min][j];
        MS[min][j] = change;
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << setw(4) << MS[i][j];
        }
        cout << endl;
    }

    return 0;
}
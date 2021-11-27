#include <iostream>
#include <windows.h>
using namespace std;
#pragma warning(disable : 4996)
#include<iomanip>
#define M 5

int main()

{
    setlocale(LC_ALL, "Russian");
    int razmerstr = 0;
    int razmerstolb = 0;
    int Ar[M][M];
    int Ms[M][M];
    cout << "Введите количество строк матрицы 1" << endl;
    cin >> razmerstr;
    cout << "Введите количество столбцов матрицы 1" << endl;
    cin >> razmerstolb;
    int sizerow = 0;
    int sizecol = 0;
    cout << "Введите количество строк матрицы 2" << endl;
    cin >> sizerow;
    cout << "Введите количество столбцов матрицы 2" << endl;
    cin >> sizecol;

    while (razmerstr != sizecol or razmerstolb != sizerow) {
        cout << "Такое перемножение матриц невозможно" << endl << "Попытайтесь еще" << endl;
        cout << "Введите количество строк матрицы 1" << endl;
        cin >> razmerstr;
        cout << "Введите количество столбцов матрицы 1" << endl;
        cin >> razmerstolb;
        cout << "Введите количество строк матрицы 2" << endl;
        cin >> sizerow;
        cout << "Введите количество столбцов матрицы 2" << endl;
        cin >> sizecol;
    }
    cout << "Ваши матрицы:" << endl;
    for (int i = 0; i < razmerstr; i++)
    {
        for (int j = 0; j < razmerstolb; j++)
        {


            Ar[i][j] = rand() % 15;
            cout << setw(4) << Ar[i][j];
        }
        cout << endl;
    }
    cout << "\n\n";
    for (int i = 0; i < sizerow; i++)
    {
        for (int j = 0; j < sizecol; j++)
        {
            Ms[i][j] = rand() % 15;
            cout << setw(4) << Ms[i][j];
        }
        cout << endl;
    }
    cout << "\n\n";
    int proizv = 0;
    int sum = 0;
    int umn = 0;
    int sloz = 0;
    int mass[M][M];
    if (razmerstr == sizecol or razmerstolb == sizerow) {
        for (int k = 0; k < razmerstr; k++)
            for (int i = 0; i < razmerstr; i++)
            {
                sum = 0;
                for (int j = 0; j < sizerow; j++) {

                    proizv = Ar[k][j] * Ms[j][i];
                    sum += proizv;
                    mass[k][i] = sum;
                    cout << "Результат перемножения:" << proizv << endl;
                    cout << "Результат сложения:" << sum << endl;

                }
            }
    }
    cout << "Ваши перемноженные матрицы:" << endl;
    for (int k = 0; k < razmerstr; k++)
    {
        for (int i = 0; i < sizecol; i++)
        {
            cout << setw(4) << mass[k][i];
        }
        cout << endl;
    }
}
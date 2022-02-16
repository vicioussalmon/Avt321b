#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;
void show(int mas[], int kol)
{
    if (kol == 0)
        cout << mas[kol] << " ";
    else
    {
        cout << mas[kol] << " ";
        show(mas, --kol);
    }
}

void main(void)
{
    setlocale(LC_ALL, "rus");
    const int n = 5;
    int mas[n];
    while (true) {
        cout << "Введите массив\n";
        cout << "Массив рассчитан на " << n << " эл-тов" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Введите эл-т №[" << i + 1 << "]: ";
            cin >> mas[i];
        }

        cout << "\nВывод заданного массива в обратном порядке: ";
        show(mas, n - 1);
        cout << endl;
    }
}
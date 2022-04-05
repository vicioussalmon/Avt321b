#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;
const int n = 5;
int mas[n];
int j = n;
int k;
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
void in() {

    if (j > 1) {
        j = j - 1;
        in();
    }
    cout << "Введите эл-т №[" << k + 1 << "]: ";
    cin >> mas[k];
    k = k + 1;
}
void pin()
{
    cout << "Введите массив\n";
    cout << "Массив рассчитан на " << n << " эл-тов" << endl;
    k = 0;
    in();
    cout << "\nВывод заданного массива в обратном порядке: ";
    show(mas, n - 1);
    cout << endl;
    j = n;

}
void main(void)
{
    setlocale(LC_ALL, "rus");
    pin();
}
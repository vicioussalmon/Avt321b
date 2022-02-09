#include <iostream>
using namespace std;
const int n = 100;
int main()
{
    int i = 0, arr[n];
    setlocale(LC_ALL, "rus");
    cout << "Введите последовательность чисел:";
    do
    {
        cin >> arr[i++];

    } 
    while (arr[i - 1] != 0);
    int size = i;
    cout << "В обратном порядке:";
    for (int i = size - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    };
    system("pause>>void");
    return 0;
}
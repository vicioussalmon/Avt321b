#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int num;
    int reverse = 0;
    int sum = 0;
    int array_size = 0;
    int hash;
    cout << "Введите свое число: ";
    cin >> num;
    hash = num;
    do {
        hash /= 10;
        array_size++;
    } while (hash > 0);
    /*int* array = new int[array_size];*/
    int i = 0;
    for (i = 0; i < array_size; i++) {
        array[i] = (num % 10);
        reverse = reverse * 10 + array[i];
        num /= 10;
        sum += array[i];
    }
    cout << "Число наоборот: " << reverse;
    cout << endl;
    cout << "Сумма: " << sum << endl;
    cout << "Всего чисел: " << i << endl;
    return 0;
}
#include <iostream>
using namespace std;
# define n 100;
void sort(int arr[], int size)
{ for (int i = size - 1; i >= 0; i--)
{
    cout << arr[i] << " ";
};
}
int main()
{
    int i = 0, arr[100];
    setlocale(LC_ALL, "rus");
    cout << "Введите последовательность чисел:";
    do
    {
        cin >> arr[i++];

    }
    while (arr[i - 1] != 0);
    int size = i;
    cout << "В обратном порядке:";
    sort(arr, size);
    return 0;
}
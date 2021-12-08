#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
using namespace std;
#define M 100


int array_print(int arr[M][M], int razm_str, int razm_stol) {

    for (int i = 0; i < razm_str; i++) {
        for (int j = 0; j < razm_stol; j++) {
            arr[i][j] = rand() % 10 - 5;
            cout << setw(3) << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}

int positive(int arr[M][M], int vibor, int razm_stol) {
    int sum = 0;
    cout << "Позитивные числа:" << endl;
    for (int j = 0; j < razm_stol; j++) {

        if (arr[vibor - 1][j] >= 0) {
            cout << setw(3) << arr[vibor - 1][j];
            sum++;
        }
    } cout << endl;
    return sum;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    // 2D array 
    int matrix[M][M];
    cout << "Создадим двумерный массив:" << endl;
    int razm_str, razm_stol;
    cout << "Введите количество строк в нем ";
    cin >> razm_str;
    cout << "Введите количество столбцов в нем ";
    cin >> razm_stol;


    array_print(matrix, razm_str, razm_stol);

    while (true) {

        int vibor;
        cout << "Выберите строку, в которой будем искать положительные числа ";
        cin >> vibor;


        if (vibor > 0 && vibor <= razm_str) {
            cout << "Количество позитивных чисел: " << positive(matrix, vibor, razm_str) << endl;
        }
        else
            cout << "Этой строки не существует" << endl;
    }

    return 0;
}
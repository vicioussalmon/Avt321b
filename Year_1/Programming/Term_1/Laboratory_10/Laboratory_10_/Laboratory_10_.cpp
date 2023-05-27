#include <iostream>
#include <iomanip>
#define M 3
#define N 3
#pragma warning(disable : 4996)
using namespace std;
void Fun(int mas1[])
{
    setlocale(LC_ALL, "Russian");
    int mas2[N][M];
    int mas3[M][N];
    cout << "\nПечать ДМ из ОМ:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mas2[i][j] = mas1[i * M + j];
            cout << mas2[i][j] << " ";
        }
        cout << endl;
    }
  // транспонируем-с
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            mas3[j][i] = mas2[i][j];
        }
    }
    
    cout << "\nПечать ДМ транспонированого:\n";
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            
            cout << mas3[j][i] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            mas1[i * M + j] = mas3[i][j];
        }
        cout << endl;
    }
    
 }

int main()
{
    setlocale(LC_ALL, "Russian");
    int mas1[N * M] = {4, 9, 8, 6, 4, 8, 5, 3, 2 };
    cout << "Одномерный массив:\n";
    for (int i = 0; i < N * M; i++)
        cout << setw(4) << mas1[i];
    cout << endl;
    Fun(mas1);
    cout << "\nОдномерный итоговый массив:\n";
    for (int i = 0; i < N * M; i++)
        cout << setw(4) << mas1[i];
    cout << endl;
}
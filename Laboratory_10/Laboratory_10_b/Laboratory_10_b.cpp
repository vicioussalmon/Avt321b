#include <stdio.h>
#include <conio.h> 
#include <iostream>
#include <iomanip>
#define M 4
#define N 4
#pragma warning(disable : 4996)

using namespace std;
void zap(int mas2[][M], int mas1[])
{
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			mas2[i][j] = rand() % 5 + 1;
			/*cout << setw(4) << mas1[i][j];*/
		}
	}
		cout << endl;
}
 void print(int mas2[][M], int mas1[]){
  int a;
  cout << "Введите номер строки:" << endl;
  cin >> a;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << mas2[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < M; i++)
		{
			mas1[i] = a;
			cout << mas1[i];
		}
}
int pol(int mas2[][M], int mas1[]) 
{
	int j;
	for  (int j = 0; j < N; j++) {
		for (int i = 0; i < M; i++) {
			if (mas1[i] > 0)
				return mas1[i];
			
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int mas1[M];
	int mas2[N][M];
	int i;
	zap(mas2, mas1);
	print(mas2, mas1);
	pol(mas2, mas1);
	cout << "Положительные в " << i << " строке " << pol << endl;
	/*return;*/
}
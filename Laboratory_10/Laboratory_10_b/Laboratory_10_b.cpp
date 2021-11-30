#include <stdio.h>
#include <conio.h> 
#include <iostream>
#include <iomanip>
#define M 4
#define N 3
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
	void print(int mas2[][M], int mas1[])
{
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << mas2[i][j] << " ";
			}
			cout << endl;
		}
}
void pol(int mas2[][M], int mas1[]) {
	int j;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (M[j] > 0);
			cout << "Положительные в " << i << " строке " << M[j] << endl;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int mas1[M];
	int mas2[N][M];
	zap(mas2, mas1);
	print(mas2, mas1);
	pol(mas2, mas1);
	
	/*return;*/
}
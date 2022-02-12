#include <iostream>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define M 3
#pragma warning(disable : 4996)
using namespace std;
struct mon {
	char name[15]; /* название */
	char sc;       /* группа */
	int cnt;       /* место обитания */
	float sq;      /* численность */
} /*mm[10]*/;
void input(mon mm[]) {
	int n = M; //количество элементов в массиве
	int i, j;// текущие индексы в массиве
	int m;//индекс минимального элемента
	float sqx;//рабочая переменная
	for (n = 0; n < M; n++)
	{
		printf("%d. Введите: название, группу, место обитания, численность >",
			n + 1);
		scanf_s("%s", mm[n].name, sizeof(mm[n].name));
		if (!strcmp(mm[n].name, "***")) break;
		scanf_s("%c", &mm[n].sc, sizeof(mm[n].name));
		scanf_s("%s", &mm[n].cnt);
		//обходим ошибку в системе программирования
		scanf_s("%i", &mm[n].sq);//mm[n].sq = sqx;
	}
}
void print(mon mm[]) {

	int n = M; //количество элементов в массиве
	int i, j;// текущие индексы в массиве
	int m;//индекс минимального элемента
	struct mon x;//рабочая переменная
	printf("-----------------------------------------------\n");
	printf("|         Некоторые виды антилоп              |\n");
	printf("|---------------------------------------------|\n");
	printf("| Название | Группа |   Место  | Численность  |\n");
	printf("|          |        | обитания |  популяции   |\n");
	printf("|----------|--------|----------|--------------|\n");
	for (i = 0; i < n; i++)
	{
		printf("|%-10s|%-8c|%-10s|%-14d|\n",
			mm[i].name, mm[i].sc, mm[i].cnt, mm[i].sq);
	}
	printf("|---------------------------------------------|\n");


}
void sort(mon mm[]) {
	int m;
	int n = M;
	struct mon x;
	for (int i = 0; i < n - 1; i++) {
		m = i; /* минимальный элемент - первый */
		for (int j = i + 1; j < n; j++)
			/* если текущий элемент > минимального,
			   он становится минимальным */
			if (strcmp(mm[m].name, mm[j].name) > 0) m = j;
		if (m > i) {

			x = mm[i];
			mm[i] = mm[m];
			mm[m] = x;
		}
	}
}
void random(mon mm[]) {
	for (int n = 0; n < M; n++) {
		printf("%d. Введите название>", n + 1);
		scanf_s("%s", mm[n].name, sizeof(mm[n].name));
	}
		char letters[3] = { 'A', 'B' ,'H' };
		for (int i = 0; i < 3; i++)
		{
			mm[i].cnt = rand() % 40 + (40 * (2 - i));
			mm[i].sc = letters[i % 3];
			mm[i].sq = i + 1;
		}

		mm[10] = mm[2];
		mm[2] = mm[0];
		mm[0] = mm[10];
	
}
int main(void)
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	int n = 3;
	float sqx;
	mon mm[M];
	while (true) {
		for (int i = 0; i < 1; i++)
		{
			cout << "Выберите действие (Ввод с экрана - 1/Заполнение случайным образом - 2/Сортировка - 3/Печать - 4):" << endl;
			cin >> choice;
			if (choice == 1) {
				input(mm);
			}
			else if (choice == 2) {
				random(mm);
			}
			else if (choice == 3) {
				sort(mm);
			}
			else if (choice == 4) {
				print(mm);
			}
		}
	}
	return 0;
}
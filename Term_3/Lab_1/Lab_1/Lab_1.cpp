#include "Header.h"
#include <iostream>
#define N 3

int main()
{
	setlocale(LC_ALL, "Russian");
	char* n;
	char t;
	unsigned int s;
	float h;
	short i;

	church obj[N];
	system("cls");
	cout << "Работа функции SET!\n";
	for (i = 0; i < N; i++)
	{
		cout << "Название	Группа	Место обитания	Численность популяции: ";
		cin >> n;
		cin >> t;
		cin >> s;
		cin >> h;
		obj[i].set(n, t, s, h);
	}
	cout << "Работа функции SHOW!\n";
	cout << "Название	Группа	Место обитания	Численность популяции: \n";
	for (i = 0; i < N; i++)
	{
		obj[i].show();
		cout << "\n";
	}
	cout << "Работа функции GET и SHOW!\n";
	cout << "Название	Группа	Место обитания	Численность популяции: \n";
	for (i = 0; i < N; i++)
	{
		obj[i].get(n, t, s, h);
		obj[i].show();
		cout << "\n";
	}
	_getch();
	delete[] n;
	return 0;
}
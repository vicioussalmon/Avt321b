﻿// Laboratory_4_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#pragma warning(disable : 4996)
int main(void) {
	setlocale(LC_ALL, "Russian");
	int n; /* номер головки */
	int t; /* номер дорожки */
	int s; /* номер сектора */
	unsigned int UnitStateWord; /* слово состояния */
	/* ввод слова состояния устройства */
	printf("Введите cлово состояния устройства \n");
	printf("(16-ричное число от 0 до 0xFFFF) >");
	scanf("%x", &UnitStateWord);
	/* Выделение составных частей */
	n = (UnitStateWord >> 14) & 0x3;
	t = (UnitStateWord >> 5) & 0x1FF;
	s = UnitStateWord & 0x1F;
	/* вывод результатов */
	putchar('\n');
	printf("Hомер головки= %d\n", n);
	printf("Hомер дорожки= %d\n", t);
	printf("Hомер сектора= %d\n", s);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

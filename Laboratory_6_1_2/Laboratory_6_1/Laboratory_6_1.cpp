﻿// Laboratory_6_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <time.h>
#include <iostream>
#pragma warning(disable : 4996)

int main(void) {
	setlocale(LC_ALL, "Russian");

	srand(time(0));
	int num = rand() % 100;

	int k = 0;
	int num2 = 0;
	printf("Отгадайте число от 0 до 100\n");
	while (num2 != num)
	{
		++k;
		printf("Введите ваше значениe ");
		scanf("%d", &num2);
		if(num > num2)
			printf("Загаданное число больше вашего\n");
		else if (num < num2)
			printf("Загаданное число меньше вашего\n");
	}
	printf("Вы угадали за"" %d ""попыток\n", k);
	printf("\n\n\n");
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

// Laboratory_6_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <math.h>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));//случайные значения
	int answer;
	int counttrue = 0;//кол-во правильных
	int i = 0;//кол-во примеров
	
	for (i; i < 10; i++) //кол-во примеров
	{
		int a = rand() % 10 + 1; // числа от 0 до 9 и добавляет 1, получаем числа от 1го до 10
		int b = rand() % 10 + 1;
		answer = a * b;
		cout << a << "*" << b << "=" << endl;
		cin >> answer;
		if (answer == a * b)
		{
			counttrue = counttrue + 1;
		}
		else if (answer != a * b)
		{
			counttrue = counttrue + 0;
		}
		
	}
	cout << "Количество правильных ответов" << endl << counttrue << endl;

	 if (counttrue == 0)

	cout << "Ваша оценка" << endl << "0" << endl << "УЧИТЬ НАДО БЫЛО" << endl;

	else if (counttrue == i)

		cout << "Ваша оценка" << endl << "5" << endl;

	else if (counttrue == (i * 80) / 100)

		 cout << "Ваша оценка" << endl << "4" << endl;

	else if (counttrue == (i * 60) / 100)
	
		cout << "Ваша оценка" << endl << "3" << endl;
	
	else if (counttrue == (i * 40)/100)
	
		cout << "Ваша оценка" << endl << "2" << endl;
	
	else if (counttrue == (i * 20)/100)
	
		cout << "Ваша оценка" << endl << "1" << endl; 
	
	else if (counttrue == (i * 10) / 100)

		 cout << "Ваша оценка" << endl << "0,5" << endl;
	
	return 0;
}

// 
// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

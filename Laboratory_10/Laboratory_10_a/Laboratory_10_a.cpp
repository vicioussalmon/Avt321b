#include <stdio.h>
#include <conio.h> 
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
char f(int a, int b)
{
	
	if (a > b)return '>';
	if (a < b)return  '<';
	return  '=';
}

int main() {
	setlocale(LC_ALL, "Russian");
	int a;
	int b;
	cout << "Введите а и b" << endl;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << a << f(a, b) << b;
	getch();
	return 0;
}
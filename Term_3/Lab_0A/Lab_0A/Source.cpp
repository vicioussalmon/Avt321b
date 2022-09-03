#include "Header.h"
void foo(int a = 5, int b = 7) {
	int answer;
	int S;
	cout << "Оберіть фігуру, площу якої маємо знайти" << endl;
	cout << "Прямокутник(1)/Квадрат(2)" << endl;
	cin >> answer;
	if (answer == 1)
	{
		cout << "Площа прямокутника:" << endl;
		S = a * b;
		cout << S << endl;
	}
	if (answer == 2)
	{
		cout << "Площа квадрата:" << endl;
		S = a * a;
		cout << S << endl;
	}
	if (answer <1 ||answer > 2) {
		cout << "Упс! Такой функції немає, спробуйте ще раз..." << endl;
	}
}
void osn() {
	setlocale(LC_CTYPE, "ukr");
	while (true) {
		foo();
	}
}
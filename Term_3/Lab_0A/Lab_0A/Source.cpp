#include "Header.h"
void sq(int a = 0, int b = 0) {
	if (a > 0 and b == 0) { 
		a = a * a;
		cout << "Площа квадрата: " << a << endl;
	}

	else  {
		a = a * b;
		cout << "Площа прямокутника: " << a << endl;
	}
}
void osn() {
	setlocale(LC_CTYPE, "ukr");
	while (true) {
		int answer;
		int a, b;
		cout << "---------------------------------------" << endl;
		cout << "Оберіть фігуру, площу якої маємо знайти" << endl;
		cout << "Прямокутник(1)" << endl;
		cout << "Квадрат(2)" << endl;
		cout << "Вихід(3)" << endl;
		cout << "---------------------------------------" << endl;
		cin >> answer;
		switch (answer) {
		case 1:
			cout << "Уведіть сторони прямокутника:" << endl;
			cin >> a;
			cin >> b;
			if (a < 0 || b < 0) {
				cout << "Помилка..." << endl;
				break;
			}
			sq(a, b);
			break;
		case 2:
			cout << "Уведіть сторону квадрата:" << endl;
			cin >> a;
			if (a < 0)
			{
				cout << "Помилка..." << endl;
				break;
			}
			sq(a);
			break;
		case 3:
			exit(0);
			if (answer < 1 || answer > 3) {
				cout << "Упс! Такой функції немає, спробуйте ще раз..." << endl;
			}
		}
	}
}
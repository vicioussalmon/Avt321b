#include "Header.h"
void foo(int a = 5, int b = 7) {
	int answer;
	int S;
	cout << "������ ������, ����� ��� ���� ������" << endl;
	cout << "�����������(1)/�������(2)" << endl;
	cin >> answer;
	if (answer == 1)
	{
		cout << "����� ������������:" << endl;
		S = a * b;
		cout << S << endl;
	}
	if (answer == 2)
	{
		cout << "����� ��������:" << endl;
		S = a * a;
		cout << S << endl;
	}
	if (answer <1 ||answer > 2) {
		cout << "���! ����� ������� ����, ��������� �� ���..." << endl;
	}
}
void osn() {
	setlocale(LC_CTYPE, "ukr");
	while (true) {
		foo();
	}
}
#include "Header.h"
void sq(int a = 0, int b = 0) {
	if (a > 0 and b == 0) { 
		a = a * a;
		cout << "����� ��������: " << a << endl;
	}

	else  {
		a = a * b;
		cout << "����� ������������: " << a << endl;
	}
}
void osn() {
	setlocale(LC_CTYPE, "ukr");
	while (true) {
		int answer;
		int a, b;
		cout << "---------------------------------------" << endl;
		cout << "������ ������, ����� ��� ���� ������" << endl;
		cout << "�����������(1)" << endl;
		cout << "�������(2)" << endl;
		cout << "�����(3)" << endl;
		cout << "---------------------------------------" << endl;
		cin >> answer;
		switch (answer) {
		case 1:
			cout << "������ ������� ������������:" << endl;
			cin >> a;
			cin >> b;
			if (a < 0 || b < 0) {
				cout << "�������..." << endl;
				break;
			}
			sq(a, b);
			break;
		case 2:
			cout << "������ ������� ��������:" << endl;
			cin >> a;
			if (a < 0)
			{
				cout << "�������..." << endl;
				break;
			}
			sq(a);
			break;
		case 3:
			exit(0);
			if (answer < 1 || answer > 3) {
				cout << "���! ����� ������� ����, ��������� �� ���..." << endl;
			}
		}
	}
}
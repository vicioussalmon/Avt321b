#include "Header.h"
Antilops::Antilops() {
	name = "���";
	group = '�';
	areal = "������";
	population = 0;
}
void random(Antilops antilop[]) {
	const char* names[3] = { "�������", "���", "�����" };
	char groups[3] = { '�', '�', '�' };
	const char* areals[2] = { "����","������" };
	for (int i = 0; i < M; i++) {
		antilop[i].name = names[rand() % 3];
		antilop[i].group = groups[rand() % 3];
		antilop[i].areal = areals[rand() % 2];
		antilop[i].population = rand() % 1000 + 1000000;
	}
}
void Antilops::print_tabl() {
	cout << setw(4) << "-----------------------------------------------\n";
	cout << setw(4) << "|             ��������� ���� �������          |\n";
	cout << setw(4) << "|---------------------------------------------|\n";
	cout << setw(4) << "|  ��������  | ������ |   �����   |�����������|\n";
	cout << setw(4) << "|---------------------------------------------|\n";
}
void print_obj(Antilops antilop[]) {

	for (int i = 0; i < M; i++) {
		antilop[i].ShowAll();
		cout << "|\n";
		cout << "|---------------------------------------------|" << "\n";
	}
}
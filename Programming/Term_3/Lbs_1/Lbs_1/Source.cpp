#include "Header.h"
Antilops::Antilops() {
	name = "Гну";
	group = 'А';
	areal = "Африка";
	population = 0;
}
void random(Antilops antilop[]) {
	const char* names[3] = { "Джейран", "Гну", "Бейза" };
	char groups[3] = { 'А', 'В', 'Н' };
	const char* areals[2] = { "Азия","Африка" };
	for (int i = 0; i < M; i++) {
		antilop[i].name = names[rand() % 3];
		antilop[i].group = groups[rand() % 3];
		antilop[i].areal = areals[rand() % 2];
		antilop[i].population = rand() % 1000 + 1000000;
	}
}
void Antilops::print_tabl() {
	cout << setw(4) << "-----------------------------------------------\n";
	cout << setw(4) << "|             Некоторые виды антилоп          |\n";
	cout << setw(4) << "|---------------------------------------------|\n";
	cout << setw(4) << "|  Название  | Группа |   Ареал   |Численность|\n";
	cout << setw(4) << "|---------------------------------------------|\n";
}
void print_obj(Antilops antilop[]) {

	for (int i = 0; i < M; i++) {
		antilop[i].ShowAll();
		cout << "|\n";
		cout << "|---------------------------------------------|" << "\n";
	}
}
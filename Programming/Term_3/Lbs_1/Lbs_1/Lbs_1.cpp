#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	Antilops antilop[M];

	antilop->print_tabl();
	random(antilop);
	print_obj(antilop);

}

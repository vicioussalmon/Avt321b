#include "simplex_method.h"
#include <Windows.h>
int main()
{
	setlocale(LC_ALL, "ukr");
	simplex* ud = new simplex;
	ud->get_data_from_user();
	ud->init();
	ud->gen_plane();
	return 0;
}

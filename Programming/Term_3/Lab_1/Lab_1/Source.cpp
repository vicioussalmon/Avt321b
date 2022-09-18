#include "Header.h"
//#include <stdlib.h>
//#include <conio.h>
//#include <string.h>
//#include <stdio.h>
#pragma warning(disable : 4996)
void church::set(char* a, char b, unsigned int c, float d) {
	strcpy(name, a);
	school = b;
	count = c;
	square = d;
}

void church::get(char* a, char& b, unsigned int& c, float& d)
{
	delete[] a;
	a = new char[strlen(name) + 1];
	strcpy(a, name);
	b = school;
	c = count;
	d = square;
}

void church::show(void) {
	cout << name << " ";
	cout << school << " ";
	cout << count << " ";
	cout << square << " ";
}

#pragma once
#include <iostream>
#include <Windows.h>
#include <iomanip>
#pragma warning (disable: 4996)
#define M 3
using namespace std;
class Antilops {
private:
	string name;
	char group;
	string areal;
	long int population;
public:
	Antilops();
	friend void random(Antilops antilop[]);
	void print_tabl();
	friend void print_obj(Antilops antilop[]);
};
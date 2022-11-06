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
	void SetAll(string& name, char& group, string& areal, long int& population) {
		name; group; areal; population;
	}
	string GetNamenAreal() { return name, areal;}
	char GetGroup() { return group;}
	long int GetPopulation() { return population; }
	void ShowAll() {
		cout << "|" << setw(10) << this->name << setw(4);
		cout << "|" << setw(4) << this->group << setw(4);
		cout << "|" << setw(6) << this->areal << setw(6);
		cout << "|" << setw(3) << this->population << setw(6);
	}
	friend void random(Antilops antilop[]);
	void print_tabl();
	friend void print_obj(Antilops antilop[]);
};
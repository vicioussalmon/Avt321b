#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

class Triangle {
public:
	int Side1;
	int Side2;
	int Side3;

	Triangle() {
		this->Side1 = 0;
		this->Side2 = 0;
		this->Side3 = 0;
	}
	Triangle(int Side1, int Side2, int Side3) {
		this->Side1 = Side1;
		this->Side2 = Side2;
		this->Side3 = Side3;
	}

	string ToString() {
		return string("(Triangle){\n") +
			"    Side1: " + to_string(Side1) + "\n" +
			"    Side2: " + to_string(Side2) + "\n" +
			"    Side3: " + to_string(Side3) + "\n" +
			"    Perimeter: " + to_string(Perimeter()) + "\n" +
			"}";
	}

	double Perimeter() {
		return Side1 + Side2 + Side3;
	}

	bool operator>(Triangle b) {
		return Perimeter() > b.Perimeter();
	}
	bool operator<(Triangle b) {
		return Perimeter() < b.Perimeter();
	}
	bool operator==(Triangle b) {
		return Side1 == b.Side1 && Side2 == b.Side2 && Side3 == b.Side3;
	}
	Triangle operator+(Triangle b) {
		return Triangle(Side1 + b.Side1, Side2 + b.Side2, Side3 + b.Side3);
	}
	Triangle operator*(Triangle b) {
		return Triangle(Side1 * b.Side1, Side2 * b.Side2, Side3 * b.Side3);
	}
	Triangle operator/(int b) {
		return Triangle(Side1 / b, Side2 / b, Side3 / b);
	}
	int operator%(int b) {
		return fmod(Perimeter(), b);
	}
};

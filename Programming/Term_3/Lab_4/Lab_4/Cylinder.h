#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "Triangle.h"
using namespace std;


class Cylinder {
public:
	int Radius;
	int Height;

	Cylinder() {
		this->Radius = 0;
		this->Height = 0;
	}
	Cylinder(double radius, double height) {
		this->Radius = radius;
		this->Height = height;
	}

	string ToString() {
		return string("(Cylinder){\n") +
			"    Radius: " + to_string(Radius) + "\n" +
			"    Height: " + to_string(Height) + "\n" +
			"    Square: " + to_string(Perimeter()) + "\n" +
			"}";
	}

	double Perimeter() {
		double a = max(Radius, Height);
		double b = min(Radius, Height);
		return 2.0 * M_PI * b * (a + b);
	}

	bool operator>(Cylinder b) {
		return Perimeter() > b.Perimeter();
	}
	bool operator<(Cylinder b) {
		return Perimeter() < b.Perimeter();
	}
	bool operator==(Cylinder b) {
		return Radius == b.Radius && Height == b.Height;
	}
	Cylinder operator+(Cylinder b) {
		return Cylinder(Radius + b.Radius, Height + b.Height);
	}
	Cylinder operator*(Cylinder b) {
		return Cylinder(Radius * b.Radius, Height * b.Height);
	}
	Cylinder operator/(double b) {
		return Cylinder(Radius / b, Height / b);
	}
	double operator%(double b) {
		return fmod(Perimeter(), b);
	}
};

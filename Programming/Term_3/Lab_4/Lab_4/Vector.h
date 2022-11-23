#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

class Vector {
public:
	int x;
	int y;
	int z;

	Vector() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	Vector(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	string ToString() {
		return string("(Vector){\n") +
			"    X: " + to_string(x) + "\n" +
			"    Y: " + to_string(y) + "\n" +
			"    Z: " + to_string(z) + "\n" +
			"    Sum of coordinates: " + to_string(Perimeter()) + "\n" +
			"}";
	}
	
	double Perimeter() {
		return x + y + z;
	}

	bool operator>(Vector b) {
		return Perimeter() > b.Perimeter();
	}
	bool operator<(Vector b) {
		return Perimeter() < b.Perimeter();
	}
	bool operator==(Vector b) {
		return x == b.x && y == b.y && z == b.z;
	}
	Vector operator+(Vector b) {
		return Vector(x + b.x, y + b.y, z + b.z);
	}
	Vector operator*(Vector b) {
		return Vector(x * b.x, y * b.y, z * b.z);
	}
	Vector operator/(int b) {
		return Vector(x / b, y / b, z / b);
	}
	int operator%(int b) {
		return fmod(Perimeter(), b);
	}
};

#define _USE_MATH_DEFINES
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "Triangle.h"
#include "Vector.h"
#include "Cylinder.h"
#include "Testing.h"
using namespace std;

Triangle sqrt(Triangle a) {
	return Triangle(sqrt(a.Side1), sqrt(a.Side2), sqrt(a.Side3));
}
Cylinder sqrt(Cylinder a) {
	return Cylinder(sqrt(a.Radius), sqrt(a.Height));
}
Vector sqrt(Vector a) {
	return Vector(sqrt(a.x), sqrt(a.y), sqrt(a.z));
}

Vector RandomVector() {
	return Vector(1 + rand() % 10, 1 + rand() % 10, 1 + rand() % 10);
}

template<typename T>
void Test_1(T a, T b, T c) {
reM:
	system("cls");
	int menu;

	cout << "Test exercise #1" << endl;
	cout << "Arguments for testing" << endl;
	cout << a.ToString() << endl;
	cout << b.ToString() << endl;
	cout << c.ToString() << endl;

	cout << "    1. Max element" << endl;
	cout << "    2. Min element" << endl;
	cout << "    3. Average" << endl;
	cout << "    4. Root mean sqare" << endl;//среднее квадратическое
	cout << "    5. Sum of the arguments" << endl;
	cout << "    6. Product of the arguments" << endl;//произведение 
	cin >> menu;
	system("cls");
	switch (menu) {
	case 1:
		cout << "    1. Max element" << endl;
		cout << Task1<T>::Max(a, b, c).ToString() << endl;
		break;
	case 2:
		cout << "    2. Min element" << endl;
		cout << Task1<T>::Min(a, b, c).ToString() << endl;
		break;
	case 3:
		cout << "    3. Average" << endl;
		cout << Task1<T>::Avg(a, b, c).ToString() << endl;
		break;
	case 4:
		cout << "    4. Root mean sqare" << endl;
		cout << Task1<T>::Avg2(a, b, c).ToString() << endl;
		break;
	case 5:
		cout << "    5. Sum of the arguments" << endl;
		cout << Task1<T>::Sum(a, b, c).ToString() << endl;
		break;
	case 6:
		cout << "    6. Product of the arguments" << endl;
		cout << Task1<T>::Mul(a, b, c).ToString() << endl;
		break;
	default:
		cout << "Wrong meaning!" << endl;
		break;
	}
	system("pause");
	goto reM;
}
template<typename T>
void Test_2(T* array, unsigned int size) {
reM:
	system("cls");
	int menu;
	cout << "Test exercise #2" << endl;
	cout << "Elements of array for testing" << endl;
	cout << "(array){" << endl;
	for (unsigned int i = 0; i < size; i++)
		cout << array[i].ToString() << endl;
	cout << "}" << endl;

	cout << "    1. Max element of array" << endl;
	cout << "    2. Min element of array" << endl;
	cout << "    3. Sum of the arguments of array" << endl;
	cout << "    4. Product of the arguments of array" << endl;//произведение 
	cout << "    5. Average of array" << endl;
	cout << "    6. Root mean sqare of array" << endl;//среднее квадратическое
	cout << "    7. Number of array`s elements, which are divisible by 2 without a remainder" << endl;

	cin >> menu;
	system("cls");
	switch (menu) {
	case 1:
		cout << "    1. Max element of array" << endl;
		cout << Task2<T>::Max(array, size).ToString() << endl;
		break;
	case 2:
		cout << "    2. Min element of array" << endl;
		cout << Task2<T>::Min(array, size).ToString() << endl;
		break;
	case 3:
		cout << "    3. Sum of the arguments of array" << endl;
		cout << Task2<T>::Sum(array, size).ToString() << endl;
		break;
	case 4:
		cout << "    4. Product of the arguments of array" << endl;
		cout << Task2<T>::Mul(array, size).ToString() << endl;
		break;
	case 5:
		cout << "    5. Average of array" << endl;
		cout << Task2<T>::Avg(array, size).ToString() << endl;
		break;
	case 6:
		cout << "    6. Root mean sqare of array" << endl;
		cout << Task2<T>::Avg2(array, size).ToString() << endl;
		break;
	case 7:
		cout << "    7. Number of array`s elements, which are divisible by 2 without a remainder" << endl;
		cout << Task2<T>::Count(array, size) << endl;
		break;
	default:
		cout << "Wrong meaning!" << endl;
		break;
	}
	system("pause");
	goto reM;
}

Triangle RandomTriangle() {
	return Triangle(1 + rand() % 10, 1 + rand() % 10, 1 + rand() % 10);
}
Cylinder RandomCylinder() {
	return Cylinder(1 + rand() % 10, 1 + rand() % 10);
}

Triangle InputTriangle() {
	Triangle obj = Triangle();
	cout << "Input Triangle" << endl;
	cout << "First side: ";
	cin >> obj.Side1;
	cout << "Second side: ";
	cin >> obj.Side2;
	cout << "Third side: ";
	cin >> obj.Side3;
	return obj;
}
Cylinder InputCylinder() {
	Cylinder obj = Cylinder();
	cout << "Input Cylinder" << endl;
	cout << "Radius: ";
	cin >> obj.Radius;
	cout << "Height: ";
	cin >> obj.Height;
	return obj;
}
Vector InputVector() {
	Vector obj = Vector();
	cout << "Input Vector" << endl;
	cout << "First coordinate: ";
	cin >> obj.x;
	cout << "Second coordinate: ";
	cin >> obj.y;
	cout << "Third coordinate: ";
	cin >> obj.z;
	return obj;
}



int main() {
	srand(time(NULL));

reObj:
	int object;
	cout << "Choose the object" << endl;
	cout << "  1 - Triangle" << endl;
	cout << "  2 - Cylinder" << endl;
	cout << "  3 - Vector" << endl;
	cin >> object;
	if (object < 1 || object > 3) {
		cout << "ERROR: Wrong meaning!" << endl;
		goto reObj;
	}
reTask:
	cout << "Choose, how you prefer work with objects" << endl;
	cout << "  1 - Work with three objects" << endl;
	cout << "  2 - Work with array of objects" << endl;
	int task;
	cin >> task;
	if (task < 1 || task > 2) {
		cout << "ERROR: Wrong meaning!" << endl;
		goto reTask;
	}
reInput:
	cout << "Choose the type of inputing" << endl;
	cout << "  1 - Random" << endl;
	cout << "  2 - By the user" << endl;
	int input;
	cin >> input;
	if (task < 1 || task > 2) {
		cout << "ERROR: Wrong meaning!" << endl;
		goto reInput;
	}
	switch (task)
	{
	case 1:
		switch (object) {
		case 1:
			Test_1<Triangle>(input == 1 ? RandomTriangle() : InputTriangle(), input == 1 ? RandomTriangle() : InputTriangle(), input == 1 ? RandomTriangle() : InputTriangle());
			break;
		case 2:
			Test_1<Cylinder>(input == 1 ? RandomCylinder() : InputCylinder(), input == 1 ? RandomCylinder() : InputCylinder(), input == 1 ? RandomCylinder() : InputCylinder());
			break;
		case 3:
			Test_1<Vector>(input == 1 ? RandomVector() : InputVector(), input == 1 ? RandomVector() : InputVector(), input == 1 ? RandomVector() : InputVector());

			break;
		}
		break;
	case 2: {
		unsigned int size;
		if (input == 2) {
			cout << "Input array`s size: ";
			cin >> size;
		}
		else
			size = rand() % (10-1+1)+1;
		switch (object) {
		case 1: {
			Triangle* array = new Triangle[size];
			for (unsigned int i = 0; i < size; i++)
				array[i] = input == 1 ? RandomTriangle() : InputTriangle();
			Test_2<Triangle>(array, size);
		}
			  break;
		case 2: {
			Cylinder* array = new Cylinder[size];
			for (unsigned int i = 0; i < size; i++)
				array[i] = input == 1 ? RandomCylinder() : InputCylinder();
			Test_2<Cylinder>(array, size);
		}
			  break;
		case 3: {
			Vector* array = new Vector[size];
			for (unsigned int i = 0; i < size; i++)
				array[i] = input == 1 ? RandomVector() : InputVector();
			Test_2<Vector>(array, size);
		}
			  break;
		}
		break;
	}
	}
	return 0;
}
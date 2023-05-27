#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "Triangle.h"
#include "Vector.h"
#include "Cylinder.h"
using namespace std;
template <typename T>
class Task1 {
public:
	static T Max(T a, T b, T c) {
		if (a > b && a > c)
			return a;
		if (b > a && b > c)
			return b;
		if (c > a && c > b)
			return c;
		return a;
	}
	static T Min(T a, T b, T c) {
		if (a < b && a < c)
			return a;
		if (b < a && b < c)
			return b;
		if (c < a && c < b)
			return c;
		return a;
	}
	static T Avg(T a, T b, T c) {
		return (a + b + c) / 3;
	}
	static T Avg2(T a, T b, T c) {
		return sqrt((a * a + b * b + c * c) / 3);
	}
	static T Sum(T a, T b, T c) {
		return a + b + c;
	}
	static T Mul(T a, T b, T c) {
		return a * b * c;
	} 
};

template <typename T>
class Task2 {
public:
	static T Max(T* array, unsigned int size) {
		T max;
		for (unsigned int i = 0; i < size; i++)
			if (i == 0)
				max = array[i];
			else if (array[i] > max)
				max = array[i];
		return max;
	}
	static T Min(T* array, unsigned int size) {
		T min;
		for (unsigned int i = 0; i < size; i++)
			if (i == 0)
				min = array[i];
			else if (array[i] < min)
				min = array[i];
		return min;
	}
	static T Sum(T* array, unsigned int size) {
		T sum;
		for (unsigned int i = 0; i < size; i++)
			if (i == 0)
				sum = array[i];
			else
				sum = sum + array[i];
		return sum;
	}
	static T Mul(T* array, unsigned int size) {
		T mul;
		for (unsigned int i = 0; i < size; i++)
			if (i == 0)
				mul = array[i];
			else
				mul = mul * array[i];
		return mul;
	}
	static T Avg(T* array, unsigned int size) {
		return Sum(array, size) / size;
	}
	static T Avg2(T* array, unsigned int size) {
		T sum;
		for (unsigned int i = 0; i < size; i++)
			if (i == 0)
				sum = array[i];
			else
				sum = sum + (array[i] * array[i]);
		return sqrt(sum / size);
	}
	//	Количество элементов, которые делятся на 2 без остатка
	static unsigned int Count(T* array, unsigned int size) {
		unsigned int result = 0;
		for (unsigned int i = 0; i < size; i++)
			if (array[i] % 2 == 0)
				result++;
		return result;
	}
};

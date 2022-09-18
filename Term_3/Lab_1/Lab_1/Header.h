#pragma once
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#define N 3
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class church {
	char* name;
	char school;
	unsigned int count;
	float square;
public:
	void set(char* a, char b, unsigned int c, float d);
	void get(char* a, char& b, unsigned int& c, float& d);
	void show(void);
};
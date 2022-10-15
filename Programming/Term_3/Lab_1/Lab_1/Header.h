#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#define  M 5
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Student {
private:
	string FullName;
	int birthdate;
	string address;
	short int course;
	string fakultat;
	long tel_num;
public:
	Student();
	friend void random(Student students[]);
	friend void print_obj(Student students[]);
};
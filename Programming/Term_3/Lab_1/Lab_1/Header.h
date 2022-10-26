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
	string Name;
	string initial;
	string initial2;
	int birthdate;
	int birthmonth;
	int birthyear;
	string address;
	int course;
	string fakultat;
	int tel_num;
public:
	Student();
	friend void random(Student*& students, int n);
	friend void del(Student*& students, int& n);
	friend void add(Student*& students, int& n);
	friend void individum(Student* &students, int n);
	friend void PrintFakultet(Student* &students, int n);
	friend void print_obj(Student* &students, int &n);
};

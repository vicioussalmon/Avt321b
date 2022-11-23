#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifdef FUNC_EXPORTS
#define FUNC_API __declspec(dllexport)
#else
#define FUNC_API __declspec(dllimport)
#endif

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
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

	void SetAll(const string& FullName, const int& birthdate, const int& birthmonth, const int& birthyear, const string& address, const int& course, const string& fakultat, const int& tel_num) {
		this->FullName;
		this->birthdate;
		this->birthmonth;
		this->birthyear;
		this->address;
		this->course;
		this->fakultat;
		this->tel_num;
	}

	string GetFullName() const { return this->FullName; } string GetAddress() const { return this->address; } string GetFakultat() const { return this->fakultat; }
	int GetBirthdate() const { return this->birthdate; } int GetBirthmonth()const { return this->birthmonth; } int GetBirthyear() const { return this->birthyear; }
	int GetCourse()const { return this->course; } int GetTel_num() const { return this->tel_num; }

	void ShowAll() {

		cout << this->FullName << setw(6);

		cout << this->birthdate << "." << this->birthmonth << "." << this->birthyear << "  ";

		cout << this->address << "@gmail.com" << " ";
		cout << this->fakultat << " ";
		cout << this->course << " ";
		cout << "+380" << this->tel_num << " ";
		cout << endl;


	}

	friend void random(Student*& students, int n);
	friend void del(Student*& students, int& n);
	friend void add(Student*& students, int& n);
	friend void individum(Student*& students, int n);
	friend void PrintFakultet(Student*& students, int n);
	friend void print_obj(Student*& students, int& n);
};

extern "C++" FUNC_API void complite();
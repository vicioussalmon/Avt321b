#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

#define  MAXSIZE 300

using namespace std;


class Faculty
{
	string FacultyName;
	string dataFacultyNames[5] = { "CS", "CM", "IT", "GM", "SGC" };
public:
	Faculty() { FacultyName = dataFacultyNames[rand() % 5]; }
	string getterFacultyName() { return FacultyName; }
};


class Student {
	class Solarschip {
		int solar;
	public:
		void setterSolar(const int& solar) { this->solar = solar; };
		int getterSolar() { return solar; };
	};

	string FullName;
	string address;
	Solarschip solar;
	Faculty faculty;
	short int course;

public:

	Student* next, * prev;
	//Student();

	// setter
	void setterAll(string FullName, string address, short int course,int solar);

	//getters
	string getterFullname(); string getterAddress(); short int getterCourse(); int getterSolar();

	void show();

	//~Student(){};
	friend void Sort(Student** head);

};



class Main
{
private:
	int size;

public:
	Main() : size(0) {};

	int GetSize() { return size; };
	void CreateList(short int count, Student** head, Student* tail);
	void PrintList(Student* head);
	void Insert(Student** head, Student** tail, int pos);
	void DeleteInList(Student** Dhead, Student** Dtail, int pos);
	bool DcheckNULL(Student* head);
	void FreeList(Student** head);
	void table_header();

	// main tasks
	void unsatisfactory(Student** head);
	void byGrade(Student** head, short int setted);
	//void hightesGradeandHalf(Student** head);

	// working method
	void main();

	~Main() {};
};


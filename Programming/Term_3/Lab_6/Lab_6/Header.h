#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

#define  MAXSIZE 300

using namespace std;


class Department
{
	string DepName;
	bool fullDay;
	string dataDepNames[5] = { "Computer Science", "Computer Modeling", "Integrated Tech", "Geom. Modeling", "SGC" };
public:
	Department() { DepName = dataDepNames[rand() % 5]; fullDay = rand() % 2; }
	string getterDepName() { return DepName; }
	bool getterfullDay() { return fullDay; }
};


class Student {
	class GradeSub {
		short int grade;
		string subject;
	public:
		void setterGrade(const short int& grade) noexcept { this->grade = grade; };
		void setterSubject(const string& subject) { this->subject = subject; };
		short int getterGrade() noexcept { return grade; };
		string getterSubject() { return subject; };
	};

	string FullName;
	string address;
	GradeSub grade;
	Department departament;

public:

	Student* next, * prev;
	//Student();

	// setter
	void setterAll(string FullName, string address, short int grade, string subject);

	//getters
	string getterFullname(); string getterAddress(); short int getterGrade(); string getterSubject();

	void show();

	//~Student(){};
	friend void Sort(Student** head, short int set);

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
	void hightesGradeandHalf(Student** head);

	// working method
	void main();

	~Main() {};
};


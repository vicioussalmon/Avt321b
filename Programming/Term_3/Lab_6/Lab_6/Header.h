#pragma once
#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <ctime>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


class Faculty {
	string FacultyName;
	string dataFaculty[7] = { "CS", "NS", "CH", "MI","EN", "LG", "JL" };
public:
	Faculty() { FacultyName = dataFaculty[rand() % 7]; }
	string getterFucName() { return FacultyName; }
	void setterFacultyName(string& FacultyName) { this->FacultyName; }
};

class Student {
	class Birthdate {
		string birthdate;

		string birthday;
		string birthmonth;
		string birthyear;
	public:
		void setterBirthdate(string & birthdate) noexcept {
			this->birthday = to_string(rand() % (31 - 1 + 1) + 1);
			this->birthmonth = to_string(rand() % (12 - 1 + 1) + 1);
			this->birthyear = to_string(rand() % (2005 - 1998 + 1) + 1998);
			this->birthdate += (birthday + "." + birthmonth + "." + birthyear);
		};
		string getterBirthdate() noexcept { return birthdate; }
		string getterBirthyear() noexcept { return birthyear; }

	};
	
	string dataNames[27] = { "Ethan", "Josh", "Sam", "Tom", "Bruse",  "Diego", "Adrian", "Brian", "Carl", "Caleb", "Daniel", "Derek", "Elliot", "Kuel",
						   "Sophia", "Amelia", "Ella", "Chloe",  "Emma", "Ava",  "Ginna", "Layla", "Zoey", "Olivia", "Sarah", "Rachel", "Emily" };
	string dataSecondNames[39] = { "Smith", "Johnson", "Williams", "Jones", "Brown","Davis","Miller", "Wilson","Moore","Taylor", "Thomas","Jackson", "White","Harris","Martin", "Garcia","Clark", "Lewis","Lee","Walker", "Hall","Allen","Young", "King","Wright", "Lopez","Hill","Scott", "Green","Adams","Baker",
		 "Nelson","Carter", "Perez","Roberts","Turner", "Parker", "Evans","Collins" };



	string FullName;//
	string Name;
	string SecondName;
	Birthdate birthdate;//
	Faculty faculty;//
	string address;//
	string course;
	string place;
	string phonenumber;
public:

	void SetAll(string FullName,  string birthdate, string course, string FacultyName, string address, string place, string phonenumber);

	string getterCourse();
	string getPlace();
	string getAddress();
	string getFullName();
	string getPhonenumber();
	string getterBirthyear();
	string getterBirthdate();
	string getterFucName();

	void ShowAll();


};
class Osn {
	//Student();
	void creating(Student** List, int size);
	void del(Student** List, int& size);
	void add(Student** List, int& size);
	void edit(Student** List, int& size);
	void individum(Student** List, int size);
	void print(Student** List, int size);
public:
	void main();
	~Osn() {};
};
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
class Uchen {
protected:
	string dataNames[32] = { "Ethan", "Josh", "Sam", "Tom", "Bruse", "Michael", "Diego", "Adrian", "Brian", "Carl", "Caleb", "Charles", "Daniel", "Derek", "Elliot", "Kuel",
						   "Sophia", "Amelia", "Ella", "Chloe", "Penelope", "Emma", "Ava", "Isabella", "Elizabath", "Ginna", "Layla", "Zoey", "Olivia", "Sarah", "Rachel", "Emily" };
	string dataSecondNames[50] = { "Smith", "Johnson", "Williams", "Jones", "Brown","Davis","Miller", "Wilson","Moore","Taylor", "Anderson","Thomas","Jackson", "White","Harris","Martin", "Thompson","Garcia","Martinez", "Robinson","Clark","Rodriguez", "Lewis","Lee","Walker", "Hall","Allen","Young", "Hernandez","King","Wright", "Lopez","Hill","Scott", "Green","Adams","Baker",
		"Gonzalez", "Nelson","Carter","Mitchell", "Perez","Roberts","Turner", "Phillips","Campbell","Parker", "Evans","Edwards","Collins" };

	string Name;
	string SecondName;
	string phonenumber;
	string place;
	string birthyear;
public:

	virtual string getName() const { return Name; }
	virtual string getPhonenumber() const { return phonenumber; }
	virtual string getSecond() const { return SecondName; }
	virtual string getplace() const { return place; }
	virtual string getBirthyear() const { return birthyear; }
	virtual void ShowAll() = 0;
	virtual void SetAll() = 0;
};
class Student : public Uchen {
private:
	string dataFaculty[7] = { "CS", "NS", "CH", "MI","EN", "LG", "JL" };

	string faculty;
	string birthdate;
	string birthday;
	string birthmonth;
	string address;
	string course;

public:

	void SetAll () override {
		this->Name = dataNames[rand() % 32];
		this->SecondName = dataSecondNames[rand() % 50];
		this->birthday = to_string(rand() % (31 - 1 + 1) + 1);
		this->birthmonth = to_string(rand() % (12 - 1 + 1) + 1);
		this->birthyear = to_string(rand() % (2005 - 1998 + 1) + 1998);
		this->birthdate += (birthday +"." + birthmonth + "." + birthyear);
		this->address = Name + "@gmail.com";
		this->course = to_string(rand() % (5 - 1 + 1) + 1);
		this->faculty = dataFaculty[rand() % 7];
		this->phonenumber = "+380" + (to_string(rand() % 1000 + 1000000));
		this->place = "Univercity";
	}
	
	/*string GetName() const { return this->Name; } string GetAddress() const { return this->address; } string Getfaculty() const { return this->faculty; }
	 string GetBirthdate() const { return this->birthdate; }
	string GetCourse()const { return this->course; } string Getphonenumber() const { return this->phonenumber; }*/

	void ShowAll() {

		cout << "|" << setw(10) << this->Name << setw(10) << "|" << this->birthdate<< setw(10);
		cout << "|" << setw(10) << this->faculty << setw(10);
		cout << "|" << setw(10) << this->course << setw(10);
		cout << "|" << setw(10) << this->phonenumber << setw(10);
		cout << "|" << setw(10) << this->address << setw(10);
		cout << "|" << setw(10) << this->place << setw(10);
		cout << endl;


	}


};
class School : public Uchen {
private:
	string dataClassLetter[7] = { "A", "B", "C", "D","E", "F", "G" };

	string classletter;
	string birthdate;
	string address;
	string classnumber;


public:


	void SetAll() override {
		this->Name = dataNames[rand() % 32];
		this->SecondName = dataSecondNames[rand() % 50];
		this->birthdate += (to_string(rand() % (31 - 1 + 1) + 1) + "." + to_string(rand() % (12 - 1 + 1) + 1) + "." + to_string(rand() % (2004 - 2016 + 1) + 2016));
		this->address = Name + "@gmail.com";
		this->classnumber = to_string(rand() % (11 - 1 + 1) + 1);
		this->classletter = dataClassLetter[rand() % 7];
		this->phonenumber = "+380" + (to_string(rand() % 1000 + 1000000));
		this->place = "School";
	}
	
	/*string GetName() const { return this->Name; } string GetAddress() const { return this->address; } string Getfaculty() const { return this->faculty; }
	string GetBirthdate() const { return this->birthdate; }
	string GetCourse()const { return this->course; } string Getphonenumber() const { return this->phonenumber; }*/

	void ShowAll() {

		cout << "|" << setw(10) << this->Name << setw(10) << "|" << this->birthdate << setw(10);
		cout << "|" << setw(10) << this->address << setw(10);
		cout << "|" << setw(10) << this->classletter << setw(10);
		cout << "|" << setw(10) << this->classnumber << setw(10);
		cout << "|" << setw(10) << this->phonenumber << setw(10);
		cout << "|" << setw(10) << this->place << setw(10);
		cout << endl;


	}
};
class Osn {
	void creating(Uchen** List, int size);
	void del(Uchen** List, int &size);
	void add(Uchen** List, int &size);
	void edit(Uchen** List, int& size);
	void individum(Uchen** List, int size);
	void printplace(Uchen** List, int size);
	void print(Uchen** List, int size);
public:
	void main();
};

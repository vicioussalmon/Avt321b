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
	string dataNames[27] = { "Ethan", "Josh", "Sam", "Tom", "Bruse",  "Diego", "Adrian", "Brian", "Carl", "Caleb", "Daniel", "Derek", "Elliot", "Kuel",
						   "Sophia", "Amelia", "Ella", "Chloe",  "Emma", "Ava",  "Ginna", "Layla", "Zoey", "Olivia", "Sarah", "Rachel", "Emily" };
	string dataSecondNames[39] = { "Smith", "Johnson", "Williams", "Jones", "Brown","Davis","Miller", "Wilson","Moore","Taylor", "Thomas","Jackson", "White","Harris","Martin", "Garcia","Clark", "Lewis","Lee","Walker", "Hall","Allen","Young", "King","Wright", "Lopez","Hill","Scott", "Green","Adams","Baker",
		 "Nelson","Carter", "Perez","Roberts","Turner", "Parker", "Evans","Collins" };
	
	

	string FullName;
	string Name;
	string SecondName;
	string phonenumber;
	string place;
	string birthyear;

public:

	virtual string getFullName() = 0;
	virtual string getPhonenumber() = 0;
	virtual string getSecond() = 0;
	virtual string getBirthyear() = 0;
	virtual string getPlace() = 0;
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
		this->Name = dataNames[rand() % 27];
		this->SecondName = dataSecondNames[rand() % 39];
		this->FullName += Name + " " + SecondName;
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
	

    string getPlace() override { return place; }
	string getFullName() override { return FullName; }
	string getPhonenumber() override { return phonenumber; }
	string getSecond() override { return SecondName; }
	string getBirthyear() override { return birthyear; }

	void ShowAll() {

		cout << "|" << setw(15) << this->FullName << setw(1) << "|" << setw(10) << this->birthdate << setw(1);
		cout << "|" << setw(3) << this->faculty << setw(1);
		cout << "|" << setw(2) << this->course << setw(1);
		cout << "|" << setw(11) << this->phonenumber << setw(1);
		cout << "|" << setw(16) << this->address << setw(1);
		cout << "|" << setw(10) << this->place << setw(1) << "|";
		cout << endl;


	}


};
class School : public Uchen {
protected:

	string classletter;
	string number = "+380";
};
class MSchool : public School {
private:
	string dataClassLetter[7] = { "A", "B", "C", "D","E", "F", "G" };

	string birthdate;
	string birthday;
	string birthmonth;
	string address;
	string classnumber;


public:


	void SetAll() override {
		this->Name = dataNames[rand() % 27];
		this->SecondName = dataSecondNames[rand() % 39];
		this->FullName += Name + " " + SecondName;
		this->birthday = to_string(rand() % (31 - 1 + 1) + 1);
		this->birthmonth = to_string(rand() % (12 - 1 + 1) + 1);
		this->birthyear = to_string(rand() % (2007 - 2005 + 1) + 2005);
		this->birthdate += (birthday + "." + birthmonth + "." + birthyear);
		this->address = Name + "@gmail.com";
		this->classnumber = to_string(rand() % (11 - 1 + 1) + 1);
		this->classletter = dataClassLetter[rand() % 7];
		this->phonenumber +=(to_string(rand() % 1000 + 1000000));
		this->place = "M.School";
	}

	string getPlace() override { return place; }
	string getFullName() override { return FullName; }
	string getPhonenumber() override { return phonenumber; }
	string getSecond() override { return SecondName; }
	string getBirthyear() override { return birthyear; }

	void ShowAll() {



		cout << "|" << setw(15) << this->FullName << setw(1) << "|" << setw(10) << this->birthdate << setw(1);
		cout << "|" << setw(3) << this->classletter << setw(1);
		cout << "|" << setw(2) << this->classnumber << setw(1);
		cout << "|" << setw(11) << this->phonenumber << setw(1);
		cout << "|" << setw(16) << this->address << setw(1);
		cout << "|" << setw(10) << this->place << setw(1) << "|";
		cout << endl;

	}
};
class HSchool : public School {
private:
	string dataClassLetter[7] = { "A", "B", "C", "D","E", "F", "G" };

	string birthdate;
	string birthday;
	string birthmonth;
	string address;
	string classnumber;


public:


	void SetAll() override {
		this->Name = dataNames[rand() % 27];
		this->SecondName = dataSecondNames[rand() % 39];
		this->FullName += Name + " " + SecondName;
		this->birthday = to_string(rand() % (31 - 1 + 1) + 1);
		this->birthmonth = to_string(rand() % (12 - 1 + 1) + 1);
		this->birthyear = to_string(rand() % (2007 - 2005 + 1) + 2005);
		this->birthdate += (birthday + "." + birthmonth + "." + birthyear);
		this->address = Name + "@gmail.com";
		this->classnumber = to_string(rand() % (11 - 1 + 1) + 1);
		this->classletter = dataClassLetter[rand() % 7];
		this->phonenumber += (to_string(rand() % 1000 + 1000000));
		this->place = "H.School";
	}
	
    string getPlace() override { return place; }
    string getFullName() override { return FullName; }
	string getPhonenumber() override { return phonenumber; }
	string getSecond() override { return SecondName; }
	string getBirthyear() override { return birthyear; }

	void ShowAll() {



		cout << "|" << setw(15) << this->FullName << setw(1) << "|" << setw(10) << this->birthdate << setw(1);
		cout << "|" << setw(3) << this->classletter << setw(1);
		cout << "|" << setw(2) << this->classnumber << setw(1);
		cout << "|" << setw(11) << this->phonenumber << setw(1);
		cout << "|" << setw(16) << this->address << setw(1);
		cout << "|" << setw(10) << this->place << setw(1) << "|";
		cout << endl;

	}
};
class Collage : public Uchen {
private:
	string dataFaculty[7] = { "CS", "NS", "CH", "MI","EN", "LG", "JL" };

	string faculty;
	string birthdate;
	string birthday;
	string birthmonth;
	string address;
	string course;

public:

	void SetAll() override {
		this->Name = dataNames[rand() % 27];
		this->SecondName = dataSecondNames[rand() % 39];
		this->FullName += Name + " " + SecondName;
		this->birthday = to_string(rand() % (31 - 1 + 1) + 1);
		this->birthmonth = to_string(rand() % (12 - 1 + 1) + 1);
		this->birthyear = to_string(rand() % (2005 - 1998 + 1) + 1998);
		this->birthdate += (birthday + "." + birthmonth + "." + birthyear);
		this->address = Name + "@gmail.com";
		this->course = to_string(rand() % (5 - 1 + 1) + 1);
		this->faculty = dataFaculty[rand() % 7];
		this->phonenumber = "+380" + (to_string(rand() % 1000 + 1000000));
		this->place = "Collage";
	}


	string getPlace() override { return place; }
	string getFullName() override { return FullName; }
	string getPhonenumber() override { return phonenumber; }
	string getSecond() override { return SecondName; }
	string getBirthyear() override { return birthyear; }

	void ShowAll() {

		cout << "|" << setw(15) << this->FullName << setw(1) << "|" << setw(10) << this->birthdate << setw(1);
		cout << "|" << setw(3) << this->faculty << setw(1);
		cout << "|" << setw(2) << this->course << setw(1);
		cout << "|" << setw(11) << this->phonenumber << setw(1);
		cout << "|" << setw(16) << this->address << setw(1);
		cout << "|" << setw(10) << this->place << setw(1) << "|";
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
	~Osn() {};
};

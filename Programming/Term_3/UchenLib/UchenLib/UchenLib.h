#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

#ifdef HUMANLIBRARY_EXPORTS

#define HUMANLIBRARY_API __declspec(dllexport)

#else

#define HUMANLIBRARY_API __declspec(dllimport)

#endif

#define  MAXSIZE 300

using namespace std;


extern "C++" HUMANLIBRARY_API class Uchen{
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

	//string pupplace[1] = {"School"};
	//string studplace[1] = {"Univercity"};
public:

	virtual string getFullName() = 0;
	virtual string getPhonenumber() = 0;
	virtual string getSecond() = 0;
	virtual string getBirthyear() = 0;
	virtual string getPlace() = 0;
	virtual void ShowAll() = 0;
	virtual void SetAll() = 0;
};
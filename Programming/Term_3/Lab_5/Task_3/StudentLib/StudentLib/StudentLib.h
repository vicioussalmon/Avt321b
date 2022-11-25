#include "pch.h"
#include "UchenLib.h"

#ifdef STAFFLIBRARY_EXPORTS

#define STAFFLIBRARY_API __declspec(dllexport)

#else

#define STAFFLIBRARY_API __declspec(dllimport)

#endif




extern "C++" STAFFLIBRARY_API class Student : public Uchen {
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
		this->place = "Univercity";
	}


	string getPlace() override { return place; }
	string getFullName() override { return FullName; }
	string getPhonenumber() override {
		return phonenumber;
	}
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
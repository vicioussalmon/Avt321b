#include "pch.h"
#include "UchenLib.h"

#ifdef STAFFLIBRARY_EXPORTS

#define STAFFLIBRARY_API __declspec(dllexport)

#else

#define STAFFLIBRARY_API __declspec(dllimport)

#endif




extern "C++" STAFFLIBRARY_API class School : public Uchen {
protected:

	string classletter;
	string number = "+380";
};
extern "C++" STAFFLIBRARY_API class MSchool : public School {
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
extern "C++" STAFFLIBRARY_API class HSchool : public School {
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
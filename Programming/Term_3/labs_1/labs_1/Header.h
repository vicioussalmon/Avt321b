#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

#define  MAXSIZE 300
using namespace std;

struct List {
	long int number;
	List* next;
	List* prev;
};
class Student {
private:
	string FullName;
	string Name;
	string initial;
	int birthdate;
	int birthmonth;
	int birthyear;
	string address;
	int course;
	string fakultat;
	int tel_num;
public:
	Student* next, * prev;
	//Student();
	////////list/////////////////

	void CreateList(int count, List** head, List* tail);
	void Printlist(List* head);
	void Insert(List** head, List** tail, int pos);
	void Deletelist(List** head, List** tail, int pos);
	bool DcheckNULL(List* head);
	short int CountOflist(List* head);
	void Freelist(List** head);
	//void SaveInFileDlist(DList* Dhead);
	
	/////////task//////////////

	void table();
	void show();
	friend void random(Student students[]);
	void table_header();
	friend void sort(Student students[]);
	friend void print_obj(Student students[]);
};

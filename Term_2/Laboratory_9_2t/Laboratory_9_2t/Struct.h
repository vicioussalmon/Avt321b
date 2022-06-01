#pragma once
#include <iostream>
#include <windows.h>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <fstream>
struct Data {
	int position;
	char pro;
	char firstValue;
	char secondValue;
	char thirdValue;
	float fourthValue;
};
struct List {

	Data in;
	List* next;
	List* prew;
};
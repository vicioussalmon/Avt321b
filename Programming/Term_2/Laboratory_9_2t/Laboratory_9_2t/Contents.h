#pragma once
#include <iostream>
#include <windows.h>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <fstream>
#include "Struct.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 4996)
using namespace std;
List* newsp();
void print_nach();
void print_end();
void search_nach(List* head);
List* search_end(List* head, List* tail);
List* ad(int el);
void del(List* head, int el); 
void sort(List* head);
void file(List* head);
void newfile(List* head);
void osn();
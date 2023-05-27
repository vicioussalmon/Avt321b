#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include "Contents.h" 
#include "Struct.h" 
#define _CRT_SECURE_NO_WARNINGS 
//#define DEBUG
#pragma warning(disable : 4996) 
using namespace std;
struct List* newsp();
void print(List* head);
void search(List* head);
void ad(List*head, int el);
void del(List* head, int el);
void sort(List* head);
void file(List* head);
void newfile(List* head);
void osn();
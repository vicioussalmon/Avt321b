#pragma once
#include <iostream>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
void pfoo(int* arr, int SIZE);
void lfoo(int(&ref)[], int SIZE);
void osn();
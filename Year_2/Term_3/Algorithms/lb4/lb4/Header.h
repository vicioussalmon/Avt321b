#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;


void printArray(int* array, int size);

void readChaotically(int* array, int size);
void createChaotically(int* array, int size);
void createAscending(int* array, int size);
void createDescending(int* array, int size);

//sorting
void ChooseSort(int* array, int size, int& operationCounter);
void heapify(int* array, int size, int i, int& operationCounter);
void PiramidSort(int* array, int size, int& operationCounter);
void ShellSort(int* array, int size, int& operationCounter);
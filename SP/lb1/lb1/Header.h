#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include <string>  
#include <ctime>
#include <Windows.h>
using namespace std;





struct Node {
	long int number;
	Node* next;
};

struct DList {
	int number;
	DList* next;
	DList* prev;
};


void inputCheker();

// doubly node 


void CreateDListConsole(int count, DList** Dhead, DList* Dtail);
void PrintDlist(DList* Dhead);
void DInsert(DList** Dhead, DList** Dtail, int pos);
void DeleteDlist(DList** Dhead, DList** Dtail, int pos);
bool DcheckNULL(DList* Dhead);
short int CountOfDlist(DList* Dhead);
void FreeDlist(DList** Dhead);
void SwapDlsit(const int value1, const int value2, DList* Dhead);
void SaveInFileDlist(DList* Dhead);
void LoadFromFileDlist(DList** Dhead, DList** Dtail);



// singly node 
void CreateNodeConsole(int count, Node** head);
void PrintNode(Node* head);
void Insert(Node* head, int check);
void Delete(Node** head, int check);
void FreeNode(Node** head);
bool checkNULL(Node* head);
short int CountOfNode(Node* head);
void Split(Node** head, Node** begin);
void SwapNode(const int value1, const int value2, Node* head);
void SaveInFileNode(Node* head);
void LoadFromFile(Node** head);
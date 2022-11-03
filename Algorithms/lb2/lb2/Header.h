#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Stack
{

private:

	long int data;
	Stack* next;
	Stack* root;
	int size;

public:

	void PushStack(long int& newData);
	long int PopStack();
	void CreateStack(int amount);
	bool isNULL();
	void show();

	void deleteStack();
	//task mathods
	void replaceFirstandLast();
	void reverse();
	void deleteEverySecond();
	void findMax0();
	void deleteMin();
	void deletAllExpFrist();
	void deletAllExpLast();

	//filework
	void read();
	void write();


	Stack() { root = NULL; size = 0; }

};
class Queue {

private:

	int size;
	long int data;
	Queue* head;
	Queue* next;
	Queue* tail;



public:

	void Push(const long int& data);
	void show();
	int amount() { return size; }
	void ArithmeticMean();
	void MinandMax();
	void beforeMIN();
	void write();
	void read();

	void deleteq() {
		while (head) {
			Queue* deletedITM = this->head;
			long int tempData = deletedITM->data;
			this->head = deletedITM->next;
			delete deletedITM; deletedITM = NULL;
			size--;
		}
		cout << "\tОчередь была удалена!\n";
	}

	Queue() { head = NULL; tail = NULL; size = 0; }


};
class Deque {

private:

	int size;
	long int data;
	Deque* head;
	Deque* next;
	Deque* tail;
	Deque* prev;



public:

	void PushFront(const long int& data);
	void PushBack(const long int& data);
	void show();
	bool isNULL() {
		if (size == 0)
			return true;
		else
			return false;

	}
	long int readLast() { return tail->data; };
	void read();
	void write();

	void deleted() {
		while (head) {
			Deque* deletedITM = this->head;
			long int tempData = deletedITM->data;
			this->head = deletedITM->next;
			delete deletedITM; deletedITM = NULL;
			size--;
		}
		cout << "\tДек был удален!\n";
	}
	Deque() { head = NULL; tail = NULL; size = 0; }


};
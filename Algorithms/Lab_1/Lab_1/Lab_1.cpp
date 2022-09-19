#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable : 4996) 
using namespace std;
//односвязный список
struct Data {
	char data;
	char pro;
	char firstValue;
	char secondValue;
	char thirdValue;
	float fourthValue;
};
struct TList {

	Data info;
	TList* next;
	/*TList* head;
	TList* tail;*/

};
extern TList* head, * tail;
void create_List(int num, Data tt) {
	if (num > 0) {
		TList* temp = new TList;
		temp->next = NULL;
		temp->info.data = tt.data;
		if (head == NULL) {
			head = tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}
}
void print_List() {
	TList* temp;
	temp = head;
	while (temp != NULL) {
		cout << temp->info.data << " ";
		temp = temp->next;
	}
}
void add_last_element(Data ob) {
	TList* temp = new TList;
	TList* temp_last = tail;
	temp->next = temp_last->next;
	temp_last->next = temp;

	temp->info.data = ob.data;

}
void delete_eleme_by_num(int index) {
	TList* temp_post = head;
	if (index == 0) {
		head = head->next;
		delete temp_post;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			temp_post = temp_post->next;
			TList* temp = temp_post->next;
			temp_post->next = temp->next;
			delete temp;
		}
	}
}
int size_list() {
	int k = 0;
	TList* temp = head;
	while (temp != 0) {
		temp = temp->next;
		k++;
	}
	return k;
}
void change(int in) {
	TList* temp = head;
	Data b;
	int k = 1;
	while (temp != NULL) {
		temp = temp->next;
		k++;
		if (k == in) {
			b.data = temp->info.data;
			temp->info.data = temp->next->info.data;
			temp->next->info.data = b.data;
		}
	}
}



int main()
{
    std::cout << "Hello World!\n";
}

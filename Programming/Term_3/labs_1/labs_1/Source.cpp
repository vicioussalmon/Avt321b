#include "Header.h"
void Student::show()
{
cout << "|" << setw(17) << this->FullName << setw(9) << "|" << setw(12) << this->address << setw(9) << "|" << setw(4) << this->birthdate << setw(4) << "|"<< this->course << endl;
}
void Student::CreateList(short int count, Student** head, Student* tail)
{
	string FullName = "Student ", init, address; short int grade;
	if (count > 0) {
		(*head) = new Student;
		//cout << "Input you value \n--->"; //cin >> FullName >> address >> grade;
		init = rand() % 26 + 65; init += '.'; init += rand() % 26 + 65; init += '.';
		FullName += init;
		address += rand() % 26 + 65; address += "@mail.com";
		grade = rand() % 101;
		(*head)->setterAll(FullName, address, grade);
		(*head)->prev = tail;
		(*head)->next = NULL;
		CreateList(count - 1, &((*head)->next), (*head));
	}
	else (*head) = NULL;

	size = count;
}
#include "Header.h"

string dataNames[32] = { "Ethan", "Josh", "Sam", "Tom", "Bruse", "Michael", "Diego", "Adrian", "Brian", "Carl", "Caleb", "Charles", "Daniel", "Derek", "Elliot", "Kuel",
						   "Sophia", "Amelia", "Ella", "Chloe", "Penelope", "Emma", "Ava", "Isabella", "Elizabath", "Ginna", "Layla", "Zoey", "Olivia", "Sarah", "Rachel", "Emily" };
string dataSecondNames[50] = { "Smith", "Johnson", "Williams", "Jones", "Brown","Davis","Miller", "Wilson","Moore","Taylor", "Anderson","Thomas","Jackson", "White","Harris","Martin", "Thompson","Garcia","Martinez", "Robinson","Clark","Rodriguez", "Lewis","Lee","Walker", "Hall","Allen","Young", "Hernandez","King","Wright", "Lopez","Hill","Scott", "Green","Adams","Baker",
	"Gonzalez", "Nelson","Carter","Mitchell", "Perez","Roberts","Turner", "Phillips","Campbell","Parker", "Evans","Edwards","Collins" };

// main class


void Main::main()
{
	short int count, button, checker;
	Student* head = NULL, * tail = NULL;

	while (true) {
		cout << "Work with data - 1 \nClear data - 2 \nExit - 0 \n"; cin >> button;
		if (cin.fail()) {
			system("cls");
			cin.clear();
			cin.ignore(32767, '\n');
			cout << " \t\t\tIncorrect input! ERROR! " << endl;
			continue;
		}
		switch (button)
		{
		case 1:
			while (button != 0) {
				system("cls");
				if (head == NULL) {
					cout << "How long you list could be? \n"; cin >> count;
					if (cin.fail()) {
						system("cls");
						cin.clear();
						cin.ignore(32767, '\n');
						cout << " \t\t\tIncorrect input! ERROR! " << endl;
						continue;
					}
					CreateList(count, &head, tail);
					system("cls");
				}

				table_header();
				PrintList(head);

				cout << "Find students from <bachaleor> courses - 1\n" <<
					"Find students by courses, that are less than you choose - 2\n" <<
					"Delete one data - 3\n" <<
					"Add new data - 4\n" <<
					"Sort - 5\n" <<
					"Back - 0\n";
				cin >> button;
				if (cin.fail()) {
					system("cls");
					cin.clear();
					cin.ignore(32767, '\n');
					cout << " \t\t\tIncorrect input! ERROR! " << endl;
					continue;
					system("pause");
				}

				switch (button)
				{
				case 1:
					system("cls");
					unsatisfactory(&head);
					system("pause");
					break;
				case 2:
					system("cls");
					cout << "Input course limit \n"; cin >> checker;
					if (cin.fail()) {
						system("cls");
						cin.clear();
						cin.ignore(32767, '\n');
						cout << " \t\t\tIncorrect input! ERROR! " << endl;
						system("pause");
						continue;
					}
					byGrade(&head, checker);
					system("pause");
					break;
				case 3:
					system("cls");
					cout << "Input number data \n"; cin >> checker;
					if (cin.fail()) {
						system("cls");
						cin.clear();
						cin.ignore(32767, '\n');
						cout << " \t\t\tIncorrect input! ERROR! " << endl;
						system("pause");
						continue;
					}
					DeleteInList(&head, &tail, checker);
					break;
				case 4:
					system("cls");
					cout << "Input number data \n"; cin >> checker;
					if (cin.fail()) {
						system("cls");
						cin.clear();
						cin.ignore(32767, '\n');
						cout << " \t\t\tIncorrect input! ERROR! " << endl;
						system("pause");
						continue;
					}
					Insert(&head, &tail, checker);
					break;
				case 5:
					system("cls");
					cout << "Sort by name - 1 \nnBack - 0 \n"; cin >> button;
					if (cin.fail()) {
						system("cls");
						cin.clear();
						cin.ignore(32767, '\n');
						cout << " \t\t\tIncorrect input! ERROR! " << endl;
						system("pause");
						continue;
					}
					switch (button)
					{
					case 1:
						Sort(&head);
						table_header();
						PrintList(head);
						system("pause");
						break;
					case 0:
						system("cls");
						break;
					default:
						break;
					}
					break;
				case 0:
					system("cls");
					break;
				default:
					break;
				}

			}
			break;
		case 2:
			system("cls");
			if (DcheckNULL(head) != 0)
				FreeList(&head);
			break;
		case 0:
			system("cls");
			FreeList(&head);
			exit(0);
			break;
		default:
			break;
		}

	}

}



//set methods
void Student::setterAll(string FullName, string address, short int course,int solar)
{
	this->FullName = FullName;
	this->address = address;
	this->course = course;
	this->solar.setterSolar(solar);

}


// get methods
string Student::getterFullname() { return this->FullName; }

string Student::getterAddress() { return this->address; }

short int Student::getterCourse() { return this->course; }

int Student::getterSolar() { return solar.getterSolar(); };


// show method
void Student::show()
{
	if (this->solar.getterSolar() != -1)
		cout << "|" << setw(22) << this->FullName << setw(1) << "|" << setw(23) << this->address << setw(1) << "|" << setw(6)<< this->course<< setw(1) << "|" << setw(12) << this->solar.getterSolar() << setw(1) << "|" << setw(10) << this->faculty.getterFacultyName() << setw(1) << "|";
	else
		cout << "|" << setw(22) << "NO USER " << setw(1) << "|" << setw(23) << "MISTAKE" << setw(1) << "|" << setw(6) << "404" << setw(1) << "|" << setw(12) << "404" << setw(1) << "|" << setw(10) << "404" << setw(1) << "|";
	cout << "\n ------------------------------------------------------------------------------\n";
}

///////////////////////////////////////////////////////////////////////
/////////////////////  Main tasks  ///////////////////////////////////
/////////////////////////////////////////////////////////////////////

void Main::unsatisfactory(Student** head)
{
	int count = 0;
	Student* current = *head;
	Student* unsatisfactoryGrade = new Student[MAXSIZE];


	if (DcheckNULL((*head)) == 0) { return; }
	else {
		while (current) {
			if (current->getterCourse() <= 4 && current->getterSolar() != -1) {
				unsatisfactoryGrade[count].setterAll(current->getterFullname(), current->getterAddress(), current->getterCourse(), current->getterSolar());
				count++;
			}
			current = current->next;
		}
	}

	if (count != 0) {
		cout << "\t Students from <bachelor> courses: " << count << endl;
		table_header();
		for (size_t i = 0; i < count; i++) {
			unsatisfactoryGrade[i].show();
		}
	}
	else
		cout << "\tStudents haven`t been found!\n";


	delete[] unsatisfactoryGrade; unsatisfactoryGrade = NULL;
}

void Main::byGrade(Student** head, short int setted)
{
	int count = 0;
	Student* current = *head;
	Student* byGrade = new Student[MAXSIZE];


	if (DcheckNULL((*head)) == 0) { return; }
	else {
		while (current) {
			if (current->getterCourse() > setted && current->getterSolar() != -1) {
				byGrade[count].setterAll(current->getterFullname(), current->getterAddress(), current->getterCourse(), current->getterSolar());
				count++;
			}
			current = current->next;
		}
	}

	if (count != 0) {
		cout << "\t Students with courses higher " << setted << ": " << count << endl;
		table_header();
		for (size_t i = 0; i < count; i++) {
			byGrade[i].show();
		}
	}
	else
		cout << "\tStudents haven`t been found!\n";


	delete[] byGrade; byGrade = NULL;
}


//void Main::hightesGradeandHalf(Student** head)
//{
//	int count = 0;
//	Student* current = *head;
//	Student* byGrade = new Student[MAXSIZE];
//
//
//	if (DcheckNULL((*head)) == 0) { return; }
//	else {
//		while (current) {
//			if (current->getterCourse() > 89 or (current->getterCourse() > 34 and current->getterCourse() < 60)) {
//				byGrade[count].setterAll(current->getterFullname(), current->getterAddress(), current->getterCourse(), current->getterSolar());
//				count++;
//			}
//			current = current->next;
//		}
//	}
//
//
//	if (count != 0) {
//
//		cout << "\tStudents " << ": " << count << endl;
//		table_header();
//		for (size_t i = 0; i < count; i++) {
//			byGrade[i].show();
//		}
//
//		if (count != 1) {
//			short int choose = -1;
//			Student* chosen = new Student[count];
//			short int flag = 0;
//			short index = 0;
//			current = *head;
//			while (choose != 0 and flag != count) {
//				cout << "Choose the studenet by number (0-stop) --> "; cin >> choose;
//				if (choose > count) {
//					cout << "\tFalse input, try again!\n";
//					continue;
//				}
//				if (choose != 0) { flag++; };
//				for (size_t i = 0; i < choose; i++) {
//					if (i == choose - 1) {
//						chosen[index] = byGrade[choose - 1];
//						index++;
//					}
//					current = current->next;
//				}
//			}
//
//			if (flag != 0) {
//				table_header();
//				for (size_t i = 0; i < flag; i++) {
//					chosen[i].show();
//				}
//			}
//			else
//				cout << "\tStudents haven`t been chosen!\n";
//
//			delete[] chosen; chosen = NULL;
//		}
//		else {
//			cout << "You shouldn`t to choose the one student!\n";
//		}
//
//
//	}
//	else
//		cout << "\tStudents haven`t been found!\n";
//
//	delete[] byGrade; byGrade = NULL;
//
//}
//
//




void Main::table_header()
{
	cout << "\n ------------------------------------------------------------------------------\n";
	cout << "|" << setw(22) << "Full Name" << setw(1) << "|" << setw(23) << "Email" << setw(1) << "|" << setw(6) << "Course" << setw(1) << "|" << setw(12) << "Solarschip" << setw(1) << "|" << setw(10) << "Faculty" << setw(1) << "|";
	cout << "\n ------------------------------------------------------------------------------\n";
}






///////////////////////////////////////////////////////////////////////
///////////////////// Doubly Node  ///////////////////////////////////
/////////////////////////////////////////////////////////////////////


void Main::CreateList(short int count, Student** head, Student* tail)
{
	string FullName, buffer, address; int solar; short int course;

	if (count > 0) {
		(*head) = new Student;
		FullName = dataNames[rand() % 32];
		address += FullName;
		FullName += " ";
		buffer = dataSecondNames[rand() % 32];
		FullName += buffer;
		address += buffer += "@gmail.com";
		if (rand() % 2)
			solar = rand() % (3500 - 2000 + 1) + 2000;
			
		else
			solar = -1;
		course = rand() % (6-1+1)+1;
		(*head)->setterAll(FullName, address, course, solar);
		(*head)->prev = tail;
		(*head)->next = NULL;
		CreateList(count - 1, &((*head)->next), (*head));
	}
	else (*head) = NULL;

	size = count;
}

void Main::PrintList(Student* head) {
	if (head != NULL) {
		head->show();
		PrintList(head->next);
	}
	else cout << endl << endl;
}

void Main::Insert(Student** head, Student** tail, int pos) {

	Student* temp = new Student;

	if (pos == 0) {
		temp->next = *head;
		(*head)->prev = temp;
		*head = temp;
		temp->prev = NULL;
	}
	else {
		Student* current = *head;
		for (size_t i = 0; i < pos - 1; i++)
			current = current->next;
		if (current->next == NULL) {
			current->next = temp;
			temp->prev = *tail;
			temp->next = NULL;
			*tail = temp;
		}
		else {
			temp->next = current->next;
			current->next = temp;
			temp->next->prev = temp;
			temp->prev = current;
		}
	}
	string FullName, buffer, address; int solar; short int course;
	FullName = dataNames[rand() % 32];
	address += FullName;
	FullName += " ";
	buffer = dataSecondNames[rand() % 32];
	FullName += buffer;
	address += buffer += "@gmail.com";
	if (rand() % 2)
		solar = rand() % (3500 - 2000 + 1) + 2000;

	else
		solar = -1;
	course = rand() % (6 - 1 + 1) + 1;
	temp->setterAll(FullName, address, course, solar);

}


void Main::DeleteInList(Student** head, Student** tail, int pos) {

	Student* current = *head;

	if (pos == 0) {
		*head = (*head)->next;
		(*head)->prev = NULL;
		delete current;
	}
	else {
		for (size_t i = 0; i < pos - 1; i++)
			current = current->next;
		Student* temp = current->next;
		if (temp->next == NULL) {
			current->next = NULL;
			*tail = current;
		}
		else {
			current->next = temp->next;
			temp->next->prev = current;
		}
		delete temp;
	}
}


bool Main::DcheckNULL(Student* head) { // cheking on empty 
	if (head == NULL) {
		cout << "List is empty." << endl;
		return 0;
	}
	return 1;
}


void Main::FreeList(Student** head) { // clean list
	Student* current = *head;
	while (current) {
		*head = (*head)->next;
		free(current);
		current = *head;
	}
}


void Sort(Student** head) {
	Student* left = *head;
	Student* right = (*head)->next;
	Student* temp = new Student;

	// sort by name
		while (left->next) {

			while (right) {

				if ((left->FullName.compare(right->FullName) > 0)) {

					temp->FullName = left->FullName;
					left->FullName = right->FullName;
					right->FullName = temp->FullName;

				}
				right = right->next;

			}

			left = left->next;
			right = left->next;
		}
		
	}


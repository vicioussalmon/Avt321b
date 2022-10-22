#include "Header.h"

int main()
{
	while (true) {
		int a;
		cout << "Choose operation that you need:" << endl;
		cout << "Show the list of students - 1" << endl;
		cout << "Show the list of students of fakultat that you need - 2" << endl;
		cout << "Show the list of students, that was born after 2004 year - 3" << endl;
		cout << "Delete choosen person - 4" << endl;
		cout << "Add new person - 5" << endl;
		cout << "Exit - 0" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			system("cls");
			Student students[M];
			random(students);
			//table_header();
			print_obj(students);
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			Student students[M];
			random(students);
			int f;
			print_obj(students);
			cout << "Students of what faculty do you need?" << endl;
			cout << "We have three faculty, so please choose one of them: CS, MI, NS" << endl;
			PrintFakultet(students);
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			system("cls");
			Student students[M];
			random(students);
			cout << "List of students, that was born after 2004" << endl;
			individum(students);
			cout << "-----------------------------------------------------------------------------" << endl;
			print_obj(students);
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			system("cls");
			Student students[M];
			int position;
			cout << "Choose position, that we will delete:" << endl;
			cin >> position;
			print_obj(students);
			system("pause");
			system("cls");
			break;
			  }
		case 0:{
			system("cls");
			exit(0);
			break;
			}

		default:
			system("cls");
			cout << " \t\t\tERROR " << endl;
			break;
		}
	}
		

}

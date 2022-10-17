#include "Header.h"

int main()
{
	while (true) {
		int a;
		cout << "Choose operation that you need:" << endl;
		cout << "Show the list of students - 1" << endl;
		cout << "Show the list of students of fakultat that you need - 2" << endl;
		cout << "Show the list of students, that was born after this year - 3" << endl;
		cout << "Exit - 0" << endl;
		cin >> a;
		switch (a)
		{
		default:
			system("cls");
			cout << " \t\t\tERROR " << endl;
			break;
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
			cout << "Students of what fakultat do you need?" << endl;
			cout << "We have three fakultat, so please choose one of them:" << endl;
			//by_fakultat(students);
			individum(students);
			//print_obj(students);
			system("pause");
			system("cls");
			break;
		}
		case 0:{
			system("cls");
			break;
			}

		
		}
	}
		

}

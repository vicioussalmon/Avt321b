#include "Header.h"

int main()
{
	while (true) {
		int a;
		int n;
		cout << "Enter the length of list:" << endl;
		cin >> n;
		Student* students = new Student[n];
		random(students, n);
		system("pause");
		system("cls");
		while (true) {
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

				print_obj(students, n);

				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				system("cls");

				PrintFakultet(students, n);

				system("pause");
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				
				individum(students, n);

				system("pause");
				system("cls");
				break;
			}
			case 4: {
				system("cls");
				del(students, n);
				system("pause");
				system("cls");
				break;
			}
			case 5: {
				system("cls");
				add(students,n);
				system("pause");
				system("cls");
				break;
			}
			case 0: {
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
		delete[] students;
	}
}

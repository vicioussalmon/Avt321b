#include "Header.h"

void Osn:: main()
{
	while (true) {
		int a;

		int size = 1000;
		Uchen** List = new  Uchen* [size];
		cout << "Enter the length of list:" << endl;
		cin >> size;

		creating(List, size);

		while (true) {
			cout << "\t\t\tChoose operation that you need:" << endl;
			cout << "\t\t\tShow the list of students - 1" << endl;
			cout << "\t\t\tShow the list of students, that was born after choosen year - 2" << endl;
			cout << "\t\t\tShow the list of students or pupils - 3" << endl;
			cout << "\t\t\tChange person - 4" << endl;
			cout << "\t\t\tDelete choosen person - 5" << endl;
			cout << "\t\t\tAdd new person - 6" << endl;
			cout << "\t\t\tExit - 0" << endl;
			cin >> a;

			switch (a)
			{

			case 1:
			{
				print(List, size);
				system("pause");

				break;
			}
			case 2:
			{
				individum(List, size);

				system("pause");
				break;
			}
			case 3: {
				printplace(List, size);
				system("pause");
				break;
			}
			case 4: {


				edit(List, size);

				system("pause");
				break;
			}
			case 5: {

				del(List, size);
				system("pause");

				break;
			}
			case 6: {

				add(List, size);
				system("pause");

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
		delete[] List;
	}
}
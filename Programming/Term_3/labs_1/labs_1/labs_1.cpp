#include "Header.h"

int main()
{
	setlocale(LC_CTYPE, "ukr");
	srand(time(NULL));
	List* head = NULL;
	List* tail = NULL;


	short int count, nodeSelect, index1, index2, pos;
	system("cls");
	while (nodeSelect != 0) {
		system("cls");
		if (head == NULL) {
			cout << "Какой длинны список вам надобен? \n ";
			cin >> count;
			CreateList(count, &head, tail);
			system("pause");
			system("cls");
		}
		table();
		Printlist(head);
		
		
		cout << "Show the list of students - 1 \n";
		cout << "Show the list of students of fakultat that you need - 2 \n";
		cout << "Show the list of students, that was born after this year - 3 \n";
		cout << "Add new element - 4 \n";
		cout << "Delete element - 5 \n";
		cout << "Clean list - 6 \n";
		cout << "Выход - 0 \n-- ";
		cin >> nodeSelect;
		if (cin.fail()) {
			system("cls");
			cin.clear();
			cin.ignore(32767, '\n');
			cout << " \t\t\tIncorrect input! ERROR! " << endl;
			continue;
			system("pause");
		}

		switch (nodeSelect)
		{
			//Show the list of students
		case 1: {

		}
			//Add new element
		case 4: {
			system("cls");
			Printlist(head);
			cout << "Выберите позицию выбраного эл-та \n ";
			cin >> pos;
			if (pos > CountOflist(head) + 1) {
				cout << "Вы вышли за пределы!" << endl;
				system("pause");
				system("cls");
				break;
			}
			Insert(&head, &tail, pos - 1);
			Printlist(head);
			system("pause");
			system("cls");
			break;
		}
			  //Delete element
		case 5: {
			system("cls");
			Printlist(head);
			cout << "Выберите позицию выбраного эл-та \n-- ";
			cin >> pos;
			Deletelist(&head, &tail, pos - 1);
			Printlist(head);
			system("pause");
			system("cls");
			break;
		}
			  //Clean list
		case 6: {
			system("cls");
			Freelist(&head);
			cout << "Список очищен\n";
			system("pause");
			system("cls");
			nodeSelect = 0;
			break;
		}
		case 0: {
			system("cls");
			FreeList(&head);
			exit(0);
			break;
		}
		default:
			system("cls");
			cout << " \t\t\tОшибка! " << endl;
			break;
		}
	}
}


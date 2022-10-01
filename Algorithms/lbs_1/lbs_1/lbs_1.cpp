// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header.h"

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	DList* Dhead = NULL;
	DList* Dtail = NULL;
	Node* head = NULL;
	Node* begin = NULL;


	short int count, nodeSelect, index1, index2, pos;

	while (true) {
		cout << "Выберите тип тип списка: \n";
		cout << "Однонаправленный - 1 \n";
		cout << "Двунаправленный - 2 \n";
		cout << "Загрузить однонаправленный список - 3 \n";
		cout << "Загрузить двунаправленный список - 4 \n";
		cout << "Выход - 0 \n--";
		cin >> nodeSelect;
		inputCheker();
		switch (nodeSelect)
		{
			///////////////////// Односвязный  ///////////////////////////////////
		case 1:
			while (nodeSelect != 0) {
				system("cls");
				if (head == NULL) {
					cout << "Какой длинны список вам надобен? \n";
					cin >> count;
					//inputCheker();
					CreateNodeConsole(count, &head);
					system("pause");
					system("cls");
				}
				PrintNode(head);
				cout << "Выберите операцию: \n";
				cout << "Добавить новый эл - т - 1 \n";
				cout << "Подсчитать количество эл - тов - 2 \n";
				cout << "Поменять местами два эл - та - 3 \n";
				cout << "Удалить один эл - т - 4 \n";
				cout << "Соеденить два списка в один - 5 \n";
				cout << "Очистить список - 6 \n";
				cout << "Напечатать список - 7 \n";
				cout << "Назад - 0 \n ";
				cin >> nodeSelect;
				//inputCheker();
				switch (nodeSelect)
				{
				case 1:
					system("cls");
					PrintNode(head);
					cout << "Выберите позицию выбранного эл-та: \n ";
					cin >> pos;
					if (pos > CountOfNode(head) + 1) {
						cout << "Вы вышли за пределы" << endl;
						system("pause");
						system("cls");
						break;
					}
					Insert(head, pos - 1);
					PrintNode(head);
					system("pause");
					system("cls");
					break;

				case 2:
					system("cls");
					cout << "Кол-во эл-ов: " << CountOfNode(head) << "\n";
					system("pause");
					system("cls");
					break;

				case 3:
					system("cls");
					PrintNode(head);
					cout << "Первый индекс эл-та: "; cin >> index1;
					cout << "Второй индекс эл-та: "; cin >> index2;
					SwapNode(index1, index2, head);
					PrintNode(head);
					system("pause");
					system("cls");
					break;

				case 4:
					system("cls");
					PrintNode(head);
					cout << "Выберите позицию выбранного эл - та \n ";
					cin >> pos;
					Delete(&head, pos);
					PrintNode(head);
					system("pause");
					system("cls");
					break;
				case 5:
					system("cls");
					cout << "Какой длинны новый список вам надобен? \n ";
					cin >> count;
					CreateNodeConsole(count, &begin);
					cout << "Ваш новый список: ";
					Split(&head, &begin);
					PrintNode(head);
					system("pause");
					system("cls");
					break;

				case 6:
					system("cls");
					FreeNode(&head);
					/*FreeNode(&begin);*/
					cout << "Список очищен\n";
					system("pause");
					system("cls");
					nodeSelect = 0;
					break;
				case 7:
					system("cls");
					cout << "Ваш список: ";
					PrintNode(head);
					break;
				case 0:
					system("cls");
					break;

				default:
					system("cls");
					cout << " \t\t\tНекорректный ввод " << endl;
					break;
				}
			}
			break;


			///////////////////// Двусвязный  ///////////////////////////////////
		case 2:
			system("cls");
			while (nodeSelect != 0) {
				system("cls");
				if (Dhead == NULL) {
					cout << "Какой длинны список вам надобен? \n ";
					cin >> count;
					//inputCheker();
					CreateDListConsole(count, &Dhead, Dtail);
					system("pause");
					system("cls");
				}
				PrintDlist(Dhead);
				cout << "Выберите операцию: \n";
				cout << "Добавить новый эл-т - 1 \n";
				cout << "Подсчитать ко - во эл - ов - 2 \n";
				cout << "Поменять два эл - та - 3 \n";
				cout << "Удалить один эл - т - 4 \n";
				cout << "Очистить список - 5 \n";
				cout << "Напечатать список - 6 \n";
				cout << "Шаг назад - 0 \n-- ";
				cin >> nodeSelect;
				//inputCheker();
				switch (nodeSelect)
				{
				case 1:
					system("cls");
					PrintDlist(Dhead);
					cout << "Выберите позицию выбраного эл-та \n ";
					cin >> pos;
					if (pos > CountOfDlist(Dhead) + 1) {
						cout << "Вы вышли за пределы!" << endl;
						system("pause");
						system("cls");
						break;
					}
					DInsert(&Dhead, &Dtail, pos - 1);
					PrintDlist(Dhead);
					system("pause");
					system("cls");
					break;

				case 2:
					system("cls");
					cout << "Количество эл-тов: " << CountOfDlist(Dhead) << "\n";
					system("pause");
					system("cls");
					break;

				case 3:
					system("cls");
					PrintDlist(Dhead);
					cout << "Первый индекс эл-та: "; cin >> index1;
					cout << "Второй индекс эл-та: "; cin >> index2;
					SwapDlsit(index1, index2, Dhead);
					PrintDlist(Dhead);
					system("pause");
					system("cls");
					break;

				case 4:
					system("cls");
					PrintDlist(Dhead);
					cout << "Выберите позицию выбраного эл-та \n-- ";
					cin >> pos;
					DeleteDlist(&Dhead, &Dtail, pos - 1);
					PrintDlist(Dhead);
					system("pause");
					system("cls");
					break;
				case 5:
					system("cls");
					FreeDlist(&Dhead);
					cout << "Список очищен\n";
					system("pause");
					system("cls");
					nodeSelect = 0;
					break;
				case 6:
					system("cls");
					cout << "Ваш список: ";
					PrintDlist(Dhead);
					break;
				case 0:
					system("cls");
					break;

				default:
					system("cls");
					cout << " \t\t\tОшибка! " << endl;
					break;
				}
			}


			break;

		case 3:
			system("cls");
			LoadFromFile(&head);
			system("pause");
			break;
		case 4:
			system("cls");
			LoadFromFileDlist(&Dhead, &Dtail);
			system("pause");
			break;

		case 0:
			system("cls");
			FreeDlist(&Dhead);
			FreeNode(&head);
			FreeNode(&begin);
			exit(0);
			break;

		default:
			system("cls");
			cout << " \t\t\tНекорректный ввод! " << endl;
			break;
		}

	}



	return 0;
}

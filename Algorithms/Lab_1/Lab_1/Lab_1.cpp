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
		cout << "Выберите тип тип списка: \nОднонаправленный - 1 \nДвунаправленный - 2 \nЗагрузить однонаправленный список - 3 \nЗагрузить двунаправленный список - 4 \nВыход - 0 \n---> "; 
		cin >> nodeSelect;
		inputCheker();
		switch (nodeSelect)
		{
			
			///////////////////// Односвязный  ///////////////////////////////////
			
		case 1:
			while (nodeSelect != 0) {
				system("cls");
				if (head == NULL) {
					cout << "Какой длинны список вам надобен? \n"; cin >> count;
					//inputCheker();
					CreateNodeConsole(count, &head);
					system("pause");
					system("cls");
				}
				PrintNode(head);
				cout << "Выберите операцию: \nДобавить новый эл-т - 1 \nПодсчитать количество эл-тов - 2 \nПоменять местами два эл-та - 3 \nУдалить один эл-т - 4 \nСоеденить два списка в один - 5 \nОчистить список - 6 \nНапечатать список - 7 \nНазад - 0 \n "; 
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
						cout << "Вы зашли далеко" << endl;
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
					cout << "Выберите позицию выбранного эл-та \n "; cin >> pos;
					Delete(&head, pos);
					PrintNode(head);
					system("pause");
					system("cls");
					break;
				case 5:
					system("cls");
					cout << "Какой длинны новый список вам надобен? \n "; cin >> count;
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
					FreeNode(&begin);
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
					cout << " \t\t\tНекорректный ввод" << endl;
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
				cout << "Выберите операцию: \nДобавить новый эл-т - 1 \nПодсчитать ко-во эл-ов - 2 \nПоменять два эл-та - 3 \nУдалить один эл-т - 4 \nОчистить список - 5 \nНапечатать список - 6 \nШаг назад - 0 \n---> "; cin >> nodeSelect;
				//inputCheker();
				switch (nodeSelect)
				{
				case 1:
					system("cls");
					PrintDlist(Dhead);
					cout << "Выберите позицию выбраного эл-та \n "; 
					cin >> pos;
					if (pos > CountOfDlist(Dhead) + 1) {
						cout << "Вы зашли далеко" << endl;
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
					cout << "Выберите позицию выбраного эл-та \n---> "; cin >> pos;
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
					cout << " \t\t\tНекорректный ввод " << endl;
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
			cout << " \t\t\t Некорректный ввод " << endl;
			break;
		}

	}



	return 0;
}
#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	BinaryTree* Root = NULL;

	string FullName = "Student"; int birthdate; short int mark;
	int button; string fileRead;

	ifstream dataFile;



	while (true) {

		cout << "------------------------------------------------------------------------\n"
			<< "--------------------------БИНАРНОЕ---ДЕРЕВО-----------------------------\n"
			<< "------------------------------------------------------------------------\n"
			<< "1 - Создать бинарное дерево вводом через консоль\n"
			<< "2 - Загрузить бинарное дерево из файла\n"
			<< "3 - Печать бинарного дерева в консоль\n"
			<< "4 - Прямой обход дерева\n"
			<< "5 - Симметричный обход дерева\n"
			<< "6 - Обратный обход дерева\n"
			<< "7 - Среднее арифметическое бинарного дерева (середняя оценка студентов)\n"
			<< "8 - Удаление левого поддерева и зануление ветки\n"
			<< "9 - Удаление правого поддерева и зануление ветки\n"
			<< "10 - Удалить узел и занулить его указатель\n"
			<< "11 - Удалить все дерево\n"
			<< "12 - Запись бинарного дерева в файл\n"
			<< "13 - Переписать в новое бинарное дерево (по оценкам)\n"
			<< "0 - Выход\n"
			<< "------------------------------------------------------------------------\n";
		cin >> button;
		switch (button) {
		case 1:

			cout << "Введите количество элементов дерева: ";
			cin >> button;
			for (size_t i = 0; i < button; i++) {
				FullName += to_string(rand() % 10);
				birthdate = rand () % (2005 - 1998 + 1) + 1998;
				mark = rand() % (5 - 1 + 1) + 1;
				CreateTree(Root, FullName, birthdate, mark);
				FullName = "Student";
			}
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				PrintTest(Root);
			break;

		case 2: {
			int count = 0;
			dataFile.open("data.txt");
			while (!dataFile.eof()) {
				getline(dataFile, fileRead);
				count++;
			}

			count = count / 3;
			dataFile.close();
			BinaryTree* data = new BinaryTree[count];
			dataFile.open("data.txt");
			for (int i = 0; i < count; i++) {
				dataFile >> FullName;
				dataFile >> birthdate;
				dataFile >> mark;
				CreateTree(Root, FullName, birthdate, mark);
				FullName = "Student";
			}
			dataFile.close();

			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				PrintTest(Root);

			break;
		}


		case 3:
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				PrintTest(Root);
			break;

		case 4:

			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				PrintTest(Root);

			cout << "Прямий обход дерева: " << endl;
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				pr_obh(Root);
			cout << endl;
			break;

		case 5:

			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				PrintTest(Root);

			cout << "Симметричний обход дерева: " << endl;
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				sm_obh(Root);
			cout << endl;
			break;

		case 6:
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				PrintTest(Root);

			cout << "Обратный обход дерева: " << endl;
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				zb_obh(Root);
			cout << endl;
			break;

		case 7:

			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				PrintTest(Root);

			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				cout << "Средняя оценка студентов составляет " << avarmarkmark(Root) << endl;
			break;

		case 8:

			cout << "Удаление левого поддерева и зануление ветки" << endl;
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				del_left_tree(Root);

			cout << endl;
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				PrintTest(Root);

			break;

		case 9:
			cout << "Удаление правого поддерева и зануление ветки" << endl;
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				del_right_tree(Root);
			cout << endl;
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				PrintTest(Root);
			break;

		case 10:
			cout << "Введите элемент, который хотите удалить: ";
			cin >> mark;
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				del_branch(Root, mark);
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				PrintTest(Root);
			break;

		case 11:
			cout << "Дерево было очищено из памяти. Последующая работа с ним невозможна!" << endl;
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				del(Root);
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				PrintTest(Root);
			break;

		case 12:
			cout << "Запись дерева в файл: " << endl;
			if (!Empty)
				cout << "Дерево не найдено!\n";
			else
				write_trea_in_file(Root);
			break;

		case 13:

			if (!Empty)
				cout << "Дерево не найдено!\n";
			else {
				int TreeSize = size(Root);
				BinaryTree* NewTreeArray = new BinaryTree[TreeSize];
				BinaryTree* NewTree = NULL;
				get_data(Root, NewTreeArray, TreeSize);
				for (size_t i = 0; i < TreeSize; i++) {
					CreateNewTree(NewTree, NewTreeArray[i].FullName, NewTreeArray[i].birthdate, NewTreeArray[i].mark);
				}
				PrintTest(NewTree);
			}
			break;

		default: {
			break;
		}

		}

	}

}


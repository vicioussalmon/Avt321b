
#include "Header.h"




int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	BinaryTree* Root = NULL;

	string FullName = "Person"; int IDpass; short int age;
	int button; string fileRead;

	ifstream dataFile;



	while (true) {

		cout << "1 - Створити бінарне дерево вводом через консоль\n"
			<< "2 - Загрузити бінарне дерево з файлу\n"
			<< "3 - Роздрукувати бінарне дерево в консоль\n"
			<< "4 - Прямий обхід дерева\n"
			<< "5 - Симетричний обхід дерева\n"
			<< "6 - Зворотній обхід дерева\n"
			<< "7 - Середнє арифметичне бінарного дерева (середній вік громадян)\n"
			<< "8 - Видалення лівого піддерева й занулення гілки\n"
			<< "9 - Видалення правого піддерева й занулення гілки\n"
			<< "10 - Видалити вузол й занулити його вказівник\n"
			<< "11 - Видалити все дерево\n"
			<< "12 - Записати бінарне дерево в файл\n"
			<< "13 - Пересипати у нове бінарне дерево (за ID паспорта)\n"
			<< "0 - Завершити роботу програми\n"
			<< "---> ";
		cin >> button;
		switch (button) {
		case 1:

			cout << "Введіть кількість елементів дерева: ";
			cin >> button;
			for (size_t i = 0; i < button; i++) {
				FullName += to_string(rand() % 10);
				IDpass = rand();
				age = rand() % 60 + 20;
				CreateTree(Root, FullName, IDpass, age);
				FullName = "Person";
			}
			if (!Empty)
				cout << "Дерево не знайдено!\n";
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
				dataFile >> IDpass;
				dataFile >> age;
				CreateTree(Root, FullName, IDpass, age);
				FullName = "Person";
			}
			dataFile.close();

			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				PrintTest(Root);

			break;
		}


		case 3:
			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				PrintTest(Root);
			break;

		case 4:

			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				PrintTest(Root);

			cout << "Прямий обхід дерева: " << endl;
			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				pr_obh(Root);
			cout << endl;
			break;

		case 5:

			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				PrintTest(Root);

			cout << "Симетричний обхід дерева: " << endl;
			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				sm_obh(Root);
			cout << endl;
			break;

		case 6:
			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				PrintTest(Root);

			cout << "Зворотній обхід дерева: " << endl;
			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				zb_obh(Root);
			cout << endl;
			break;

		case 7:

			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				PrintTest(Root);

			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				cout << "Середній арефметичний рік громадян складає " << avarageAge(Root) << endl;
			break;

		case 8:

			cout << "Видалення лівого піддерева й занулення гілки" << endl;
			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				del_left_tree(Root);

			cout << endl;
			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				PrintTest(Root);

			break;

		case 9:
			cout << "Видалення правого піддерева й занулення гілки" << endl;
			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				del_right_tree(Root);
			cout << endl;
			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				PrintTest(Root);
			break;

		case 10:
			cout << "Введіть елемент, який хочете видалить: ";
			cin >> age;
			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				del_branch(Root, age);
			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				PrintTest(Root);
			break;

		case 11:
			cout << "Дерево було очищенно з пам'яті. Подальша робота з ним неможлива!" << endl;
			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				del(Root);
			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				PrintTest(Root);
			break;

		case 12:
			cout << "Запис дерева у файл: " << endl;
			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else
				write_trea_in_file(Root);
			break;

		case 13:

			if (!Empty)
				cout << "Дерево не знайдено!\n";
			else {
				int TreeSize = size(Root);
				BinaryTree* NewTreeArray = new BinaryTree[TreeSize];
				BinaryTree* NewTree = NULL;
				get_data(Root, NewTreeArray, TreeSize);
				for (size_t i = 0; i < TreeSize; i++) {
					CreateNewTree(NewTree, NewTreeArray[i].FullName, NewTreeArray[i].IDpass, NewTreeArray[i].age);
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


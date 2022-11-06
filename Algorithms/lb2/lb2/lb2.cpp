#include "Header.h"

int main()
{
	setlocale(LC_ALL,"Russian");
	while (true) {

	int an;
	cout << "Выберете с чем вы хотите работать:" << endl;
	cout << "Стек - 1" << endl;
	cout << "Очередь - 2" << endl;
	cout << "Дек - 3" << endl;
	cout << "Выход - 0" << endl;
	cin >> an;
	switch (an)
	{
	case 1: {
		Stack stack;

		short int button;
		int sizeofStack;

		cout << "\nСоздать стек - 1 \nСтек файлов данных - 2 \nСброс - 3 \nВыход - 0 \n"; cin >> button;
		switch (button)
		{
		case 1:

			if (stack.isNULL()) {
				cout << "Размер стека: "; cin >> sizeofStack;
				stack.CreateStack(sizeofStack);
			}

			cout << endl; stack.show(); cout << endl; stack.write();

			while (button != 0) {
				// menu
				cout << "Поменять местами первый и последний элементы стека - 1\n" <<
					"Развернуть стек - 2\n" <<
					"Удалить каждый второй элемент стека - 3\n" <<
					"Найди максимальный элемент и вставь после него 0 - 4\n" <<
					"Удалить минимальный элемент - 5\n" <<
					"Удалить все элементы, кроме первого - 6\n" <<
					"Удалить все элементы кроме последнего -7\n" <<
					"Назад - 0\n";
				cin >> button;


				switch (button)
				{
				case 1:
					stack.replaceFirstandLast();
					cout << endl; stack.show(); cout << endl;
					stack.write();
					break;
				case 2:
					stack.reverse();
					cout << endl; stack.show(); cout << endl;
					stack.write();
					break;
				case 3:
					stack.deleteEverySecond();
					cout << endl; stack.show(); cout << endl;
					stack.write();
					break;
				case 4:
					stack.findMax0();
					cout << endl; stack.show(); cout << endl;
					stack.write();
					break;
				case 5:
					stack.deleteMin();
					cout << endl; stack.show(); cout << endl;
					stack.write();
					break;
				case 6:
					stack.deletAllExpFrist();
					cout << endl; stack.show(); cout << endl;
					stack.write();
					break;
				case 7:
					stack.deletAllExpLast();
					cout << endl; stack.show(); cout << endl;
					stack.write();
					break;
				case 0:
					break;
				default:
					cout << " \t\t\tНекорректный ввод! ОШИБКА! " << endl;
					break;
				}
			}
			break;

		case 2:

			if (!stack.isNULL()) {
				stack.deleteStack();
			}


			stack.read();
			cout << endl; stack.show(); cout << endl;

			while (button != 0) {
				// menu
				cout << "Поменять местами первый и последний элементы стека - 1\n" <<
					"Развернуть стек - 2\n" <<
					"Удалить каждый второй элемент стека - 3\n" <<
					"Найди максимальный элемент и вставь после него 0 - 4\n" <<
					"Удалить минимальный элемент - 5\n" <<
					"Удалить все элементы, кроме первого - 6\n" <<
					"Удалить все элементы кроме последнего -7\n" <<
					"Назад - 0\n";
				cin >> button;


				switch (button)
				{
				case 1:
					stack.replaceFirstandLast();
					cout << endl; stack.show(); cout << endl;
					stack.write();
					break;
				case 2:
					stack.reverse();
					cout << endl; stack.show(); cout << endl;
					stack.write();
					break;
				case 3:
					stack.deleteEverySecond();
					cout << endl; stack.show(); cout << endl;
					stack.write();
					break;
				case 4:
					stack.findMax0();
					cout << endl; stack.show(); cout << endl;
					stack.write();
					break;
				case 5:
					stack.deleteMin();
					cout << endl; stack.show(); cout << endl;
					stack.write();
					break;
				case 6:
					stack.deletAllExpFrist();
					cout << endl; stack.show(); cout << endl;
					stack.write();
					break;
				case 7:
					stack.deletAllExpLast();
					cout << endl; stack.show(); cout << endl;
					stack.write();
					break;
				case 0:
					break;
				default:
					cout << " \t\t\tНекорректный ввод! ОШИБКА! " << endl;
					break;
				}
			}

		case 3:
			system("cls");
			stack.deleteStack();
			break;
		case 0:
			system("cls");
			stack.deleteStack();
			exit(0);
			break;
		default:
			cout << " \t\t\tНекорректный ввод! ОШИБКА! " << endl;
			break;
			break;
		}
	}
	case 2:{
		Queue queue;
		long int data;
		short int button;
		int sizeofQueue;

		cout << "\nСоздать очередь - 1 \nОчередь файлов данных - 2 \nСброс - 3 \nВыход - 0 \n"; cin >> button;
		switch (button)
		{
		case 1:

			if (queue.amount() == 0) {
				cout << "Размер очереди: "; cin >> sizeofQueue;
				for (size_t i = 0; i < sizeofQueue; i++) {
					cout << "Введите ваши данные: "; cin >> data;
					queue.Push(data);
				}
			}

			cout << endl; queue.show(); cout << endl; queue.write();

			while (button != 0) {
				// menu
				cout << "Вывести размер очереди - 1\n" <<
					"Среднее арифметическое - 2\n" <<
					"Минимальный и максимальный элемент - 3\n" <<
					"Элемент, который стоит перед минимальным элементом - 4\n" <<
					"Назад - 0\n";
				cin >> button;


				switch (button)
				{
				case 1:
					cout << "Размер очереди: " << queue.amount() << endl;
					cout << endl; queue.show(); cout << endl;
					queue.write();
					break;
				case 2:
					queue.ArithmeticMean();
					queue.write();
					break;
				case 3:
					cout << endl; queue.show(); cout << endl;
					queue.MinandMax();
					queue.write();
					break;
				case 4:
					cout << endl; queue.show(); cout << endl;
					queue.beforeMIN();
					queue.write();
					break;
				case 0:
					break;
				default:
					cout << " \t\t\tНекорректный ввод! ОШИБКА! " << endl;
					break;
				}
			}
			break;

		case 2:

			if (queue.amount() > 0) {
				queue.deleteq();
			}


			queue.read();
			cout << endl; queue.show(); cout << endl;

			while (button != 0) {
				// menu
				cout << "Выведите количество очереди - 1\n" <<
					"Среднее арифметическое - 2\n" <<
					"Минимальный и максимальный элемент - 3\n" <<
					"Элемент, который стоит перед минимальным элементом - 4\n" <<
					"Назад - 0\n";
				cin >> button;


				switch (button)
				{
				case 1:
					cout << "Размер очереди: " << queue.amount() << endl;
					cout << endl; queue.show(); cout << endl;
					queue.write();
					break;
				case 2:
					queue.ArithmeticMean();
					queue.write();
					break;
				case 3:
					cout << endl; queue.show(); cout << endl;
					queue.MinandMax();
					queue.write();
					break;
				case 4:
					cout << endl; queue.show(); cout << endl;
					queue.beforeMIN();
					queue.write();
					break;
				case 0:
					break;
				default:
					cout << " \t\t\tНекорректный ввод! ОШИБКА! " << endl;
					break;
				}
			}

		case 3:
			system("cls");
			queue.deleteq();
			break;
		case 0:
			system("cls");
			queue.deleteq();
			exit(0);
			break;
		default:
			cout << " \t\t\tНекорректный ввод! ОШИБКА! " << endl;
			break;
			break;
		}

	  }
	case 3: {
		Deque deque;
		long int data;
		short int button;
		int sizeofQueue;

			cout << "\nСоздать дек - 1 \nДек файлов данных - 2 \nСброс - 3 \nВыход - 0 \n"; cin >> button;
			switch (button)
			{
			case 1: {

				if (deque.isNULL()) {
					cout << "Размер дека: "; cin >> sizeofQueue;
					for (size_t i = 0; i < sizeofQueue; i++) {
						cout << "Введите ваши данные: "; cin >> data;
						deque.PushBack(data);
					}
				}

				cout << endl; deque.show(); cout << endl;
				deque.write();

				while (button != 0) {
					// menu
					cout << "Добавить элемент в начало - 1\n" <<
						"Добавить элемент в конец - 2\n" <<
						"Читать последний элемент - 3\n" <<
						"Назад - 0\n";
					cin >> button;


					switch (button)
					{
					case 1:
						cout << "Введите ваши данные: "; cin >> data;
						deque.PushFront(data);
						cout << endl; deque.show(); cout << endl;
						deque.write();
						break;
					case 2:
						cout << "Введите ваши данные: "; cin >> data;
						deque.PushBack(data);
						cout << endl; deque.show(); cout << endl;
						deque.write();
						break;
					case 3:
						cout << "Последний элемент: " << deque.readLast() << endl;
						break;
					case 0:
						break;
					default:
						cout << " \t\t\tНекорректный ввод! ОШИБКА! " << endl;
						break;
					}
				}
				break;
			}
			case 2: {

				if (!deque.isNULL()) {
					deque.deleted();
				}


				deque.read();
				cout << endl; deque.show(); cout << endl;

				while (button != 0) {
					// menu
					cout << "Добавить элемент в начало - 1\n" <<
						"Добавить элемент в конец - 2\n" <<
						"Читать последний элемент - 3\n" <<
						"Назад - 0\n";
					cin >> button;


					switch (button)
					{
					case 1:
						cout << "Введите ваши данные: "; cin >> data;
						deque.PushFront(data);
						cout << endl; deque.show(); cout << endl;
						deque.write();
						break;
					case 2:
						cout << "Введите ваши данные "; cin >> data;
						deque.PushBack(data);
						cout << endl; deque.show(); cout << endl;
						deque.write();
						break;
					case 3:
						cout << "Последний элемент: " << deque.readLast() << endl;
						break;
					case 0:
						break;
					default:
						cout << " \t\t\tНекорректный ввод! ОШИБКА! " << endl;
						break;
					}
				}
			}
			case 3: {
				system("cls");
				deque.deleted();
				break;
			}
			case 0:
				system("cls");
				deque.deleted();
				exit(0);
				break;
			default:
				cout << " \t\t\tНекорректный ввод! ОШИБКА! " << endl;
				break;
				break;
			}
		
	}
	case 0: {
		system("cls");
		exit(0);
		break;
	}
	  default:
		  cout << " \t\t\tНекорректный ввод! ОШИБКА! " << endl;
		  break;
		  break;
		}

	}
}
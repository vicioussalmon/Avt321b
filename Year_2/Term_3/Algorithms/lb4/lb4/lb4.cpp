#include "Header.h"



int main()
{

	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int operationCounter, button;
	constexpr int size10 = 10;
	constexpr int size100 = 100;
	constexpr int size1000 = 1000;
	constexpr int size10000 = 10000;
	int array10[size10];
	int array100[size100];
	int array1000[size1000];
	int array10000[size10000];


	while (true) {

		cout << "Сортировка выбором - 1\n"
			<< "Сортировка Шелла - 2\n"
			<< "Пирамидальная сортировка - 3\n"
			<< "Выход - 0\n"; cin >> button;
		switch (button)
		{
		case 1:
			while (button != 0) {
				cout << "Выберите размер массива:\n"
					<< "10 - 1\n"
					<< "100 - 2\n"
					<< "1 000 - 3\n"
					<< "10 000 - 4\n"
					<< "Назад - 0\n"; cin >> button;
				switch (button) {

				case 1:

					cout << "Выберите тип массива:\n"
						<< "Случайный массив из файла - 1\n"
						<< "Массив по возрастанию - 2\n"
						<< "Массив по убыванию - 3\n"
						<< "Назад - 0\n"; cin >> button;

					switch (button)
					{
					case 1:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						readChaotically(array10, size10);
						printArray(array10, size10);
						ChooseSort(array10, size10, operationCounter);
						printArray(array10, size10);
						cout << "\nОпераций сортировки выбором 10 случайный -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 2:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createAscending(array10, size10);
						printArray(array10, size10);
						ChooseSort(array10, size10, operationCounter);
						printArray(array10, size10);
						cout << "\nОпераций сортировки выбором 10 по возрастанию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 3:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createDescending(array10, size10);
						printArray(array10, size10);
						ChooseSort(array10, size10, operationCounter);
						printArray(array10, size10);
						cout << "\nОпераций сортировки выбором 10 по убыванию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;

					case 0:
						break;
					default:
						break;
					}
					break;

				case 2:
					cout << "Выберите тип массива:\n"
						<< "Случайный массив из файла - 1\n"
						<< "Массив по возрастанию - 2\n"
						<< "Массив по убыванию - 3\n"
						<< "Назад - 0\n"; cin >> button;

					switch (button)
					{
					case 1:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						readChaotically(array100, size100);
						printArray(array100, size100);
						ChooseSort(array100, size100, operationCounter);
						printArray(array100, size100);
						cout << "\nОпераций сортировки выбором 100 случайный -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 2:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createAscending(array100, size100);
						printArray(array100, size100);
						ChooseSort(array100, size100, operationCounter);
						printArray(array100, size100);
						cout << "\nОпераций сортировки выбором 100 по возрастанию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 3:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createDescending(array100, size100);
						printArray(array100, size100);
						ChooseSort(array100, size100, operationCounter);
						printArray(array100, size100);
						cout << "\nОпераций сортировки выбором 100 по убыванию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;

					case 0:
						break;
					default:
						break;
					}
					break;

				case 3:
					cout << "Выберите тип массива:\n"
						<< "Случайный массив из файла - 1\n"
						<< "Массив по возрастанию - 2\n"
						<< "Массив по убыванию - 3\n"
						<< "Назад - 0\n"; cin >> button;

					switch (button)
					{
					case 1:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						readChaotically(array1000, size1000);
						printArray(array1000, size1000);
						ChooseSort(array1000, size1000, operationCounter);
						printArray(array1000, size1000);
						cout << "\nОпераций сортировки выбором 1000 случайный -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 2:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createAscending(array1000, size1000);
						printArray(array1000, size1000);
						ChooseSort(array1000, size1000, operationCounter);
						printArray(array1000, size1000);
						cout << "\nОпераций сортировки выбором 1000 по возрастанию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 3:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createDescending(array1000, size1000);
						printArray(array1000, size1000);
						ChooseSort(array1000, size1000, operationCounter);
						printArray(array1000, size1000);
						cout << "\nОпераций сортировки выбором 1000 по убыванию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;

					case 0:
						break;
					default:
						break;
					}
					break;


				case 4:
					cout << "Выберите тип массива:\n"
						<< "Случайный массив из файла - 1\n"
						<< "Массив по возрастанию - 2\n"
						<< "Массив по убыванию - 3\n"
						<< "Назад - 0\n"; cin >> button;

					switch (button)
					{
					case 1:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						readChaotically(array10000, size10000);
						printArray(array10000, size10000);
						ChooseSort(array10000, size10000, operationCounter);
						printArray(array10000, size10000);
						cout << "\nОпераций сортировки выбором 10000 случайный -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 2:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createAscending(array10000, size10000);
						printArray(array10000, size10000);
						ChooseSort(array10000, size10000, operationCounter);
						printArray(array10000, size10000);
						cout << "\nОпераций сортировки выбором 10000 по возрастанию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 3:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createDescending(array10000, size10000);
						printArray(array10000, size10000);
						ChooseSort(array10000, size10000, operationCounter);
						printArray(array10000, size10000);
						cout << "\nОпераций сортировки выбором 10000 по убыванию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;

					case 0:
						break;
					default:
						break;
					}
					break;


				default:
					break;
				}
			}
			break;


		case 2:
			while (button != 0) {
				cout << "Выберите размер массива:\n"
					<< "10 - 1\n"
					<< "100 - 2\n"
					<< "1 000 - 3\n"
					<< "10 000 - 4\n"
					<< "Назад - 0\n"; cin >> button;
				switch (button) {

				case 1:

					cout << "Выберите тип массива:\n"
						<< "Случайный массив из файла - 1\n"
						<< "Массив по возрастанию - 2\n"
						<< "Массив по убыванию - 3\n"
						<< "Назад - 0\n"; cin >> button;

					switch (button)
					{
					case 1:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						readChaotically(array10, size10);
						printArray(array10, size10);
						ShellSort(array10, size10, operationCounter);
						printArray(array10, size10);
						cout << "\nОпераций сортировки Шелла 10 случайный -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 2:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createAscending(array10, size10);
						printArray(array10, size10);
						ShellSort(array10, size10, operationCounter);
						printArray(array10, size10);
						cout << "\nОпераций сортировки Шелла 10 по возрастанию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 3:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createDescending(array10, size10);
						printArray(array10, size10);
						ShellSort(array10, size10, operationCounter);
						printArray(array10, size10);
						cout << "\nОпераций сортировки Шелла 10 по убыванию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;

					case 0:
						break;
					default:
						break;
					}
					break;

				case 2:
					cout << "Выберите тип массива:\n"
						<< "Случайный массив из файла - 1\n"
						<< "Массив по возрастанию - 2\n"
						<< "Массив по убыванию - 3\n"
						<< "Назад - 0\n"; cin >> button;

					switch (button)
					{
					case 1:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						readChaotically(array100, size100);
						printArray(array100, size100);
						ShellSort(array100, size100, operationCounter);
						printArray(array100, size100);
						cout << "\nОпераций сортировки Шелла 100 случайный -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 2:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createAscending(array100, size100);
						printArray(array100, size100);
						ShellSort(array100, size100, operationCounter);
						printArray(array100, size100);
						cout << "\nОпераций сортировки Шелла 100 по возрастанию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 3:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createDescending(array100, size100);
						printArray(array100, size100);
						ShellSort(array100, size100, operationCounter);
						printArray(array100, size100);
						cout << "\nОпераций сортировки Шелла 100 по убыванию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;

					case 0:
						break;
					default:
						break;
					}
					break;

				case 3:
					cout << "Выберите тип массива:\n"
						<< "Случайный массив из файла - 1\n"
						<< "Массив по возрастанию - 2\n"
						<< "Массив по убыванию - 3\n"
						<< "Назад - 0\n"; cin >> button;

					switch (button)
					{
					case 1:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						readChaotically(array1000, size1000);
						printArray(array1000, size1000);
						ShellSort(array1000, size1000, operationCounter);
						printArray(array1000, size1000);
						cout << "\nОпераций сортировки Шелла 1000 случайный -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 2:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createAscending(array1000, size1000);
						printArray(array1000, size1000);
						ShellSort(array1000, size1000, operationCounter);
						printArray(array1000, size1000);
						cout << "\nОпераций сортировки Шелла 1000 по возрастанию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 3:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createDescending(array1000, size1000);
						printArray(array1000, size1000);
						ShellSort(array1000, size1000, operationCounter);
						printArray(array1000, size1000);
						cout << "\nОпераций сортировки Шелла 1000 по убыванию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;

					case 0:
						break;
					default:
						break;
					}
					break;


				case 4:
					cout << "Выберите тип массива:\n"
						<< "Случайный массив из файла - 1\n"
						<< "Массив по возрастанию - 2\n"
						<< "Массив по убыванию - 3\n"
						<< "Назад - 0\n"; cin >> button;

					switch (button)
					{
					case 1:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						readChaotically(array10000, size10000);
						printArray(array10000, size10000);
						ShellSort(array10000, size10000, operationCounter);
						printArray(array10000, size10000);
						cout << "\nОпераций сортировки Шелла 10000 случайный -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 2:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createAscending(array10000, size10000);
						printArray(array10000, size10000);
						ShellSort(array10000, size10000, operationCounter);
						printArray(array10000, size10000);
						cout << "\nОпераций сортировки Шелла 10000 по возрастанию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 3:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createDescending(array10000, size10000);
						printArray(array10000, size10000);
						ShellSort(array10000, size10000, operationCounter);
						printArray(array10000, size10000);
						cout << "\nОпераций сортировки Шелла 10000 по убыванию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;

					case 0:
						break;
					default:
						break;
					}
					break;


				default:
					break;
				}
			}
			break;

		case 3:
			while (button != 0) {
				cout << "Выберите размер массива:\n"
					<< "10 - 1\n"
					<< "100 - 2\n"
					<< "1 000 - 3\n"
					<< "10 000 - 4\n"
					<< "Назад - 0\n"; cin >> button;
				switch (button) {

				case 1:

					cout << "Выберите тип массива:\n"
						<< "Случайный массив из файла - 1\n"
						<< "Массив по возрастанию - 2\n"
						<< "Массив по убыванию - 3\n"
						<< "Назад - 0\n"; cin >> button;

					switch (button)
					{
					case 1:
						cout << endl << "/////////////////////////////////////////////////" << endl;
					    readChaotically(array10, size10);
						printArray(array10, size10);
						PiramidSort(array10, size10, operationCounter);
						printArray(array10, size10);
						cout << "\nОпераций пирамидальной сортировки 10 случайный -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 2:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createAscending(array10, size10);
						printArray(array10, size10);
						PiramidSort(array10, size10, operationCounter);
						printArray(array10, size10);
						cout << "\nОпераций пирамидальной сортировки 10 по возрастанию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 3:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createDescending(array10, size10);
						printArray(array10, size10);
						PiramidSort(array10, size10, operationCounter);
						printArray(array10, size10);
						cout << "\nОпераций пирамидальной сортировки 10 по убыванию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;

					case 0:
						break;
					default:
						break;
					}
					break;

				case 2:
					cout << "Выберите тип массива:\n"
						<< "Случайный массив из файла - 1\n"
						<< "Массив по возрастанию - 2\n"
						<< "Массив по убыванию - 3\n"
						<< "Назад - 0\n"; cin >> button;

					switch (button)
					{
					case 1:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						readChaotically(array100, size100);
						printArray(array100, size100);
						PiramidSort(array100, size100, operationCounter);
						printArray(array100, size100);
						cout << "\nОпераций пирамидальной сортировки 100 случайный -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 2:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createAscending(array100, size100);
						printArray(array100, size100);
						PiramidSort(array100, size100, operationCounter);
						printArray(array100, size100);
						cout << "\nОпераций пирамидальной сортировки 100 по возрастанию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 3:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createDescending(array100, size100);
						printArray(array100, size100);
						PiramidSort(array100, size100, operationCounter);
						printArray(array100, size100);
						cout << "\nОпераций пирамидальной сортировки 100 по убыванию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;

					case 0:
						break;
					default:
						break;
					}
					break;

				case 3:
					cout << "Выберите тип массива:\n"
						<< "Случайный массив из файла - 1\n"
						<< "Массив по возрастанию - 2\n"
						<< "Массив по убыванию - 3\n"
						<< "Назад - 0\n"; cin >> button;

					switch (button)
					{
					case 1:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						readChaotically(array1000, size1000);
						printArray(array1000, size1000);
						PiramidSort(array1000, size1000, operationCounter);
						printArray(array1000, size1000);
						cout << "\nОпераций пирамидальной сортировки 1000 случайный -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 2:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createAscending(array1000, size1000);
						printArray(array1000, size1000);
						PiramidSort(array1000, size1000, operationCounter);
						printArray(array1000, size1000);
						cout << "\nОпераций пирамидальной сортировки 1000 по возрастанию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 3:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createDescending(array1000, size1000);
						printArray(array1000, size1000);
						PiramidSort(array1000, size1000, operationCounter);
						printArray(array1000, size1000);
						cout << "\nОпераций пирамидальной сортировки 1000 по убыванию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;

					case 0:
						break;
					default:
						break;
					}
					break;


				case 4:
					cout << "Выберите тип массива:\n"
						<< "Случайный массив из файла - 1\n"
						<< "Массив по возрастанию - 2\n"
						<< "Массив по убыванию - 3\n"
						<< "Назад - 0\n"; cin >> button;

					switch (button)
					{
					case 1:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						readChaotically(array10000, size10000);
						printArray(array10000, size10000);
						PiramidSort(array10000, size10000, operationCounter);
						printArray(array10000, size10000);
						cout << "\nОпераций пирамидальной сортировки 10000 случайный -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 2:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createAscending(array10000, size10000);
						printArray(array10000, size10000);
						PiramidSort(array10000, size10000, operationCounter);
						printArray(array10000, size10000);
						cout << "\nОпераций пирамидальной сортировки 10000 по возрастанию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;
					case 3:
						cout << endl << "/////////////////////////////////////////////////" << endl;
						createDescending(array10000, size10000);
						printArray(array10000, size10000);
						PiramidSort(array10000, size10000, operationCounter);
						printArray(array10000, size10000);
						cout << "\nОпераций пирамидальной сортировки 10000 по убыванию -- " << operationCounter << endl;
						cout << "/////////////////////////////////////////////////" << endl << endl;
						break;

					case 0:
						break;
					default:
						break;
					}
					break;


				default:
					break;
				}
			}
			break;


		case 0:
			exit(0);
			break;
		default:
			break;
		}





	}


	/*readChaotically(array, size);
	printArray(array, size);
	ChooseSort(array, size, operationCounter);
	printArray(array, size);

	cout << "\nOperations --> " << operationCounter << endl;



	cout << " \n//////////////////////////////////////////////////////////////////////////////////////// \n";

	readChaotically(array, size);
	printArray(array, size);
	PiramidSort(array, size, operationCounter);
	printArray(array, size);

	cout << "\nOperations --> " << operationCounter << endl;


	cout << " \n//////////////////////////////////////////////////////////////////////////////////////// \n";
	readChaotically(array, size);
	printArray(array, size);
	PiramidSort(array, size, operationCounter);
	printArray(array, size);

	cout << "\nOperations --> " << operationCounter << endl;*/



}


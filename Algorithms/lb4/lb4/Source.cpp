#include "Header.h"





void printArray(int* array, int size)
{
	for (size_t i = 0; i < size; i++)
		cout << array[i] << setw(4);
	cout << setw(0) << endl;
}



void createChaotically(int* array, int size) {
	for (size_t i = 0; i < size; i++)
		array[i] = rand() % 100;
}
void readChaotically(int* array, int size) {
	ifstream file("Array.txt");
	for (size_t i = 0; i < size; i++) {
		file >> array[i];
	}
	file.close();
}
void createAscending(int* array, int size) {
	for (size_t i = 0; i < size; i++)
		array[i] = i;
}
void createDescending(int* array, int size) {
	for (int i = size, j = 0; j < size; i--, j++)
		array[j] = i;
}


void ChooseSort(int* array, int size, int& operationCounter)
{
	operationCounter = 0;
	for (int startIndex = 0; startIndex < size - 1; ++startIndex, operationCounter++)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			if (array[currentIndex] < array[smallestIndex]) {
				smallestIndex = currentIndex;
				operationCounter++;
			}
		}
		swap(array[startIndex], array[smallestIndex]);
	}
}

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

void heapify(int* array, int size, int i, int& operationCounter)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

	// Если левый дочерний элемент больше корня
	if (l < size && array[l] > array[largest]) {
		largest = l;
		operationCounter++;
	}
	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < size && array[r] > array[largest]) {
		largest = r;
		operationCounter++;
	}
	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(array[i], array[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(array, size, largest, operationCounter);

	}
}
void PiramidSort(int* array, int size, int& operationCounter)
{
	operationCounter = 0;
	// Построение кучи (перегруппируем массив)
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(array, size, i, operationCounter);
		
	}

	// Один за другим извлекаем элементы из кучи
	for (int i = size - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(array[0], array[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(array, i, 0, operationCounter);
		
	}
}

void ShellSort(int* array, int size, int& operationCounter)
{
	operationCounter = 0;
		for (int step = size / 2; step > 0; step /= 2, operationCounter++)
		{
			for (int i = step; i < size; i += 1, operationCounter++)
			{
				int j = i;

				while (j >= step && array[j - step] > array[i])
				{
					swap(array[j], array[j - step]);
					j -= step;
					operationCounter++;
				}
				operationCounter++;
			}
			operationCounter++;
		}
	

}

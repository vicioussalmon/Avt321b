#include "Header.h"

////////////////////Стек///////////////////////////////////////////////
string pathData = "dataS.txt";




void Stack::PushStack(long int& newData)
{

	Stack* newStack = new Stack;

	newStack->data = newData;
	newStack->next = this->root;
	this->root = newStack;
	size++;

}


long int Stack::PopStack()
{

	Stack* deletedITM = this->root;

	float tempData = deletedITM->data;
	this->root = deletedITM->next;
	delete deletedITM; deletedITM = NULL;
	size--;

	return tempData;
}


void Stack::CreateStack(int amount)
{
	if (amount == 0) {
		cout << "\tРазмер стека не может быть нулевым!\n\t Попробуйте еще раз.\n";
		return;
	}
	long int tempData;
	for (size_t i = 0; i < amount; i++) {
		cout << "Введите ваши данные: "; 
		cin >> tempData;
		PushStack(tempData);
	}

}


bool Stack::isNULL()
{
	if (size == 0)
		return true;
	else
		return false;
}


void Stack::show()
{

	if (size == 0)
		cout << "\tСтек не найден!\n";

	else {
		cout << "Стек: ";
		Stack* current = this->root;
		while (current != NULL) {
			cout << current->data << " -> ";
			current = current->next;
		} cout << endl;
	}
}

void Stack::deleteStack()
{
	while (root) PopStack();
	size = 0;

	cout << "\tСтек удален!\n";

}

void Stack::replaceFirstandLast()
{
	long int first = root->data, last;

	Stack* current = root;
	for (size_t i = 0; i < size - 1; i++)
		current = current->next;
	last = current->data;

	swap(first, last);
	root->data = first;
	current->data = last;


}

void Stack::reverse()
{
	int tempSize = size;
	long int* tempStack = new long int[size];

	for (int i = 0; root != NULL; i++)
		tempStack[i] = PopStack();

	for (size_t i = 0; i < tempSize; i++)
		PushStack(tempStack[i]);


	delete[] tempStack;
	tempStack = NULL;

}

void Stack::deleteEverySecond()
{
		int newSize;
		int oldSize = this->size;
		float transformSize = float(oldSize) / 2;

		if (transformSize - (oldSize / 2) > 0)
			newSize = int(transformSize + 1);
		else
			newSize = int(transformSize);

		float* tempFullStack = new float[oldSize];
		long int* newStack = new long int[newSize];

		for (int i = 0; root != NULL; i++)
			tempFullStack[i] = PopStack();

		for (int i = 0, j = 0; j < newSize; j++, i += 2)
			newStack[j] = tempFullStack[i];


		for (size_t i = 0; i < newSize; i++)
			PushStack(newStack[newSize - i - 1]);


		delete[] newStack; newStack = NULL;
		delete[] tempFullStack; tempFullStack = NULL;

	


}

void Stack::findMax0()
{
	int oldSize = this->size;
	long int* tempFullStack = new long int[oldSize];
	long int* newStack = new long int[oldSize + 1];

	for (int i = 0; root != NULL; i++)
		tempFullStack[i] = PopStack();

	int max = INT_MIN;
	for (size_t i = 0; i < oldSize; i++) {
		if (tempFullStack[i] > max) {
			max = tempFullStack[i];
		}
	}

	cout << "Максимальный элемент: " << max << endl;

	short int flag = 0;

	for (size_t j = 0, i = 0; j < oldSize + 1; j++) {
		if (max == tempFullStack[i] and flag == 0) {
			newStack[j] = 0;
			j++; flag = 1;
		}
		newStack[j] = tempFullStack[i]; i++;


	}

	for (size_t i = 0; i < oldSize + 1; i++)
		PushStack(newStack[oldSize - i]);

	delete[] newStack; newStack = nullptr;
	delete[] tempFullStack; tempFullStack = nullptr;
}

void Stack::deleteMin()
{

	int oldSize = this->size;
	long int* tempFullStack = new long int[oldSize];
	long int* newStack = new long int[oldSize - 1];

	for (int i = 0; root != NULL; i++)
		tempFullStack[i] = PopStack();

	int min = INT_MAX;
	for (size_t i = 0; i < oldSize; i++) {
		if (tempFullStack[i] < min) {
			min = tempFullStack[i];
		}
	}

	cout << "Максимальный элемент: " << min << endl;

	short int flag = 0;

	for (size_t j = 0, i = 0; j < oldSize - 1; j++) {
		if (min == tempFullStack[i] and flag == 0) {
			i++; flag = 1;
		}
		newStack[j] = tempFullStack[i]; i++;


	}


	for (size_t i = 0; i < oldSize - 1; i++)
		PushStack(newStack[(oldSize - 1) - i - 1]);

	delete[] newStack; newStack = nullptr;
	delete[] tempFullStack; tempFullStack = nullptr;


}

void Stack::deletAllExpFrist()
{

	int oldSize = this->size;
	long int* tempFullStack = new long int[1];

	for (int i = 0; root != NULL; i++) {
		if (i == (oldSize - 1)) {
			tempFullStack[0] = PopStack();
		}
		else PopStack();
	}
	PushStack(tempFullStack[0]);


	delete[] tempFullStack; tempFullStack = nullptr;

}

void Stack::deletAllExpLast()
{

	int oldSize = this->size;
	long int* tempFullStack = new long int[1];

	for (int i = 0; root != NULL; i++) {
		if (i == 0) {
			tempFullStack[0] = PopStack();
		}
		else PopStack();
	}
	PushStack(tempFullStack[0]);

	delete[] tempFullStack; tempFullStack = nullptr;
}

void Stack::read()
{

	ifstream dataFile;

	dataFile.open(pathData);

	if (dataFile.is_open()) {
		cout << "\tЧтение из файла успешно завершено!\n";
		long int temp;
		while (!dataFile.eof()) {
			dataFile >> temp;
			PushStack(temp);
		}
		reverse();
	}

	else
		cout << "\tЧтение из файла невозможно!\n";


	dataFile.close();


}

void Stack::write()
{
	ofstream dataFile;

	dataFile.open(pathData);



	if (size == 0) {
		cout << "\tСтек не найден!\n";
		cout << "\tЗапись в файл невозможна!\n";
	}


	else {
		cout << "Стек: ";
		Stack* current = this->root;
		while (current != NULL) {
			dataFile << " " << current->data;
			current = current->next;
		}


		if (dataFile.is_open()) {
			//cout << "\tWriting to the file was successful!\n";
		}

		else
			cout << "\tЗапись в файл невозможна!\n";
	}

	dataFile.close();
}
//////////////////////////////////Очередь//////////////////////////////////
string dataPath2 = "dataQ.txt";


void Queue::Push(const long int& data)
{

	Queue* temp = new Queue;
	temp->next = 0;
	temp->data = data;
	if (tail != NULL)
		tail->next = temp;
	if (size == 0)
		head = tail = temp;
	else
		tail = temp;
	size++;


}

void Queue::show()
{

	if (size != 0) {

		Queue* temp = head;

		while (temp->next != 0)
		{
			cout << temp->data << " --> ";
			temp = temp->next;
		}

		cout << temp->data << endl;
	}
	else
		cout << "\tОчередь не существует!\n";

}

void Queue::ArithmeticMean()
{
	long int* tempQueu = new long int[size];

	if (size != 0) {

		Queue* temp = head;

		for (size_t i = 0; i < size; i++) {
			tempQueu[i] = temp->data;
			temp = temp->next;
		}

		float arithmeticMean = 0;
		for (size_t i = 0; i < size; i++) {
			//cout << tempQueu[i] << " --> ";
			arithmeticMean += tempQueu[i];
		} //cout << endl;
		cout << "Арифмеическое значение: " << arithmeticMean / size << endl;

	}
	else
		cout << "\tОчередь не существует!\n";





	delete[] tempQueu; tempQueu = NULL;
}

void Queue::MinandMax()
{

	long int* tempQueu = new long int[size];

	if (size != 0) {

		Queue* temp = head;

		for (size_t i = 0; i < size; i++) {
			tempQueu[i] = temp->data;
			temp = temp->next;
		}

		int max = INT_MIN, min = INT_MAX;

		for (size_t i = 0; i < size; i++) {

			if (tempQueu[i] > max)
				max = tempQueu[i];
			if (tempQueu[i] < min)
				min = tempQueu[i];

		} cout << "Максимум: " << max << " Минимум: " << min << endl;

	}
	else
		cout << "\tОчередь не существует!\n";


	delete[] tempQueu; tempQueu = NULL;


}

void Queue::beforeMIN()
{

	long int* tempQueu = new long int[size];

	if (size != 0) {

		Queue* temp = head;

		for (size_t i = 0; i < size; i++) {
			tempQueu[i] = temp->data;
			temp = temp->next;
		}

		int flag, min = INT_MAX;

		for (size_t i = 0; i < size; i++) {

			if (tempQueu[i] < min) {
				min = tempQueu[i]; flag = i;
			}


		}
		if (flag == 0)
			cout << "Этот элемент еще не существует.\n";
		else
			cout << "Соседний от минимального элемента: " << tempQueu[flag - 1] << endl;

	}
	else
		cout << "\tОчередь не существует!\n";


	delete[] tempQueu; tempQueu = NULL;




}

void Queue::read()
{

	ifstream dataFile;

	dataFile.open(dataPath2);

	if (dataFile.is_open()) {
		cout << "\tЧтение из файла было успешным!\n";
		long int temp;
		while (!dataFile.eof()) {
			dataFile >> temp;
			Push(temp);
		}

	}

	else
		cout << "\tЧтение из файла невозможно!\n";


	dataFile.close();


}

void Queue::write()
{
	ofstream dataFile;

	dataFile.open(dataPath2);



	if (size == 0) {
		cout << "\tОчередь не найдена!\n";
		cout << "\tЗапись в файл не возможна!\n";
	}


	else {
		Queue* current = this->head;
		while (current != NULL) {
			dataFile << " ";
			dataFile << current->data;
			current = current->next;
		}


		//if (dataFile.is_open())
		//	cout << "\tWriting to the file was successful!\n";
		//else
		//	cout << "\tWriting to the file was not successful!\n";
	}

	dataFile.close();
}
///////////////Дек////////////////////////////////
string dataPath3 = "dataD.txt";

void Deque::PushBack(const long int& data)
{

	Deque* temp = new Deque;
	temp->next = NULL;
	temp->data = data;
	temp->prev = tail;
	if (tail != NULL)
		tail->next = temp;
	if (size == 0)
		head = tail = temp;
	else
		tail = temp;
	size++;

}

void Deque::PushFront(const long int& data)
{

	Deque* temp = new Deque;
	temp->data = data;
	temp->prev = NULL;
	if (size == 0)
		head = tail = temp;
	else {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}

	size++;

}

void Deque::show()
{

	if (size != 0) {

		Deque* temp = head;

		while (temp->next != 0)
		{
			cout << temp->data << " --> ";
			temp = temp->next;
		}

		cout << temp->data << endl;
	}
	else
		cout << "\t Дека не существует!\n";


}


void Deque::read()
{

	ifstream dataFile;

	dataFile.open(dataPath3);

	if (dataFile.is_open()) {
		cout << "\tЧтение из файла было успешным!\n";
		long int temp;
		while (!dataFile.eof()) {
			dataFile >> temp;
			PushBack(temp);
		}

	}

	else
		cout << "\tЧтение из файла не возможно!\n";


	dataFile.close();


}

void Deque::write()
{
	ofstream dataFile;

	dataFile.open(dataPath3);



	if (size == 0) {
		cout << "\tДек не найден!\n";
		cout << "\tЧтение из файла не возможно!\n";
	}


	else {
		Deque* current = this->head;
		while (current != NULL) {
			dataFile << " ";
			dataFile << current->data;
			current = current->next;
		}


		/*if (dataFile.is_open())
			cout << "\tWriting to the file was successful!\n";
		else
			cout << "\tWriting to the file was not successful!\n";*/
	}

	dataFile.close();
}
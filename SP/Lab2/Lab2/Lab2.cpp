#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include <vector>
#include <filesystem>

#define NO_OF_CHARS 256

using namespace std;
ifstream fin;

void searching(const char* filepath);
bool Boyer(char* txt, char* pat, int size);
void in_file(const string& current_st);


void main() {

	system("chcp 1251");//вывод руских символов 

	
	system("cls");

	const char directory[] = { "D:\\Avt321b" };//путь папки
	in_file(directory);

	system("pause");
	return;
}

void in_file(const string& current_st)//передаем путь папки
{
	for (const auto& file : filesystem::directory_iterator(current_st))//перебираем папки//функция вызывает проход по всем папкам пути
	{
		if (filesystem::is_directory(file))
		{
			in_file(file.path().string());//вызов функции рекурсивно//заход в папку пока она не дойдет до последней папки
		}
		else//доходит до последней папки-ищет вирус
		{
			searching(file.path().string().c_str());
		}
	}
}

bool Boyer(char* block, char* virus_word, int n)
{
	int m = strlen(virus_word);

	int s = 0;
	while (s <= (n - m))
	{
		int j = m - 1;

		while (j >= 0 && virus_word[j] == block[s + j])
			j--;

		if (j < 0)
		{
			s += (s + m < n) ? m - block[s + m] : 1;
			return true;
		}

		else {
			s += max(1, j - block[s + j]);
		}
	}
	return false;
}

void searching(const char* filepath) {//передаем путь папки

	char virus_word[] = "virus";//объявляем слово для поиска
	int size = strlen(virus_word);//размер слова


	int blockn = 60;//считывает по 60 байт

	//в массивы переписываем файлы которые будут считываться из файлов, счиывает по 60 байт
	char* blockread = new char[blockn];
	blockread[blockn] = '\0';

	int temp_read_size = blockn + size;
	char* blocktempread = new char[temp_read_size];
	blocktempread[temp_read_size] = '\0';

	char* blocktemp = new char[size];
	blocktemp[size] = '\0';

	bool flagfirst = true;//проверка какой раз заходим в цикл
	bool findedvirus = false;//найден вирус или не найден

	fin.open(filepath);//открываем файл

	while (!fin.eof()) {//проходимся по файлу пока он не закончится

		if (flagfirst) {//если 1й проход
			fin.read(blockread, blockn);//начинаем считывать. считываем 60 байт
			findedvirus = Boyer(blockread, virus_word, fin.gcount());//вызываем функцию буера мура//возвращаем тру если вирус найден

			if (findedvirus) {
				cout << filepath;//где вирус лежит
				cout << "\t\t\tVirus founded!\n";
				break;
			}
			else {//если блок не первый
				//для избегания разрыва слова считываем меньше 65 байт
				for (int i = blockn - size, c = 0; i < blockn; i++, c++)
				{
					blocktemp[c] = blockread[i];
				}
			}
			flagfirst = false;
		}
		else {
			fin.read(blockread, blockn);//опять считываем в массив блокрид перекидываем 5 символов которые можем потерять

			for (int i = 0, j = 0; i < temp_read_size; i++)
			{
				if (i < size) {
					blocktempread[i] = blocktemp[i];
				}
				else
				{
					blocktempread[i] = blockread[j];
					j++;
				}
			}
			findedvirus = Boyer(blocktempread, virus_word, temp_read_size);//функция на проверку

			if (findedvirus) {//если нашли
				cout << filepath;
				cout << "\t\t\tVirus founded!\n";
				break;
			}
			else {//если нет, то опять считываем 65 символов
				for (int i = temp_read_size - size, c = 0; i < temp_read_size; i++, c++)
				{
					blocktemp[c] = blocktempread[i];
				}

			}
		}
	}


	fin.close();//файл закрываем

	
}
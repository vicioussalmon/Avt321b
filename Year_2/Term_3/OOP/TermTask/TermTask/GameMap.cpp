#include "GameMap.h"

GameMap::GameMap()
{
	size.x = 0;
	size.y = 0;

	length = 0;

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++)
	{
		map[i] = new int[size.y];
	}
	//Обнуляем кажый эл-т
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++) {
			map[i][j] = 0;
		}
	}
}

GameMap::GameMap(Vector2 _size, int l)
{
	size = _size;

	length = l;

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++)
	{
		map[i] = new int[size.y];
	}
	//Обнуляем кажый эл-т
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++) {
			map[i][j] = 0;
		}
	}
}

GameMap::GameMap(int i, int j, int l)
{
	//инициализируем игровую карту
	size.x = i;
	size.y = j;

	length = l;

	map = new int* [size.x];
	for (i = 0; i < size.x; i++)
	{
		map[i] = new int[size.y];
	}
	//Обнуляем кажый эл-т
	for (i = 0; i < size.x; i++)
	{
		for (j = 0; j < size.y; j++) {
			map[i][j] = 0;
		}
	}
}

GameMap::~GameMap()
{
	//очищаем матрицу
	for (int i = 0; i < size.x; i++)
	{
		delete[] map[i];
	}
	delete[] map;
}

bool GameMap::SetPosition(Vector2 cell, int c)
{
	if (IsEmpty(cell)) {
		map[cell.x][cell.y] = c;
	}
	else {
		return false;
	}
}

bool GameMap::IsEmpty(Vector2 cell)
{
	if (map[cell.x][cell.y] == 0)
		return true;
	else
		return false;
}

bool GameMap::IsEmpty(int i, int j)
{
	if (map[i][j] == 0)
		return true;
	else
		return false;
}

void GameMap::SetMap(Vector2 _size, int l)
{
	size = _size;

	length = l;

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++)
	{
		map[i] = new int[size.y];
	}
	//Обнуляем кажый эл-т
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++) {
			map[i][j] = 0;
		}
	}
}

void GameMap::SetMap(int i, int j, int l)
{
	//инициализируем игровую карту
	size.x = i;
	size.y = j;

	length = l;

	map = new int* [size.x];
	for (i = 0; i < size.x; i++)
	{
		map[i] = new int[size.y];
	}
	//Обнуляем кажый эл-т
	for (i = 0; i < size.x; i++)
	{
		for (j = 0; j < size.y; j++) {
			map[i][j] = 0;
		}
	}
}

int GameMap::GetValue(Vector2 cell)
{
	return map[cell.x][cell.y];
}

int GameMap::GetValue(int i, int j)
{
	return map[i][j];
}

int GameMap::CheckList(vector<int> a)
{
	if (a.size() < length)
		return 0;

	//флажки победы игроков
	bool winPl1 = false;
	bool winPl2 = false;

	int count1 = 0, count2 = 0;

	//проверка набранных очков
	//крестики
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i; j < i + length; j++) {
			if (j < a.size())
			{
				if (a[j] == 1) {
					count1++;
				}
			}
			else
				break;
		}
		if (count1 >= length) {
			winPl1 = true;
			break;
		}
		count1 = 0;

	}
	//нолики
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i; j < i + length; j++) {
			if (j < a.size())
			{
				if (a[j] == 2) {
					count2++;
				}
			}
			else
				break;
		}
		if (count2 >= length) {
			winPl2 = true;
			break;
		}
		count2 = 0;
	}

	//вывод результата
	if (winPl1 && winPl2)
	{
		return 3;//ничья
	}
	else if (!winPl1 && winPl2)
	{
		return 2;//победил 2
	}
	else if (winPl1 && !winPl2)
	{
		return 1;//победил 1
	}
	else
		return 0;
}

int GameMap::CheckingWin()
{
	//вспомогательная переменная//проходим по карте в поиске последоветельностей исходя из заданной длинны
	int stateWin = 0;
	vector<int>check;

	//проверка по горизонтали
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			check.push_back(map[i][j]);
		}
		//проверяем
		stateWin = CheckList(check);
		check.clear();
		if (stateWin == 3) {
			return 3;//ничья
		}
		else if (stateWin == 2) {
			return 2;//победил 2
		}
		else if (stateWin == 1) {
			return 1;//победил 1
		}
	}
	//проверка по вертикали
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			check.push_back(map[j][i]);
		}
		//проверяем
		stateWin = CheckList(check);
		check.clear();
		if (stateWin == 3) {
			return 3;//ничья
		}
		else if (stateWin == 2) {
			return 2;//победил 2
		}
		else if (stateWin == 1) {
			return 1;//победил 1
		}
	}
	//проверка левых диагоналей
	//главная и над ней
	for (int i = 0; i < size.x; ++i)
	{
		for (int j = 0; i + j < size.y; ++j)
		{
			check.push_back(map[i + j][j]);
		}
		//проверяем
		stateWin = CheckList(check);
		check.clear();
		if (stateWin == 3) {
			return 3;//ничья
		}
		else if (stateWin == 2) {
			return 2;//победил 2
		}
		else if (stateWin == 1) {
			return 1;//победил 1
		}

	}
	//под ней
	for (int i = 1; i < size.x; ++i)
	{
		for (int j = 0; i + j < size.y; ++j)
		{
			check.push_back(map[i + j][j]);
		}
		//проверяем
		stateWin = CheckList(check);
		check.clear();
		if (stateWin == 3) {
			return 3;//ничья
		}
		else if (stateWin == 2) {
			return 2;//победил 2
		}
		else if (stateWin == 1) {
			return 1;//победил 1
		}
	}
	//проверка правых диагоналей
	//побочная и над ней
	for (int j = size.y; j > 0; --j)
	{
		for (int i = 0; i < size.x; ++i)
		{
			if (size.x - j - i >= 0) {
				check.push_back(map[i][size.x - j - i]);
			}
		}
		//проверяем
		stateWin = CheckList(check);
		check.clear();
		if (stateWin == 3) {
			return 3;//ничья
		}
		else if (stateWin == 2) {
			return 2;//победил 2
		}
		else if (stateWin == 1) {
			return 1;//победил 1
		}
	}
	//под ней
	for (int j = 0; j < size.y; ++j)
	{
		for (int i = 0; i < size.x; ++i)
		{
			if (size.x + j - i < size.x) {
				check.push_back(map[i][size.x + j - i]);
			}
		}
		//проверяем
		stateWin = CheckList(check);
		check.clear();
		if (stateWin == 3) {
			return 3;//ничья
		}
		else if (stateWin == 2) {
			return 2;//победил 2
		}
		else if (stateWin == 1) {
			return 1;//победил 1
		}
	}
	if (CanMove())//проверка на свободные ходы
		return 0;//нет победителя//если есть свободные ходы
	else
		return 3;//если нет то ничья
}

bool GameMap::CanMove()
{
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++) {
			if (map[i][j] == 0)
			{
				return true;
			}
		}
	}
	return false;
}

Vector2 GameMap::GetCenter()
{
	Vector2 center;
	int x;

	if (size.x % 2 != 0) {
		x = (size.x - 1) / 2;
	}
	else {
		x = (size.x / 2) - 1;
	}
	center.x = x;
	center.y = x;

	return center;
}
#pragma once
#include<vector>
#include<algorithm>
using namespace std;

struct Vector2
{
	int x, y;

};
class GameMap
{
private:
	int** map;
	Vector2 size;
	int length;//длинна выигрышной последовательности
public:
	GameMap();
	GameMap(Vector2, int);
	GameMap(int,int,int);
	~GameMap();

	bool SetPosition(Vector2, int);//задать позицию
	bool IsEmpty(Vector2);//проверка на свободную €чейку
	bool IsEmpty(int, int);//проверка на свободную €чейку
	void SetMap(Vector2, int);//создание
	void SetMap(int, int, int);
	int GetValue(Vector2);
	int GetValue(int, int);
	int GetLength() { return length; };
	Vector2 GetSize() { return size; };
	int CheckList(vector<int>a);//кто из игроков выиграл
	int CheckingWin();//не выиграл ли кто-то
	bool CanMove();//возможность дальнейших ходов
	Vector2 GetCenter();//координаты центра

	

};


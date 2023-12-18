#pragma once
#include <vector>
#include <graphics.h>
#include "Snake.h"
using namespace std;

struct Pos {
	int col;
	int row;
};

class Food
{
public:
	Food(static vector<vector<int>> map);
	void setFood(static vector<vector<int>> map,Snake* snake);
	void destroyFood();
	void drawFood();
	int recordCore();
	Pos getFoodIfo();

private:
	Pos food;
	int foodType;
	int core;
	static int size;
	IMAGE* BigFood;
	IMAGE* SmallFood;
	static IMAGE* imgs[2];
	Snake* theSnake;
};


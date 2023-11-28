#pragma once
#include <vector>
#include <graphics.h>
using namespace std;

struct Pos {
	int col;
	int row;
};

class Food
{
public:
	Food(static vector<vector<int>> map);
	void setFood();
	void destroyFood();

private:
	Pos food;
	int foodType;
	static int size;
	IMAGE* BigFood;
	IMAGE* SmallFood;
	static IMAGE* imgs[2];
};


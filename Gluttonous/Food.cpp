#include "Food.h"
#include <random>
#include <time.h>

int Food::size = 20;
IMAGE* Food::imgs[2] = { NULL, };

Food::Food(static vector<vector<int>> map)
{
	int rows = map.size();
	int cols = map[0].size();
	foodType = 1 + rand() % 2;

	if (imgs[0] == NULL)
	{
		IMAGE imgTmp;
		loadimage(&imgTmp, "res/food.png");

		SetWorkingImage(&imgTmp);
		for (int i = 0; i < 2; i++)
		{
			imgs[i] = new IMAGE;
			getimage(imgs[i], i * size, 0, 20, 20);
		}
		SetWorkingImage();//恢复工作区
	}

	//初始化食物
	food.col = rand() % cols;
	food.row = rand() % rows;
}

void Food::setFood()
{
	int x = food.col;
	int y = food.col;
}

void Food::destroyFood()
{
}

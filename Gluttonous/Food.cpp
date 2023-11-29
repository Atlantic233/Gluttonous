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
	food.col = 1 + rand() % (cols - 1);
	food.row = 1 + rand() % (rows - 1);
}

void Food::setFood(static vector<vector<int>> map,Snake* snake)
{
	int rows = map.size();
	int cols = map[0].size();
	int x = 1 + rand() % (cols - 1);
	int y = 1 + rand() % (rows - 1);
	for (int i = 0; i < snake->getSnakeInfo().size(); i++)
	{
		if (snake->getSnakeInfo(i).col != x ||
			snake->getSnakeInfo(i).row != y)
		{
			food.col = x;
			food.row = y;
		}
	}
	snake->growup();
}

void Food::destroyFood()
{

}

void Food::drawFood()
{
	int x = food.col * size;
	int y = food.row * size;
	putimage(x, y, imgs[foodType - 1]);
}

Pos Food::getFoodIfo()
{
	return food;
}

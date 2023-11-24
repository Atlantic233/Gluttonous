#include "Snake.h"
#include<stdlib.h>
#include<vector>
using namespace std;

IMAGE* Snake::imgs[3] = { NULL };
int Snake::size = 20;

Snake::Snake()
{
	if (imgs[0] == NULL)
	{
		IMAGE imgTmp;
		loadimage(&imgTmp, "res/snakebd2.png");

		SetWorkingImage(&imgTmp);
		for (int i = 0; i < 3; i++)
		{
			imgs[i] = new IMAGE;
			getimage(imgs[i], i * size, 0, 20, 20);
		}
		SetWorkingImage();//恢复工作区
	}
	
	//初始化Body
	for (int i = 0; i < 3; i++)
	{
		unityBody.row = 15;
		unityBody.col = 15 + i;
		unityBody.directin = 0;
		Body.push_back(unityBody);
	}

	head = imgs[0];
	bd = imgs[1];
	tail = imgs[2];
}

void Snake::growup()
{
}

void Snake::move()
{
	if (Body[0].directin == 0)
	{
		int lenth = Body.size();
		for (int i = lenth-1; i > 0; i--)
		{
			Body[i].col = Body[i - 1].col;
			Body[i].row = Body[i - 1].row;
		}
		Body[0].col--;
	}
}

void Snake::turn()
{

}

void Snake::draw(int leftMargin, int topMargin)
{
	for (int i = 0; i < Body.size(); i++)
	{
		int x = leftMargin + Body[i].col * size;
		int y = topMargin + Body[i].row * size;
		//putimage(x, y, head);
		if (i == 0)
		{
			putimage(x, y, head);
		}
		else if (i == Body.size()-1)
		{
			putimage(x, y, tail);
		}
		else
		{
			putimage(x, y, bd);
		}

	}
}

bool Snake::snakeInMap(const vector<vector<int>>& map)
{
	return false;
}



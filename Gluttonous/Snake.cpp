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
		loadimage(&imgTmp, "res/snakebd4.png");

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
		unityBody.direction = 0;
		Body.push_back(unityBody);
	}

	head = imgs[0];
	bd = imgs[1];
	tail = imgs[2];
}

void Snake::growup()
{
	newBody.col = Body.back().col + 1;
	newBody.row = Body.back().row + 1;
	Body.push_back(newBody);
}

void Snake::move()
{
	int lenth = Body.size();
	switch (Body[0].direction) {
	case 0:
		for (int i = lenth - 1; i > 0; i--)
		{
			Body[i].col = Body[i - 1].col;
			Body[i].row = Body[i - 1].row;
		}
		Body[0].col--;
		break;
	case 1:
		for (int i = lenth - 1; i > 0; i--)
		{
			Body[i].col = Body[i - 1].col;
			Body[i].row = Body[i - 1].row;
		}
		Body[0].row--;
		break;
	case 2:
		for (int i = lenth - 1; i > 0; i--)
		{
			Body[i].col = Body[i - 1].col;
			Body[i].row = Body[i - 1].row;
		}
		Body[0].col++;
		break;
	case 3:
		for (int i = lenth - 1; i > 0; i--)
		{
			Body[i].col = Body[i - 1].col;
			Body[i].row = Body[i - 1].row;
		}
		Body[0].row++;
		break;
	}
}

void Snake::turn(char ch)
{
	int snakeDirection = Body[0].direction;
	switch (ch) {
	case'w':
		switch (snakeDirection) {
		case 0:
			Body[0].direction = 1;
			break;
		case 1:
			break;
		case 2:
			Body[0].direction = 1;
			break;
		case 3:
			break;
		}
		break;
	case'a':
		switch (snakeDirection) {
		case 0:
			break;
		case 1:
			Body[0].direction = 0;
			break;
		case 2:
			break;
		case 3:
			Body[0].direction = 0;
			break;
		}
		break;
	case's':
		switch (snakeDirection) {
		case 0:
			Body[0].direction = 3;
			break;
		case 1:
			break;
		case 2:
			Body[0].direction = 3;
			break;
		case 3:
			break;
		}
		break;
	case'd':
		switch (snakeDirection) {
		case 0:
			break;
		case 1:
			Body[0].direction = 2;
			break;
		case 2:
			break;
		case 3:
			Body[0].direction = 2;
			break;
		}
		break;
	}
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
	int rows = map.size();
	int cols = map[0].size();
	if (Body[0].col <= 0 || Body[0].col >= cols ||
		Body[0].row <= 0 || Body[0].row >= rows)
	{
		return false;
	}
	for (int i = 1; i < Body.size(); i++)
	{
		if (Body[i].col == Body[0].col && Body[i].row == Body[0].row)
		{
			return false;
		}
	}
	return true;
}

Point Snake::getSnakeInfo(int i)
{
	return Body[i];
}

vector<Point> Snake::getSnakeInfo()
{
	return Body;
}






#include "Gluttonou.h"
#include "Snake.h"
#include <random>
#include <conio.h>

const int SPEED_NORMAL = 500;
const int SPEED_QUIK = 50;

Gluttonou::Gluttonou(int rows, int cols, int unitSize,int leftmargin,int topmargin)
{
	this->rows = rows;
	this->cols = cols;
	this->unitsize = unitSize;
	this->leftm = leftmargin;
	this->topm = topmargin;

	for (int i = 0; i < rows; i++)
	{
		vector<int>mapRow;
		for (int j = 0; j < cols; j++)
		{
			mapRow.push_back(0);
		}
		map.push_back(mapRow);
	}
}

void Gluttonou::init()
{
	//配置随机种子
	srand(time(NULL));

	delay = SPEED_NORMAL;
	//创建游戏窗口
	initgraph(720, 720);
	//加载背景图片
	loadimage(&bgImg, "res/map3.png");
	loadimage(&failedImg, "res/failed.png");
	//初始化游戏区中的数据
	char data[30][30];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			map[i][j] = 0;
		}
	}
}

void Gluttonou::play()
{
	init();

	foods = new Food(map);
	mysnake = new Snake;
	
	int timer = 0;

	while (1)
	{

		//keyEvent();
		timer += getDelay();

		if (timer > delay)
		{
			timer = 0;

			//mysnake->move();
			update = true;
		}

		if (update)
		{
			update = false;
			//更新游戏数据

			//结束游戏
			if (!mysnake->snakeInMap(map)) {
				GameOver();
				break;
			}
			//接收输入
			keyEvent();
			//移动
			move();
			//生成食物
			if (foods->getFoodIfo().col == mysnake->getSnakeInfo(0).col &&
				foods->getFoodIfo().row == mysnake->getSnakeInfo(0).row)
			{
				foods->setFood(map, mysnake);
				update = true;
			}
			//渲染游戏画面
			updateWindow();
		}
		
	}
}

void Gluttonou::keyEvent()
{
	char ch;
	if (_kbhit()) {
		ch = _getch();
		mysnake->turn(ch);
	}
}

void Gluttonou::updateWindow()
{
	putimage(0, 0, &bgImg);//绘制背景图片

	BeginBatchDraw();

	mysnake->draw(leftm, topm);//画蛇
	foods->drawFood();//画食物

	EndBatchDraw();
}

int Gluttonou::getDelay()
{
	static unsigned long long lastTime = 0;
	unsigned long long currentTime = GetTickCount();

	if (lastTime == 0)
	{
		lastTime = currentTime;
		return 0;
	}
	else
	{
		int ret = currentTime - lastTime;
		lastTime = currentTime;
		return ret;
	}
}

void Gluttonou::move()
{
	mysnake->move();
}

//void Gluttonou::turn()
//{
//	mysnake->turn();
//}

void Gluttonou::growup()
{
}

void Gluttonou::mapIfo(vector<vector<int>> map)
{
	
}

void Gluttonou::GameOver()
{
	putimage(0, 0, &failedImg);
	
}



#include "Gluttonou.h"
#include "Snake.h"

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
	delay = SPEED_NORMAL;
	//创建游戏窗口
	initgraph(720, 720);
	//加载背景图片
	loadimage(&bgImg, "res/map3.png");

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

	mysnake = new Snake;

	int timer = 0;
	while (1)
	{
		//接受输入
		keyEvent();
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
			if (!mysnake->snakeInMap(map)) {

			}
			move();
			//渲染游戏画面
			updateWindow();
		}
		
	}
}

void Gluttonou::keyEvent()
{
}

void Gluttonou::updateWindow()
{
	putimage(0, 0, &bgImg);//绘制背景图片
	
	mysnake->draw(leftm, topm);
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

void Gluttonou::turn()
{
	//mysnake->turn();
}

void Gluttonou::growup()
{
}

void Gluttonou::mapIfo(vector<vector<int>> map)
{
	
}

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
	//������Ϸ����
	initgraph(720, 720);
	//���ر���ͼƬ
	loadimage(&bgImg, "res/map3.png");

	//��ʼ����Ϸ���е�����
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
		//��������
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
			//������Ϸ����
			if (!mysnake->snakeInMap(map)) {

			}
			move();
			//��Ⱦ��Ϸ����
			updateWindow();
		}
		
	}
}

void Gluttonou::keyEvent()
{
}

void Gluttonou::updateWindow()
{
	putimage(0, 0, &bgImg);//���Ʊ���ͼƬ
	
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

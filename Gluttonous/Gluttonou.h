#pragma once
#include<vector>
#include<graphics.h>
#include"Snake.h"
#include"Food.h"
using namespace std;

class Gluttonou
{
public:
	//构造函数
	Gluttonou(int rows, int cols,int unitSize,int leftmargin,int rightmargin);
	//初始化
	void init();
	//开始游戏
	void play();

private:
	void keyEvent();
	void updateWindow();
	int getDelay();//返回上一次调用函数所用的时间
	void move();
	//void turn();
	void growup();
	void mapIfo(vector<vector<int>> map);
	
private:
	int delay;
	bool update;

	vector<vector<int>> map;
	int cols;
	int rows;
	int leftm;
	int topm;
	int unitsize;
	IMAGE bgImg;

	Snake* mysnake;
	Food* foods;
};


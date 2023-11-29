#pragma once
#include<vector>
#include<graphics.h>
#include"Snake.h"
#include"Food.h"
using namespace std;

class Gluttonou
{
public:
	//���캯��
	Gluttonou(int rows, int cols,int unitSize,int leftmargin,int rightmargin);
	//��ʼ��
	void init();
	//��ʼ��Ϸ
	void play();

private:
	void keyEvent();
	void updateWindow();
	int getDelay();//������һ�ε��ú������õ�ʱ��
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


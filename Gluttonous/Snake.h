#pragma once
#include <graphics.h>
#include <vector>
using namespace std;

struct Point
{
	int col;
	int row;
	int direction;
};

class Snake
{
public:
	Snake();
	void growup();
	void move();
	void turn();
	void draw(int leftMargin,int topMargin);
	bool snakeInMap(const vector<vector<int>>& map);
	Point getSnakeInfo(int i);
	vector<Point> getSnakeInfo();

private:
	Point unityBody;
	Point newBody;
	vector<Point> Body;
	IMAGE* head;
	IMAGE* bd;
	IMAGE* tail;
	static IMAGE* imgs[3];
	static int size;
};


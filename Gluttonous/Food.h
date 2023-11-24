#pragma once
struct Pos {
	int x;
	int y;
};

class Food
{
public:
	Food();
	void setFood();
	void destroy();

private:
	Pos position;

};


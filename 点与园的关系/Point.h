#pragma once
#include<iostream>
using namespace std;
//点类
class Point {
public:
	void setX(int x);//设置点的x坐标
	int getX();//获取点的x坐标
	void setY(int y);//设置点的y坐标
	int getY();//获取点的y坐标
private:
	int m_X;//x坐标
	int m_Y;//y坐标
};

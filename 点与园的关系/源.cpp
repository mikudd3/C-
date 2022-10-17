#include<iostream>
using namespace std;
#include"Circle.h"
#include"Point.h"
//判断点到圆心的距离
void isInCircle(Circle& c, Point& p) {
	int distance =//点到圆心的距离
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rdistance = c.getR() * c.getR();//半径的平方
	if (distance == rdistance) cout << "点在圆上" << endl;//
	else if(distance > rdistance)  cout << "点在圆外" << endl;
	else  cout << "点在圆内" << endl;
}
int main() {
	//圆
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);
	//点
	Point p;
	p.setX(10);
	p.setY(10);
	isInCircle(c, p);
	return 0;

}
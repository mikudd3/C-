#include<iostream>
using namespace std;
#include"Circle.h"
#include"Point.h"
//�жϵ㵽Բ�ĵľ���
void isInCircle(Circle& c, Point& p) {
	int distance =//�㵽Բ�ĵľ���
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rdistance = c.getR() * c.getR();//�뾶��ƽ��
	if (distance == rdistance) cout << "����Բ��" << endl;//
	else if(distance > rdistance)  cout << "����Բ��" << endl;
	else  cout << "����Բ��" << endl;
}
int main() {
	//Բ
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);
	//��
	Point p;
	p.setX(10);
	p.setY(10);
	isInCircle(c, p);
	return 0;

}
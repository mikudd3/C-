#pragma once
#include<iostream>
using namespace std;
#include "Point.h"
//Բ��
class Circle {
public:
	void setR(int r);//���ð뾶
	int getR();//��ȡ�뾶
	void setCenter(Point center);//����Բ��
	Point getCenter();//��ȡԲ��
private:
	int m_R;//�뾶
	Point m_Center;//Բ��
};
#pragma once
#include<iostream>

using namespace std;
class elite :public hire {
public:
	elite() {};//���캯��
	elite(char c);
	elite(double insight, double logic);
	void showmenu();//���˵�
	void minimenu();//�Ӳ˵�
	void judge();//�ж�
	void display();//չʾ
	void ischose();//�Ƿ�ѡ��
private:
	double insight;
	double logic;
	char character;
};


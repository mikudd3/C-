#pragma once
#include<iostream>

using namespace std;
class elite :public hire {
public:
	elite() {};//构造函数
	elite(char c);
	elite(double insight, double logic);
	void showmenu();//主菜单
	void minimenu();//子菜单
	void judge();//判断
	void display();//展示
	void ischose();//是否选择
private:
	double insight;
	double logic;
	char character;
};


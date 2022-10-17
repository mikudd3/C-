#pragma once
#include<iostream>
using namespace std;

class hire {
public:
	hire() {};//默认构造函数
	hire(char c);
	hire(double agility, double strength, double speed);
	void menu();
	void choose(hire& h);
	double fox();
	double bunny();
	double sloth();
	void operator +(hire& h1);
	double hirescore();
	void display1();
private:
	double agility = 0;
	double strength = 0;
	double speed = 0;
	char character;
};

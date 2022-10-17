#pragma once
#include<iostream>
using namespace std;
#include"BookData.h"
class report :public BookData{
public:
	report(){}
	void mimenu();//报表
	void shuliebia();//书库列表
	void pifajia();//批发价列表
	void lingshoujia();//零售价列表
	void shushulianag();//按书的数量列表
	void shujiage();//按书的价值额列表
	void jingshuriqi();//按进书日期列表
};

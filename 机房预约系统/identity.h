#pragma once  //防止头文件重复包含
#include<iostream>
using namespace std;

class Identity {
	//身份抽象类
public:
	virtual void operMenu() = 0;//操作系统
	string m_Name;//用户名
	string m_Pwd;//密码
};

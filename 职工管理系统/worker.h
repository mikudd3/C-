#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker {
public:
	virtual void showInfo() = 0;//显示个人信息
	virtual string getDeptName() = 0;//获取岗位名称
	int m_id;//职工编号
	string m_Name;//职工姓名
	int m_Deptid;//职工所在部门的编号
};

#pragma once//防止头文件重复包含
#include<iostream>//标准输入流
#include<fstream>
#include "worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
#define FILENAME "empFile.txt"
using namespace std;//使用标准命名空间
class workermanager {
public:
	workermanager();//构造函数
	void show_menu();//菜单
	void exitSystem();//退出系统
	void show_emp();//显示职工信息
	void delete_emp();//删除职工信息
	int IsExist(int id);//判断该职工是否存在
	void mod_emp();//修改职工信息
	void find_emp();//查找职工信息
	void sort_emp();//按照编号排序
	void clean_file();//清空所有文档
	int m_empNum;//记录文件中的人数个数
	worker** m_empArray;//员工数组指针
	void Add_emp();//增加员工
	void save();//保存文件
	bool m_FileIsEmpty;
	int get_EmpNum();//统计人数
	void init_Emp();
	~workermanager();//析构函数

};

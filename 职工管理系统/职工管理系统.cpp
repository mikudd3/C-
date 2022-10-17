#include<iostream>
#include "workermanager.h"
using namespace std;
//#include"worker.h"


int main() {
	workermanager wm;
	int choice = 0;
	while (true) {
		wm.show_menu();
		cout << "请选择" << endl;
		cin >> choice;
		switch (choice) {
		case 0://退出管理系统
			wm.exitSystem();
			break;
		case 1://增加职工信息
			wm.Add_emp();//增加员工
			break;
		case 2://显示职工信息
			wm.show_emp();
			break;
		case 3://删除职工信息
			wm.delete_emp();
			break;
		case 4://修改职工信息
			wm.mod_emp();
			break;
		case 5://查找职工信息
			wm.find_emp();
			break;
		case 6://按照编号排序
			wm.sort_emp();
			break;
		case 7://清空所有文档
			wm.clean_file();
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
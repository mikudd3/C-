#include<iostream>
using namespace std;
#include"speechmanager.h"
#include<string>
#include<ctime>
int main() {
	//添加随机数种子
	srand((unsigned int)time(NULL));

	//创建管理类对象
	speechmanager sm;
	int choice = 0;
	while (true) {
		sm.show_menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice) {
		case 1://开始比赛
			sm.startspeech();
			break;
		case 2://查看记录
			sm.showrecord();
			break;
		case 3://清空记录
			sm.clearrecord();
			break;
		case 0://退出系统
			sm.exitsystem();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}
	system("pause");
	return 0;
}

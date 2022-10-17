#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<algorithm>
#include<deque>
#include<numeric>
#include<functional>
#include"speaker.h"
#include<fstream>
class speechmanager
{
public:
	//构造函数
	speechmanager();
	//菜单功能
	void show_menu();
	//退出系统
	void exitsystem();
	//比赛选手容器 12人
	vector<int>v1;
	//第一轮晋级人数 6人
	vector<int>v2;
	//第二轮晋级人数 3人
	vector<int>victory;
	//存放编号，以及对应的具体选手 容器
	map<int, speaker> m_speaker;
	//记录比赛轮数
	int m_index;
	//初始化属性
	void initspeech();
	//创建选手
	void createspeaker();
	//开始比赛
	void startspeech();
	//1.抽签
	void speechdraw();
	//2.比赛
	void speechcontset();
	//3.显示晋级结果
	void showscore();
	//保存记录
	void saverecord();
	//读取记录
	void loadrecord();
	// 文件是否为空标志
	bool fileisempty;
	//往届记录
	map<int, vector<string>>m_record;
	//查看记录
	void showrecord();
	//清空记录
	void clearrecord();
	
	//析构函数
	~speechmanager();
};


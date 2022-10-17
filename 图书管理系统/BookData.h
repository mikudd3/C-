#pragma once
#include<iostream>
using namespace std;
#include"TitleInfo.h"
#include<string>
#include<fstream>
#define FILENAME "bookFile.txt"
class BookData :public TitleInfo {
public:
	BookData();//构造函数
	void menu();//主菜单
	void salemenu();//销售菜单
	void sale();//购买
	void shukumenu();//书库操作菜单
	void strUpper(string isbn);//小写转大写
	int isExit(string bookTitle);//判断书是否存在
	void lookUpBook();//查找书
	void modbook();//修改书
	void BookInfo(int bnum);//展示某本书
	void BookInfo();//展示全部书
	void editBook();//增加书
	void deleteBook();//删除书
	void save();//保存书到文件
	TitleInfo bookDataArray[100];//对象数组
	int booknum = 0;//记录数组里书的个数
	bool FileIsIsEmpty;//判断文件是否为空
	int get_bookNum();//统计人数
	void init_book();//导入文本数据到数组
};

#pragma once
#include<iostream>
using namespace std;
#include"TitleInfo.h"
#include<string>
#include<fstream>
#define FILENAME "bookFile.txt"
class BookData :public TitleInfo {
public:
	BookData();//���캯��
	void menu();//���˵�
	void salemenu();//���۲˵�
	void sale();//����
	void shukumenu();//�������˵�
	void strUpper(string isbn);//Сдת��д
	int isExit(string bookTitle);//�ж����Ƿ����
	void lookUpBook();//������
	void modbook();//�޸���
	void BookInfo(int bnum);//չʾĳ����
	void BookInfo();//չʾȫ����
	void editBook();//������
	void deleteBook();//ɾ����
	void save();//�����鵽�ļ�
	TitleInfo bookDataArray[100];//��������
	int booknum = 0;//��¼��������ĸ���
	bool FileIsIsEmpty;//�ж��ļ��Ƿ�Ϊ��
	int get_bookNum();//ͳ������
	void init_book();//�����ı����ݵ�����
};

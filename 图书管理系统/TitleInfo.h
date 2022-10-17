#pragma once
#include<iostream>
using namespace std;
class TitleInfo {
public:
	TitleInfo() {}
	TitleInfo(string bn, string Title, string au, string pu,
		string dA, int qty, double wh, double re);
	void seTIsbn(string bn);//����isbn��
	void seTitle(string Title);//�����鱾��
	void setAuthor(string au);//��������
	void setPub(string pu);//���ó�����
	void setDataAdded(string dA);//���ý�������
	void setQty(int qty);//������Ŀ���� 
	void setWholesale(double wh);//����������
	void setRetail(double re);//�������ۼ�
	string getBookTitle(){ return bookTitle;}
	string getISBN(){ return isbn;}
	string getAuthor(){ return author;}
	string getPubisher(){ return publisher;}
	string getDataAdded(){ return dataAdded;}
	int getQtyOnHand(){ return qtyOnHand;}
	double getWholesale(){ return wholesale;}
	double getRetail(){ return retail;}
	string isbn;//isbn��
	string bookTitle;//����
	string author;//����
	string publisher;//������
	string dataAdded;//��������
	int qtyOnHand;//�����
	double wholesale;//������
	double retail;//���ۼ�
	~TitleInfo() {}//��������
};
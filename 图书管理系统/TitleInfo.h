#pragma once
#include<iostream>
using namespace std;
class TitleInfo {
public:
	TitleInfo() {}
	TitleInfo(string bn, string Title, string au, string pu,
		string dA, int qty, double wh, double re);
	void seTIsbn(string bn);//设置isbn号
	void seTitle(string Title);//设置书本名
	void setAuthor(string au);//设置作者
	void setPub(string pu);//设置出版社
	void setDataAdded(string dA);//设置进书日期
	void setQty(int qty);//设置书的库存量 
	void setWholesale(double wh);//设置批发价
	void setRetail(double re);//设置零售价
	string getBookTitle(){ return bookTitle;}
	string getISBN(){ return isbn;}
	string getAuthor(){ return author;}
	string getPubisher(){ return publisher;}
	string getDataAdded(){ return dataAdded;}
	int getQtyOnHand(){ return qtyOnHand;}
	double getWholesale(){ return wholesale;}
	double getRetail(){ return retail;}
	string isbn;//isbn号
	string bookTitle;//书名
	string author;//作者
	string publisher;//出版社
	string dataAdded;//进书日期
	int qtyOnHand;//库存量
	double wholesale;//批发价
	double retail;//零售价
	~TitleInfo() {}//析构函数
};
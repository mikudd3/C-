#include"BookData.h"
#include "report.h"
//构造函数
BookData::BookData() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		//cout << "文件不存在" << endl;
		booknum = 0;//初始化人数
		TitleInfo bookDataArray[100] = {};//初始化数组
		FileIsIsEmpty = true;
		ifs.close();
		return;
	}
	string ch;
	ifs >> ch;
	if (ifs.eof()) {//文件存在，但没有记录
		//cout << "文件为空" << endl;
		booknum = 0;//初始化人数
		TitleInfo bookDataArray[100] = {};//初始化数组
		FileIsIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，并且记录数据
	FileIsIsEmpty = false;
	int num = get_bookNum();
	booknum = num;
	init_book();//将文件中的数据，存到数组中

}
//判断书是否存在,并返回其下标
int BookData::isExit(string bookTitle) {
	int index = -1;
	for (int i = 0; i < booknum; i++) {
		if (bookDataArray[i].bookTitle == bookTitle) {
			index = i;
			break;
		}
	}
	return index;
}
//查找书
void BookData::lookUpBook() {
	if (FileIsIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入你要查找的书的名字" << endl;
		string booktitle;
		cin >> booktitle;
		int index = -1;
		index = isExit(booktitle);
		if (index != -1) {
			BookInfo(index);
		}
		else {
			cout << "没有找到这本书" << endl;
		}
	}
}
//小写转大写
void BookData::strUpper(string isbn) {
	for (int i = 0; i < 14; i++) {
		if (isbn[i] >= 'a' && isbn[i] <= 'z')
			isbn[i] += 32;
	}
}
//查看某本书的信息
void BookData::BookInfo(int bnum) {

	int num = bnum;
	cout << "lzy图书管理系统" << endl;
	cout << "   书的资料" << endl;
	cout << "ISBN 号 ：" << bookDataArray[num].getISBN() << endl;
	cout << "书   名 ：" << bookDataArray[num].getBookTitle() << endl;
	cout << "作   者 ：" << bookDataArray[num].getAuthor() << endl;
	cout << "出版社  ：" << bookDataArray[num].getPubisher() << endl;
	cout << "进书日期：" << bookDataArray[num].getDataAdded() << endl;
	cout << "库存量  ：" << bookDataArray[num].getQtyOnHand() << endl;
	cout << "批发价  ：" << bookDataArray[num].getWholesale() << endl;
	cout << "零售价  ：" << bookDataArray[num].getRetail() << endl;
}
void BookData::BookInfo() {//展示书
	for (int i = 0; i < booknum; i++) {
		cout << "lzy图书管理系统" << endl;
		cout << "   书的资料" << endl;
		cout << "ISBN 号 ：" << bookDataArray[i].getISBN() << endl;
		cout << "书   名 ：" << bookDataArray[i].getBookTitle() << endl;
		cout << "作   者 ：" << bookDataArray[i].getAuthor() << endl;
		cout << "出版社  ：" << bookDataArray[i].getPubisher() << endl;
		cout << "进书日期：" << bookDataArray[i].getDataAdded() << endl;
		cout << "库存量  ：" << bookDataArray[i].getQtyOnHand() << endl;
		cout << "批发价  ：" << bookDataArray[i].getWholesale() << endl;
		cout << "零售价  ：" << bookDataArray[i].getRetail() << endl;
	}
}
//增加书
void BookData::editBook() {
	int addnum = 0;
	cout << "请输入你要增加的书本的个数" << endl;
	cin >> addnum;
	if (addnum > 0) {
		while (addnum) {
			string isbn;//isbn号
			string bookTitle;//书名
			string author;//作者
			string publisher;//出版社
			string dataAdded;//进书日期
			int qtyOnHand;//库存量
			double wholesale;//批发价
			double retail;//零售价
			cout << "请输入加入书的ISBN号" << endl;
			cin >> isbn;
			bookDataArray[booknum].seTIsbn(isbn);
			cout << "请输入加入书的书名" << endl;
			cin >> bookTitle;
			bookDataArray[booknum].seTitle(bookTitle);
			cout << "请输入加入书的作者" << endl;
			cin >> author;
			bookDataArray[booknum].setAuthor(author);
			cout << "请输入加入书的出版社" << endl;
			cin >> publisher;
			bookDataArray[booknum].setPub(publisher);
			cout << "请输入加入书的进书日期" << endl;
			cin >> dataAdded;
			bookDataArray[booknum].setDataAdded(dataAdded);
			cout << "请输入加入书的库存量" << endl;
			cin >> qtyOnHand;
			bookDataArray[booknum].setQty(qtyOnHand);
			cout << "请输入加入书的批发价" << endl;
			cin >> wholesale;
			bookDataArray[booknum].setWholesale(wholesale);
			cout << "请输入加入书的零售价" << endl;
			cin >> retail;
			bookDataArray[booknum].setRetail(retail);
			addnum--;
			booknum++;
			FileIsIsEmpty = false;//更新职工不为空标志
			save();//保存数据到文件
		}
		cout << "成功添加"<< endl;
	}
	else {
		cout << "输入错误" << endl;
	}
	system("pause");
	system("cls");
}
//修改书
void BookData::modbook() {
	if (FileIsIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请选择你要修改的书的名字" << endl;
		string booktitle;
		cin >> booktitle;
		int index = isExit(booktitle);
		if (index == -1) {
			cout << "没有找到该书" << endl;
		}
		else {
			while (true) {
				cout << "请选择要修改的内容" << endl;
				cout << "1.isbn号" << endl;
				cout << "2.书名" << endl;
				cout << "3.书作者" << endl;
				cout << "4.出版社" << endl;
				cout << "5.进书日期" << endl;
				cout << "6.库存量" << endl;
				cout << "7.批发价" << endl;
				cout << "8。零售价" << endl;
				cout << "9.返回上一个菜单" << endl;
				int select = 0;
				cin >> select;
				switch (select) {
				case 1: {
					cout << "请输入修改后的isbn" << endl;
					string newisbn;
					cin >> newisbn;
					bookDataArray[index].seTIsbn(newisbn);
					break;
				}
				case 2: {
					cout << "请输入修改后的书名" << endl;
					string newbooktitle;
					cin >> newbooktitle;
					bookDataArray[index].seTitle(newbooktitle);
					break;
				}
				case 3: {
					cout << "请输入修改后的作者" << endl;
					string newauthor;
					cin >> newauthor;
					bookDataArray[index].setAuthor(newauthor);
					break;
				}
				case 4: {
					cout << "请输入修改后的出版社" << endl;
					string newpublisher;//出版社
					cin >> newpublisher;
					bookDataArray[index].setPub(newpublisher);
					break;
				}
				case 5: {
					cout << "请输入修改后的进书日期" << endl;
					string newdataAdded;//进书日期
					cin >> newdataAdded;
					bookDataArray[index].setDataAdded(newdataAdded);
					break;
				}
				case 6: {
					cout << "请输入修改后的库存量" << endl;
					int newqtyOnHand;//库存量
					cin >> newqtyOnHand;
					bookDataArray[index].setQty(newqtyOnHand);
					break;
				}
				case 7: {
					cout << "请输入修改后的批发价" << endl;
					double newwholesale;//批发价
					cin >> newwholesale;
					bookDataArray[index].setWholesale(newwholesale);
					break;
				}
				case 8: {
					cout << "请输入修改后的零售价" << endl;
					double newretail;//零售价
					cin >> newretail;
					bookDataArray[index].setRetail(newretail);
					break;
				}
				case 9:
					shukumenu();
					break;
				default:
					std::cout << "输入错误，请重新输入" << endl;
					break;
				}
				this->save();
				cout << "修改成功" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
//删除书
void BookData::deleteBook() {
	if (FileIsIsEmpty) {
		cout << "文件不存在或文本为空" << endl;
	}
	else {
		string booktitle;
		cout << "请输入要删除的书名" << endl;
		cin >> booktitle;
		int index = isExit(booktitle);
		if (index != -1) {
			for (int i = 0; i < this->booknum - 1; i++) {
				bookDataArray[i] = bookDataArray[i + 1];
			}
			booknum--;
			save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "删除失败，未找到该书" << endl;
		}
	}
}
//保存文件
void BookData::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->booknum; i++) {
		ofs << bookDataArray[i].getISBN() << " "
			<< bookDataArray[i].getBookTitle() << " "
			<< bookDataArray[i].getAuthor() << " "
			<< bookDataArray[i].getDataAdded() << " "
			<< bookDataArray[i].getQtyOnHand() << " "
			<< bookDataArray[i].getWholesale() << " "
			<< bookDataArray[i].getRetail() << endl;
	}
	//关闭文件
	ofs.close();
}
//统计书本数
int BookData::get_bookNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string isbn;//isbn号
	string bookTitle;//书名
	string author;//作者
	string publisher;//出版社
	string dataAdded;//进书日期
	int qtyOnHand;//库存量
	double wholesale;//批发价
	double retail;//零售价
	int num = 0;
	while (ifs >> isbn && ifs >> bookTitle && ifs >> author
		&& ifs >> publisher && ifs >> dataAdded && ifs >> qtyOnHand
		&& ifs >> wholesale && ifs >> retail) {
		bookDataArray[num].seTIsbn(isbn);
		bookDataArray[num].seTitle(bookTitle);
		bookDataArray[num].setAuthor(author);
		bookDataArray[num].setPub(publisher);
		bookDataArray[num].setDataAdded(dataAdded);
		bookDataArray[num].setQty(qtyOnHand);
		bookDataArray[num].setWholesale(wholesale);
		bookDataArray[num].setRetail(retail);
		num++;
	}
	ifs.close();
	return num;
}
//导入数据到数组
void BookData::init_book() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string isbn;//isbn号
	string bookTitle;//书名
	string author;//作者
	string publisher;//出版社
	string dataAdded;//进书日期
	int qtyOnHand;//库存量
	double wholesale;//批发价
	double retail;//零售价
	int index = 0;
	while (ifs >> isbn && ifs >> bookTitle && ifs >> author
		&& ifs >> publisher && ifs >> dataAdded && ifs >> qtyOnHand
		&& ifs >> wholesale && ifs >> retail) {
		bookDataArray[index].seTIsbn(isbn);
		bookDataArray[index].seTitle(bookTitle);
		bookDataArray[index].setAuthor(author);
		bookDataArray[index].setPub(publisher);
		bookDataArray[index].setDataAdded(dataAdded);
		bookDataArray[index].setQty(qtyOnHand);
		bookDataArray[index].setWholesale(wholesale);
		bookDataArray[index].setRetail(retail);
		index++;
	}
	save();
	ifs.close();
}
void BookData::menu() {
	int flag = 1;
	while (flag) {
		cout << "lzy图书管理系统" << endl;
		cout << "   主菜单	 " << endl;
		cout << "1.收银模块" << endl;
		cout << "2.书库管理系统" << endl;
		cout << "3.报表模块" << endl;
		cout << "4.退出系统" << endl;
		int select = 0;
		cout << "请输入你的选择" << endl;
		cin >> select;
		switch (select) {
		case 1: {
			salemenu();
			save();
			break;
		}
		case 2:
			shukumenu();
			save();
			break;
		case 3: {
			report* a = new report();
			a->mimenu();
			break;
		}
		case 4:
			std::cout << "欢迎下次使用！！" << endl;
			return;
			break;
		default:
			std::cout << "输入错误,请重新输入！！" << endl;
			break;
		}
	}
}
//书库菜单
void BookData::shukumenu() {
	int flag = 1;
	while (flag) {
		cout << "lzy图书管理系统" << endl;
		cout << "  书库管理模块" << endl;
		cout << "1.查找某本书的信息" << endl;
		cout << "2.增加书" << endl;
		cout << "3.修改书的信息" << endl;
		cout << "4.删除书" << endl;
		cout << "5.返回主菜单" << endl;
		cout << "   输入选择（1-5）" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice) {
		case 1:
			lookUpBook();
			save();
			break;
		case 2:
			editBook();
			save();
			break;
		case 3:
			modbook();
			save();
			break;
		case 4:
			deleteBook();
			save();
			break;
		case 5:
			save();
			return;
			break;
		default:
			std::cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}
void BookData::salemenu() {
	while (true) {
		cout << "lzy图书管理系统" << endl;
		cout << "	收银模块" << endl;
		cout << "1.购买图书" << endl;
		cout << "2.返回主菜单" << endl;
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:
			sale();
			save();
			break;
		case 2: {
			menu();
			save();
			break;
		}
		default:
			break;
		}
	}
}
//购买
void BookData::sale() {
	cout << "请输入你要购买的书的书名" << endl;
	string title;
	cin >> title;
	int cnt = isExit(title);
	if (cnt != -1) {
		if (bookDataArray[cnt].qtyOnHand == 0) {
			cout << "该书已售完" << endl;
			salemenu();
		}
		else {
			cout << "请输入要购买的书的量" << endl;
			int qty;
			cin >> qty;
			if (bookDataArray[cnt].qtyOnHand < qty) {
				cout << "库存不足" << endl;
			}
			else {
				double sale = bookDataArray[cnt].retail * qty * 0.06;
				double price = bookDataArray[cnt].retail * qty + sale;
				bookDataArray[cnt].qtyOnHand -= qty;
				cout << "购买成功" << endl;
				save();
				cout << bookDataArray[cnt].bookTitle << qty
					<< bookDataArray[cnt].wholesale
					<< "税额：" << sale << endl;
			}
		}
	}
	else {
		cout << "找不到该书" << endl;
	}

}

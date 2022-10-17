#include"report.h"
void report::mimenu() {
	while (true) {
		cout << "lzy图书馆系统" << endl;
		cout << "    报表模块" << endl;
		cout << "1.书库列表" << endl;
		cout << "2.批发价列表" << endl;
		cout << "3.零售价列表" << endl;
		cout << "4.按书的数量列表" << endl;
		cout << "5.按书的价值额列表" << endl;
		cout << "6.按进书日期列表" << endl;
		cout << "7.返回到主菜单" << endl;
		cout << "  输入选择（1-7）" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice) {
		case 1:
			shuliebia();
			break;
		case 2:
			pifajia();
			break;
		case 3:
			lingshoujia();
			break;
		case 4:
			shushulianag();
			break;
		case 5:
			shujiage();
			break;
		case 6:
			jingshuriqi();
			break;
		case 7: {
			menu();
			break;
		}
		default:
			std::cout << "输入错误，请重新输入" << endl;
			break;

		}
	}
	system("cls");
	system("pause");
}
//书库列表
void report::shuliebia() {
	if (this->FileIsIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		BookInfo();
	}
}
void report::pifajia() {
	if (this->FileIsIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		int sum = 0;
		for (int i = 0; i < booknum; i++) {
			cout << "书名：" << bookDataArray[i].bookTitle
				<< "批发价：" << bookDataArray[i].wholesale << endl;
			sum += bookDataArray[i].wholesale;
		}
		cout << "批发价总和：" << sum << endl;
	}
}
void report::lingshoujia() {//零售价列表
	if (this->FileIsIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		int sum = 0;
		for (int i = 0; i < booknum; i++) {
			cout << "书名：" << bookDataArray[i].retail
				<< "零售价：" << bookDataArray[i].retail << endl;
			sum += bookDataArray[i].retail;
		}
		cout << "零售价总和：" << sum << endl;
	}
}
void report::shushulianag() {//按书的数量列表
	if (this->FileIsIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		for (int i = 0; i < booknum; i++) {
			int minOrmax = i;
			for (int j = i + 1; j < booknum; j++) {//降序
				if (bookDataArray[minOrmax].qtyOnHand <
					bookDataArray[j].qtyOnHand) {
					minOrmax = j;
				}
			}
			if (i != minOrmax) {
				TitleInfo temp = bookDataArray[i];
				bookDataArray[i] = bookDataArray[minOrmax];
				bookDataArray[minOrmax] = temp;
			}
		}
	}
}
void report::shujiage() {//按书的价值额列表
	if (this->FileIsIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		double sumarray[1000];
		for (int i = 0; i < booknum; i++) {
			sumarray[i] = bookDataArray[i].wholesale *
				bookDataArray[i].qtyOnHand;
		}
		for (int i = 0; i < booknum; i++) {
			int minOrmax = i;
			for (int j = i + 1; j < booknum; j++) {
				if (sumarray[minOrmax] < sumarray[j]) {
					minOrmax = j;
				}
			}
			if (i != minOrmax) {
				double temp = sumarray[i];
				sumarray[i] = sumarray[minOrmax];
				sumarray[minOrmax] = temp;
			}
		}
		for (int i = 0; i < booknum; i++) {
			cout << "书名：" << bookDataArray[i].bookTitle
				<< "批发价：" << bookDataArray[i].wholesale
				<< "价值额：" << sumarray[i] << endl;
		}
	}
}
void report::jingshuriqi() {//按进书日期列表
	if (this->FileIsIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		for (int i = 0; i < booknum; i++) {
			int minOrmax = i;
			for (int j = i + 1; j < booknum; j++) {//降序
				if (bookDataArray[minOrmax].dataAdded <
					bookDataArray[j].dataAdded) {
					minOrmax = j;
				}
			}
			if (i != minOrmax) {
				TitleInfo temp = bookDataArray[i];
				bookDataArray[i] = bookDataArray[minOrmax];
				bookDataArray[minOrmax] = temp;
			}
		}
	}
}
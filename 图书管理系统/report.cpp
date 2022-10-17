#include"report.h"
void report::mimenu() {
	while (true) {
		cout << "lzyͼ���ϵͳ" << endl;
		cout << "    ����ģ��" << endl;
		cout << "1.����б�" << endl;
		cout << "2.�������б�" << endl;
		cout << "3.���ۼ��б�" << endl;
		cout << "4.����������б�" << endl;
		cout << "5.����ļ�ֵ���б�" << endl;
		cout << "6.�����������б�" << endl;
		cout << "7.���ص����˵�" << endl;
		cout << "  ����ѡ��1-7��" << endl;
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
			std::cout << "�����������������" << endl;
			break;

		}
	}
	system("cls");
	system("pause");
}
//����б�
void report::shuliebia() {
	if (this->FileIsIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		BookInfo();
	}
}
void report::pifajia() {
	if (this->FileIsIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		int sum = 0;
		for (int i = 0; i < booknum; i++) {
			cout << "������" << bookDataArray[i].bookTitle
				<< "�����ۣ�" << bookDataArray[i].wholesale << endl;
			sum += bookDataArray[i].wholesale;
		}
		cout << "�������ܺͣ�" << sum << endl;
	}
}
void report::lingshoujia() {//���ۼ��б�
	if (this->FileIsIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		int sum = 0;
		for (int i = 0; i < booknum; i++) {
			cout << "������" << bookDataArray[i].retail
				<< "���ۼۣ�" << bookDataArray[i].retail << endl;
			sum += bookDataArray[i].retail;
		}
		cout << "���ۼ��ܺͣ�" << sum << endl;
	}
}
void report::shushulianag() {//����������б�
	if (this->FileIsIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < booknum; i++) {
			int minOrmax = i;
			for (int j = i + 1; j < booknum; j++) {//����
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
void report::shujiage() {//����ļ�ֵ���б�
	if (this->FileIsIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
			cout << "������" << bookDataArray[i].bookTitle
				<< "�����ۣ�" << bookDataArray[i].wholesale
				<< "��ֵ�" << sumarray[i] << endl;
		}
	}
}
void report::jingshuriqi() {//�����������б�
	if (this->FileIsIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < booknum; i++) {
			int minOrmax = i;
			for (int j = i + 1; j < booknum; j++) {//����
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
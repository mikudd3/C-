#include"BookData.h"
#include "report.h"
//���캯��
BookData::BookData() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		//cout << "�ļ�������" << endl;
		booknum = 0;//��ʼ������
		TitleInfo bookDataArray[100] = {};//��ʼ������
		FileIsIsEmpty = true;
		ifs.close();
		return;
	}
	string ch;
	ifs >> ch;
	if (ifs.eof()) {//�ļ����ڣ���û�м�¼
		//cout << "�ļ�Ϊ��" << endl;
		booknum = 0;//��ʼ������
		TitleInfo bookDataArray[100] = {};//��ʼ������
		FileIsIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ����Ҽ�¼����
	FileIsIsEmpty = false;
	int num = get_bookNum();
	booknum = num;
	init_book();//���ļ��е����ݣ��浽������

}
//�ж����Ƿ����,���������±�
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
//������
void BookData::lookUpBook() {
	if (FileIsIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "��������Ҫ���ҵ��������" << endl;
		string booktitle;
		cin >> booktitle;
		int index = -1;
		index = isExit(booktitle);
		if (index != -1) {
			BookInfo(index);
		}
		else {
			cout << "û���ҵ��Ȿ��" << endl;
		}
	}
}
//Сдת��д
void BookData::strUpper(string isbn) {
	for (int i = 0; i < 14; i++) {
		if (isbn[i] >= 'a' && isbn[i] <= 'z')
			isbn[i] += 32;
	}
}
//�鿴ĳ�������Ϣ
void BookData::BookInfo(int bnum) {

	int num = bnum;
	cout << "lzyͼ�����ϵͳ" << endl;
	cout << "   �������" << endl;
	cout << "ISBN �� ��" << bookDataArray[num].getISBN() << endl;
	cout << "��   �� ��" << bookDataArray[num].getBookTitle() << endl;
	cout << "��   �� ��" << bookDataArray[num].getAuthor() << endl;
	cout << "������  ��" << bookDataArray[num].getPubisher() << endl;
	cout << "�������ڣ�" << bookDataArray[num].getDataAdded() << endl;
	cout << "�����  ��" << bookDataArray[num].getQtyOnHand() << endl;
	cout << "������  ��" << bookDataArray[num].getWholesale() << endl;
	cout << "���ۼ�  ��" << bookDataArray[num].getRetail() << endl;
}
void BookData::BookInfo() {//չʾ��
	for (int i = 0; i < booknum; i++) {
		cout << "lzyͼ�����ϵͳ" << endl;
		cout << "   �������" << endl;
		cout << "ISBN �� ��" << bookDataArray[i].getISBN() << endl;
		cout << "��   �� ��" << bookDataArray[i].getBookTitle() << endl;
		cout << "��   �� ��" << bookDataArray[i].getAuthor() << endl;
		cout << "������  ��" << bookDataArray[i].getPubisher() << endl;
		cout << "�������ڣ�" << bookDataArray[i].getDataAdded() << endl;
		cout << "�����  ��" << bookDataArray[i].getQtyOnHand() << endl;
		cout << "������  ��" << bookDataArray[i].getWholesale() << endl;
		cout << "���ۼ�  ��" << bookDataArray[i].getRetail() << endl;
	}
}
//������
void BookData::editBook() {
	int addnum = 0;
	cout << "��������Ҫ���ӵ��鱾�ĸ���" << endl;
	cin >> addnum;
	if (addnum > 0) {
		while (addnum) {
			string isbn;//isbn��
			string bookTitle;//����
			string author;//����
			string publisher;//������
			string dataAdded;//��������
			int qtyOnHand;//�����
			double wholesale;//������
			double retail;//���ۼ�
			cout << "������������ISBN��" << endl;
			cin >> isbn;
			bookDataArray[booknum].seTIsbn(isbn);
			cout << "����������������" << endl;
			cin >> bookTitle;
			bookDataArray[booknum].seTitle(bookTitle);
			cout << "����������������" << endl;
			cin >> author;
			bookDataArray[booknum].setAuthor(author);
			cout << "�����������ĳ�����" << endl;
			cin >> publisher;
			bookDataArray[booknum].setPub(publisher);
			cout << "�����������Ľ�������" << endl;
			cin >> dataAdded;
			bookDataArray[booknum].setDataAdded(dataAdded);
			cout << "�����������Ŀ����" << endl;
			cin >> qtyOnHand;
			bookDataArray[booknum].setQty(qtyOnHand);
			cout << "������������������" << endl;
			cin >> wholesale;
			bookDataArray[booknum].setWholesale(wholesale);
			cout << "���������������ۼ�" << endl;
			cin >> retail;
			bookDataArray[booknum].setRetail(retail);
			addnum--;
			booknum++;
			FileIsIsEmpty = false;//����ְ����Ϊ�ձ�־
			save();//�������ݵ��ļ�
		}
		cout << "�ɹ����"<< endl;
	}
	else {
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���
void BookData::modbook() {
	if (FileIsIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "��ѡ����Ҫ�޸ĵ��������" << endl;
		string booktitle;
		cin >> booktitle;
		int index = isExit(booktitle);
		if (index == -1) {
			cout << "û���ҵ�����" << endl;
		}
		else {
			while (true) {
				cout << "��ѡ��Ҫ�޸ĵ�����" << endl;
				cout << "1.isbn��" << endl;
				cout << "2.����" << endl;
				cout << "3.������" << endl;
				cout << "4.������" << endl;
				cout << "5.��������" << endl;
				cout << "6.�����" << endl;
				cout << "7.������" << endl;
				cout << "8�����ۼ�" << endl;
				cout << "9.������һ���˵�" << endl;
				int select = 0;
				cin >> select;
				switch (select) {
				case 1: {
					cout << "�������޸ĺ��isbn" << endl;
					string newisbn;
					cin >> newisbn;
					bookDataArray[index].seTIsbn(newisbn);
					break;
				}
				case 2: {
					cout << "�������޸ĺ������" << endl;
					string newbooktitle;
					cin >> newbooktitle;
					bookDataArray[index].seTitle(newbooktitle);
					break;
				}
				case 3: {
					cout << "�������޸ĺ������" << endl;
					string newauthor;
					cin >> newauthor;
					bookDataArray[index].setAuthor(newauthor);
					break;
				}
				case 4: {
					cout << "�������޸ĺ�ĳ�����" << endl;
					string newpublisher;//������
					cin >> newpublisher;
					bookDataArray[index].setPub(newpublisher);
					break;
				}
				case 5: {
					cout << "�������޸ĺ�Ľ�������" << endl;
					string newdataAdded;//��������
					cin >> newdataAdded;
					bookDataArray[index].setDataAdded(newdataAdded);
					break;
				}
				case 6: {
					cout << "�������޸ĺ�Ŀ����" << endl;
					int newqtyOnHand;//�����
					cin >> newqtyOnHand;
					bookDataArray[index].setQty(newqtyOnHand);
					break;
				}
				case 7: {
					cout << "�������޸ĺ��������" << endl;
					double newwholesale;//������
					cin >> newwholesale;
					bookDataArray[index].setWholesale(newwholesale);
					break;
				}
				case 8: {
					cout << "�������޸ĺ�����ۼ�" << endl;
					double newretail;//���ۼ�
					cin >> newretail;
					bookDataArray[index].setRetail(newretail);
					break;
				}
				case 9:
					shukumenu();
					break;
				default:
					std::cout << "�����������������" << endl;
					break;
				}
				this->save();
				cout << "�޸ĳɹ�" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
//ɾ����
void BookData::deleteBook() {
	if (FileIsIsEmpty) {
		cout << "�ļ������ڻ��ı�Ϊ��" << endl;
	}
	else {
		string booktitle;
		cout << "������Ҫɾ��������" << endl;
		cin >> booktitle;
		int index = isExit(booktitle);
		if (index != -1) {
			for (int i = 0; i < this->booknum - 1; i++) {
				bookDataArray[i] = bookDataArray[i + 1];
			}
			booknum--;
			save();
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ�δ�ҵ�����" << endl;
		}
	}
}
//�����ļ�
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
	//�ر��ļ�
	ofs.close();
}
//ͳ���鱾��
int BookData::get_bookNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string isbn;//isbn��
	string bookTitle;//����
	string author;//����
	string publisher;//������
	string dataAdded;//��������
	int qtyOnHand;//�����
	double wholesale;//������
	double retail;//���ۼ�
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
//�������ݵ�����
void BookData::init_book() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string isbn;//isbn��
	string bookTitle;//����
	string author;//����
	string publisher;//������
	string dataAdded;//��������
	int qtyOnHand;//�����
	double wholesale;//������
	double retail;//���ۼ�
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
		cout << "lzyͼ�����ϵͳ" << endl;
		cout << "   ���˵�	 " << endl;
		cout << "1.����ģ��" << endl;
		cout << "2.������ϵͳ" << endl;
		cout << "3.����ģ��" << endl;
		cout << "4.�˳�ϵͳ" << endl;
		int select = 0;
		cout << "���������ѡ��" << endl;
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
			std::cout << "��ӭ�´�ʹ�ã���" << endl;
			return;
			break;
		default:
			std::cout << "�������,���������룡��" << endl;
			break;
		}
	}
}
//���˵�
void BookData::shukumenu() {
	int flag = 1;
	while (flag) {
		cout << "lzyͼ�����ϵͳ" << endl;
		cout << "  ������ģ��" << endl;
		cout << "1.����ĳ�������Ϣ" << endl;
		cout << "2.������" << endl;
		cout << "3.�޸������Ϣ" << endl;
		cout << "4.ɾ����" << endl;
		cout << "5.�������˵�" << endl;
		cout << "   ����ѡ��1-5��" << endl;
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
			std::cout << "�����������������" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}
void BookData::salemenu() {
	while (true) {
		cout << "lzyͼ�����ϵͳ" << endl;
		cout << "	����ģ��" << endl;
		cout << "1.����ͼ��" << endl;
		cout << "2.�������˵�" << endl;
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
//����
void BookData::sale() {
	cout << "��������Ҫ������������" << endl;
	string title;
	cin >> title;
	int cnt = isExit(title);
	if (cnt != -1) {
		if (bookDataArray[cnt].qtyOnHand == 0) {
			cout << "����������" << endl;
			salemenu();
		}
		else {
			cout << "������Ҫ����������" << endl;
			int qty;
			cin >> qty;
			if (bookDataArray[cnt].qtyOnHand < qty) {
				cout << "��治��" << endl;
			}
			else {
				double sale = bookDataArray[cnt].retail * qty * 0.06;
				double price = bookDataArray[cnt].retail * qty + sale;
				bookDataArray[cnt].qtyOnHand -= qty;
				cout << "����ɹ�" << endl;
				save();
				cout << bookDataArray[cnt].bookTitle << qty
					<< bookDataArray[cnt].wholesale
					<< "˰�" << sale << endl;
			}
		}
	}
	else {
		cout << "�Ҳ�������" << endl;
	}

}

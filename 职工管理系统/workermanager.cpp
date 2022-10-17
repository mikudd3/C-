#include"workermanager.h"
workermanager:: workermanager() {//���캯��
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		//cout << "�ļ�������" << endl;
		this->m_empNum = 0;//��ʼ������
		this->m_empArray = NULL;//��ʼ������
		this->m_FileIsEmpty = true;
		ifs.close();
		return ;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()){//�ļ����ڣ���û�м�¼
		//cout << "�ļ�Ϊ��" << endl;
		this->m_empNum = 0;//��ʼ������
		this->m_empArray = NULL;//��ʼ������
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->m_empNum = num;

	this->m_empArray = new worker * [this->m_empNum];//���ٿռ�
	this->init_Emp();//���ļ��е����ݣ��浽������
	/*for (int i = 0; i < this->m_empNum; i++) {
		cout << " ְ����ţ�" << this->m_empArray[i]->m_id
			<< " ������" << this->m_empArray[i]->m_Name
			<< " ���ű�ţ�" << this->m_empArray[i]->m_Deptid << endl;
	}*/
}
void workermanager::show_menu() {
	cout << "******************************************" << endl;
	cout << "********** ��ӭʹ��ְ������ϵͳ **********" << endl;
	cout << "************** 0.�˳�����ϵͳ ************" << endl;
	cout << "************** 1.����ְ����Ϣ ************" << endl;
	cout << "************** 2.��ʾְ����Ϣ ************" << endl;
	cout << "************** 3.ɾ��ְ����Ϣ ************" << endl;
	cout << "************** 4.�޸�ְ����Ϣ ************" << endl;
	cout << "************** 5.����ְ����Ϣ ************" << endl;
	cout << "************** 6.���ձ������ ************" << endl;
	cout << "************** 7.��������ĵ� ************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}
void workermanager::exitSystem() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}
void workermanager::Add_emp() {//����Ա��
	cout << "����������ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		int newsize = this->m_empNum + addNum;//�����¿ռ��С
		worker** newSpace = new worker * [newsize];//�����¿ռ�
		if (this->m_empArray != NULL) {//��ԭ�ռ����ݴ�ŵ��¿ռ�
			for (int i = 0; i < this->m_empNum; i++) {
				newSpace[i] = this->m_empArray[i];
			}
		}
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "������" << i + 1 << "��ְ�����" << endl;
			cin >> id;
			cout << "������" << i + 1 << "��ְ������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			worker* worker = NULL;
			switch (dSelect) {
			case 1://��ͨԱ��
				worker = new employee(id, name, 1);
				break;
			case 2://����
				worker = new manager(id, name, 2);
				break;
			case 3://�ϰ�
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_empNum + i] = worker;
		}
		delete[] this->m_empArray;//�ͷ�ԭ�пռ�
		this->m_empArray = newSpace;

		this->m_empNum = newsize;//���¸���
		this->m_FileIsEmpty = false;//����ְ����Ϊ�ձ��
		this->save();
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
	}
	else {
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}
void workermanager::show_emp(){//��ʾְ����Ϣ
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < m_empNum; i++) {
			this->m_empArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
int workermanager::IsExist(int id) {//�жϸ�ְ���Ƿ����
	int index = -1;
	for (int i = 0; i < m_empNum; i++) {
		if (this->m_empArray[i]->m_id = id) {
			index = i;
			break;
		}
	}
	return index;
}
void workermanager::delete_emp() {//ɾ��ְ����Ϣ
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "������ְ�����" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);//�жϸ�ְ���Ƿ����
		if (index != -1) {
			for (int i = 0; i < this->m_empNum - 1; i++) {
				this->m_empArray[i] = this->m_empArray[i + 1];
			}
			this->m_empNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ�δ�ҵ���Ա��" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workermanager::mod_emp() {//�޸�ְ����Ϣ
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "��������Ҫ�޸ĵ�Ա�����" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {
			cout << "��������Ҫ�޸ĵ����ݣ�" << endl;
			cout << "1.���" << endl;
			cout << "2.����" << endl;
			cout << "3.���ű��" << endl;
			int newid = 0;
			string newname = "";
			int newdid = 0;
			int select = 0;
			cin >> select;
			switch (select) {
				case 1:
					cout << "�������޸ĺ�ı�ţ�" << endl;
					cin >> newid;
					this->m_empArray[index]->m_id = newid;
					break;
				case 2:
					cout << "�������޸ĺ��������" << endl;
					cin >> newname;
					this->m_empArray[index]->m_Name = newname;
					break;
				case 3:
					cout << "�������޸ĺ�Ĳ��ű�ţ�" << endl;
					cin >> newdid;
					this->m_empArray[index]->m_Deptid = newdid;
					break;
				default:
					break;
			}
			this->save();
			cout << "�޸ĳɹ�" << endl;
		}
		else {
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workermanager::find_emp() {//����ְ����Ϣ
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			int id;
			cout << "��������Ҫ���ҵ�ְ�����" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1) {
				cout << "���ҳɹ�" << endl;
				this->m_empArray[ret]->showInfo();
			}
			else {
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2) {
			string name;
			cout << "��������Ҫ���ҵ��˵�����" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_empNum; i++) {
				if (m_empArray[i]->m_Name == name) {
					cout << "���ҳɹ���ְ�����Ϊ;"
						<< m_empArray[i]->m_id
						<< "�ŵ���Ϣ���£�" << endl;
					flag = true;
					this->m_empArray[i]->showInfo();
				}
			}
			if (flag == false) {
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else {
			cout << "����ѡ�����" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workermanager::sort_emp() {//���ձ������
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.��ְ���Ž�������" << endl;
		cout << "2.��ְ���Ž��н���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_empNum; i++) {
			int minOrmax = i;
			for (int j = i + 1; j < m_empNum; j++) {
				if (select == 1) {//����
					if (this->m_empArray[minOrmax]->m_id > this->m_empArray[j]->m_id) {
						minOrmax = j;
					}
				}
				else {//����
					if (this->m_empArray[minOrmax]->m_id < this->m_empArray[j]->m_id) {
						minOrmax = j;
					}
				}
			}
			if (i != minOrmax) {
				worker* temp = m_empArray[i];
				m_empArray[i] = m_empArray[minOrmax];
				m_empArray[minOrmax] = temp;
			}
		}
		cout << "����ɹ����������Ϊ��" << endl;
		this->save();
		this->show_emp();
	}
}
void workermanager::clean_file() {//��������ĵ�
	cout << "ȷ����գ�" << endl;
	cout << "1.yes" << endl;
	cout << "2.no" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_empArray != NULL) {
			for (int i = 0; i < this->m_empNum; i++) {
				if (this->m_empArray[i] != NULL) {
					delete this->m_empArray[i];
				}
			}
			this->m_empNum = 0;
			delete[] this->m_empArray;
			this->m_empArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}
void workermanager::save() {//�����ļ�
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_empNum; i++) {
		ofs << this->m_empArray[i]->m_id << " "
			<< this->m_empArray[i]->m_Name << " "
			<< this->m_empArray[i]->m_Deptid << endl;
	}
	//�ر��ļ�
	ofs.close();
}
int workermanager::get_EmpNum(){//ͳ������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		num++;
	}
	ifs.close();
	return num;
}
void workermanager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		worker* worker = NULL;
		if (did == 1) {
			worker = new employee(id, name, did);
		}
		else if (did == 2) {
			worker = new manager(id, name, did);
		}
		else {
			worker = new boss(id, name, did);
		}
		this->m_empArray[index] = worker;
		index++;
	}
	ifs.close();
}
workermanager::~workermanager() {//��������
	if (this->m_empArray != NULL) {
		delete[] this->m_empArray;
		this->m_empArray = NULL;
	}
}
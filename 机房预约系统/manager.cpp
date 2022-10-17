#include"manager.h"

//Ĭ�Ϲ���
Manager::Manager() {

}

//�вι���  ����������������
Manager::Manager(string name, string pwd) {
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ȡ��Ϣ
	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);
	}
	ifs.close();
	cout << "����������Ϊ��" << vCom.size() << endl;
}

//�˵�����
void Manager::operMenu() {
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t --------------------------\n";
	cout << "\t\t|                          \n";
	cout << "\t\t|        1.����˺�         \n";
	cout << "\t\t|                          \n";
	cout << "\t\t|        2.�鿴�˺�         \n";
	cout << "\t\t|                          \n";
	cout << "\t\t|        3.�鿴����         \n";
	cout << "\t\t|                          \n";
	cout << "\t\t|        4.���ԤԼ         \n";
	cout << "\t\t|                          \n";
	cout << "\t\t|        5.ע����¼         \n";
	cout << "\t\t|                          \n";
	cout << "\t\t --------------------------\n";
	cout << "����������ѡ��";
}

//����˺�
void Manager::addPerson() {
	cout << "��ѡ����Ҫ��ӵ����ͣ�" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2����ӽ�ʦ" << endl;

	string fileName;//�������ļ�����
	string tip;//��ʾid��
	ofstream ofs;//�ļ���������
	string errorTip;//��������ʾ

	int select = 0;
	cin >> select;

	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������룡";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "������ְ���ţ�";
		errorTip = "ְ�����ظ������������룡";
	}

	//����׷�ӵķ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip << endl;

	while (true) {
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret == true) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}

	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ���" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//���ó�ʼ�� ��ʱ����
	this->initVector();
}

void printStudent(Student& s) {
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t) {
	cout << "ְ���ţ�" << t.m_EmpId << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}

//�鿴�˺�
void Manager::showPerson() {
	cout << "��ѡ����Ҫ�鿴�����ͣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴���н�ʦ" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		//�鿴ѧ��
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else {
		//�鿴��ʦ
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

void printComputer(ComputerRoom& c) {
	cout << "������ţ�" << c.m_ComId << " �������������" << c.m_MaxNum << endl;
}

//�鿴������Ϣ
void Manager::showComputer() {
	cout << "������Ϣ���£�" << endl;
	for_each(vCom.begin(), vCom.end(), printComputer);

	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.clear();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector() {
	//ȷ���������
	vStu.clear();
	vTea.clear();

	//��ȡѧ����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}

	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}

	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}

//����ظ�  ����1 ѧ��/ְ����  ����2 ���ͣ�1ѧ�� 2��ʦ��
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else {
		//����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->m_EmpId) {
				return true;
			}
		}
	}
	return false;
}


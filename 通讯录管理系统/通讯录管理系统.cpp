#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
void showMenu() {//�˵�
	cout << "*************************" << endl;
	cout << "*****  1.�����ϵ�� *****" << endl;
	cout << "*****  2.��ʾ��ϵ�� *****" << endl;
	cout << "*****  3.ɾ����ϵ�� *****" << endl;
	cout << "*****  4.������ϵ�� *****" << endl;
	cout << "*****  5.�޸���ϵ�� *****" << endl;
	cout << "*****  6.�����ϵ�� *****" << endl;
	cout << "*****  0.�˳�ϵͳ   *****" << endl;
	cout << "*************************" << endl;
}
struct Person {
	string m_Name;//����
	int m_Sex;//�Ա�1.�У�2.Ů
	int m_Age;//����
	string m_Phone;//�绰����
	string m_Addr;//��ַ
};
struct Addresbooks {
	struct Person personArray[MAX];//ͨѶ¼�������Ա����
	int m_size;//ͨѶ¼����Ա����
};
void addPerson(Addresbooks* abs) {//1.�����ϵ��
	if (abs->m_size == MAX) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "�����������������" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;
		//�绰
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;
		//��ͥסַ
		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_Addr = address;
		//����ͨѶ¼����
		abs->m_size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");//����
	}
}
void showPerson(Addresbooks* abs) {//2.��ʾ��ϵ��
	if (abs->m_size == 0) cout << "��ǰ��¼Ϊ��" << endl;
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "������" << abs->personArray[i].m_Name <<"	";
			if (abs->personArray[i].m_Sex == 1)
				cout << "�Ա�" << "��" <<"	";
			else
				cout << "�Ա�" << "Ů" <<"	";
			cout << "���䣺" << abs->personArray[i].m_Age <<"	";
			cout << "�绰��" << abs->personArray[i].m_Phone <<"	";
			cout << "��ͥסַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");//����
}
int isExist(Addresbooks* abs,string name) {//�ж����Ƿ����
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_Name == name) return i;
	}
	return -1;
}
void deletePerson(Addresbooks* abs) {//3.ɾ����ϵ��
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else cout << "���޴���" << endl;
	system("pause");
	system("cls");//����
}
void findPerson(Addresbooks* abs){//4.������ϵ��
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������" << abs->personArray[ret].m_Name <<"	";
		cout << "�Ա�" << abs->personArray[ret].m_Sex <<"    ";
		cout << "���䣺" << abs->personArray[ret].m_Age <<"    ";
		cout << "�绰��" << abs->personArray[ret].m_Phone <<"    ";
		cout << "��ͥסַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else cout << "���޴���" << endl;
	system("pause");
	system("cls");//����
}
void modifyPerson(Addresbooks* abs) {//5.�޸���ϵ��
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "��������Ҫ�޸ĵĶ���" << endl;
		cout << "1.----�޸�����" << endl;
		cout << "2.----�޸��Ա�" << endl;
		cout << "3.----�޸�����" << endl;
		cout << "4.----�޸ĵ绰" << endl;
		cout << "5.----�޸ļ�ͥסַ" << endl;
		cout << "0.----���޸�" << endl;
		int cnt = 0;
		cin >> cnt;
		switch (cnt) {
		case 1:
		{
			string name1;
			cout << "������������" << endl;
			cin >> name1;
			abs->personArray[ret].m_Name = name1;
			break;
		}
		case 2: 
		{
			//�Ա�
			cout << "�������Ա�" << endl;
			cout << "1---��" << endl;
			cout << "2---Ů" << endl;
			int sex1 = 0;
			while (true) {
				cin >> sex1;
				if (sex1 == 1 || sex1 == 2) {
					abs->personArray[ret].m_Sex = sex1;
					break;
				}
				cout << "�����������������" << endl;
			}
			break;
		}
		case 3: 
		{
			//����
			cout << "����������" << endl;
			int age1 = 0;
			cin >> age1;
			abs->personArray[ret].m_Age = age1;
			break;
		}
		case 4:
		{
			//�绰
			cout << "������绰" << endl;
			string phone1;
			cin >> phone1;
			abs->personArray[ret].m_Phone = phone1;
			break;
		}
		case 5:
		{
			//��ͥסַ
			cout << "�������ͥסַ" << endl;
			string address1;
			cin >> address1;
			abs->personArray[ret].m_Addr = address1;
			break;
		}
		case 0:
			cout << "���˳�" << endl;
			break;
		default:
			break;
		}
	}
	else cout << "���޴���" << endl;
	system("pause");
	system("cls");//����
}
void CleanPerson(Addresbooks* abs) {//6.ɾ��ͨѶ¼
	int ret = 0;
	cout << "�Ƿ�������ͨѶ¼" << endl;
	cout << "1----��" << endl;
	cout << "2---��" << endl;
	cin >> ret;
	if (ret == 1) {
		abs->m_size = 0;
		cout << "ͨѶ¼��ɾ��" << endl;
	}
	system("pause");
	system("cls");//����
}
int main() {
	Addresbooks abs; //����ͨѶ¼�ṹ�����
	abs.m_size = 0;//��ʼ����ǰͨѶ¼����Ա����
	int select = 0;
	while (true) {
		showMenu();//�˵�����
		cin >> select;
		switch (select) {
		case 1:// 1.�����ϵ��
			addPerson(&abs);//���õ�ַ���ݣ������޸��β�
			break;
		case 2://2.��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3.ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://4.������ϵ�� 
			findPerson(&abs);
			break;
		case 5://5.�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6.�����ϵ��
			CleanPerson(&abs);
			break;
		case 0://0.�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

	}
	system("pause");
	return 0;
}
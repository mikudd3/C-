#include<iostream>
using namespace std;
#include"speechmanager.h"
#include<string>
#include<ctime>
int main() {
	//������������
	srand((unsigned int)time(NULL));

	//�������������
	speechmanager sm;
	int choice = 0;
	while (true) {
		sm.show_menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 1://��ʼ����
			sm.startspeech();
			break;
		case 2://�鿴��¼
			sm.showrecord();
			break;
		case 3://��ռ�¼
			sm.clearrecord();
			break;
		case 0://�˳�ϵͳ
			sm.exitsystem();
			break;
		default:
			system("cls");//����
			break;
		}
	}
	system("pause");
	return 0;
}

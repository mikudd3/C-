#include<iostream>
#include "workermanager.h"
using namespace std;
//#include"worker.h"


int main() {
	workermanager wm;
	int choice = 0;
	while (true) {
		wm.show_menu();
		cout << "��ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 0://�˳�����ϵͳ
			wm.exitSystem();
			break;
		case 1://����ְ����Ϣ
			wm.Add_emp();//����Ա��
			break;
		case 2://��ʾְ����Ϣ
			wm.show_emp();
			break;
		case 3://ɾ��ְ����Ϣ
			wm.delete_emp();
			break;
		case 4://�޸�ְ����Ϣ
			wm.mod_emp();
			break;
		case 5://����ְ����Ϣ
			wm.find_emp();
			break;
		case 6://���ձ������
			wm.sort_emp();
			break;
		case 7://��������ĵ�
			wm.clean_file();
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
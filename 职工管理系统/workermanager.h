#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//��׼������
#include<fstream>
#include "worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
#define FILENAME "empFile.txt"
using namespace std;//ʹ�ñ�׼�����ռ�
class workermanager {
public:
	workermanager();//���캯��
	void show_menu();//�˵�
	void exitSystem();//�˳�ϵͳ
	void show_emp();//��ʾְ����Ϣ
	void delete_emp();//ɾ��ְ����Ϣ
	int IsExist(int id);//�жϸ�ְ���Ƿ����
	void mod_emp();//�޸�ְ����Ϣ
	void find_emp();//����ְ����Ϣ
	void sort_emp();//���ձ������
	void clean_file();//��������ĵ�
	int m_empNum;//��¼�ļ��е���������
	worker** m_empArray;//Ա������ָ��
	void Add_emp();//����Ա��
	void save();//�����ļ�
	bool m_FileIsEmpty;
	int get_EmpNum();//ͳ������
	void init_Emp();
	~workermanager();//��������

};

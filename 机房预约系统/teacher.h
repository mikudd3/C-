#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include"orderFile.h"
#include<vector>

class Teacher :public Identity {
	//��ʦ��
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���  ������ְ���š�����������
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//ְ����
	int m_EmpId;
};

#pragma once
using namespace std;
#include"worker.h"
class boss :public worker {
public:
	boss(int id, string name, int did);//���캯��
	virtual void showInfo();//��ʾ������Ϣ
	virtual string getDeptName();//��ȡ��λ����
};
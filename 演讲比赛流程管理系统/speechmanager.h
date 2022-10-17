#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<algorithm>
#include<deque>
#include<numeric>
#include<functional>
#include"speaker.h"
#include<fstream>
class speechmanager
{
public:
	//���캯��
	speechmanager();
	//�˵�����
	void show_menu();
	//�˳�ϵͳ
	void exitsystem();
	//����ѡ������ 12��
	vector<int>v1;
	//��һ�ֽ������� 6��
	vector<int>v2;
	//�ڶ��ֽ������� 3��
	vector<int>victory;
	//��ű�ţ��Լ���Ӧ�ľ���ѡ�� ����
	map<int, speaker> m_speaker;
	//��¼��������
	int m_index;
	//��ʼ������
	void initspeech();
	//����ѡ��
	void createspeaker();
	//��ʼ����
	void startspeech();
	//1.��ǩ
	void speechdraw();
	//2.����
	void speechcontset();
	//3.��ʾ�������
	void showscore();
	//�����¼
	void saverecord();
	//��ȡ��¼
	void loadrecord();
	// �ļ��Ƿ�Ϊ�ձ�־
	bool fileisempty;
	//�����¼
	map<int, vector<string>>m_record;
	//�鿴��¼
	void showrecord();
	//��ռ�¼
	void clearrecord();
	
	//��������
	~speechmanager();
};


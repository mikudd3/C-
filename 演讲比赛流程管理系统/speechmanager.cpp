#include "speechmanager.h"
//���캯��
speechmanager::speechmanager() {
	//��ʼ������
	this->initspeech();
	//����ѡ��
	this->createspeaker();
	//��ȡ��¼
	this->loadrecord();
}
//�˵�����
void speechmanager::show_menu() {
	cout << "********************************************" << endl;
	cout << "************* ��ӭ�μ��ݽ����� *************" << endl;
	cout << "************* 1.��ʼ�ݽ�����   *************" << endl;
	cout << "************* 2.�鿴�����¼   *************" << endl;
	cout << "************* 3.��ձ�����¼   *************" << endl;
	cout << "************* 0.�˳���������   *************" << endl;
	cout << "********************************************" << endl;

}
//��ʼ������
void speechmanager::initspeech() {
	//������֤Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_speaker.clear();
	this->m_index = 1;
	this->m_record.clear();
}
//����ѡ��
void speechmanager:: createspeaker() {
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameseed.size(); i++) {
		string name = "ѡ��";
		name += nameseed[i];
		speaker sp;
		sp.m_name = name;
		for (int i = 0; i < 2; i++) {
			sp.m_score[i] = 0;
		}
		//12��ѡ�ֱ��
		this->v1.push_back(i + 10001);
		//��ѡ�ֱ���Լ���Ӧ��ѡ�ִ�ŵ�map������
		this->m_speaker.insert(make_pair(i + 10001, sp));
	}
}
//��ʼ����
void speechmanager::startspeech() {
	//��һ�ֱ���
	//1.��ǩ
	speechdraw();
	//2.����
	speechcontset();
	//3.��ʾ�������
	showscore();
	this->m_index++;
	//�ڶ��ֱ���

	//1.��ǩ
	speechdraw();
	//2.����
	speechcontset();
	//3.��ʾ�������
	showscore();
	//4.�������
	saverecord();
	//��ʼ������
	this->initspeech();
	//����ѡ��
	this->createspeaker();
	//��ȡ�����¼
	this->loadrecord();

	cout << "����������" << endl;
	system("pause");
	system("cls");
}
//1.��ǩ
void speechmanager::speechdraw() {
	cout << "��" << this->m_index << "�ֱ���ѡ�����ڳ�ǩ"<< endl;
	cout << "----------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (this->m_index == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "----------------------" << endl;
	system("pause");
}
//2.����
void speechmanager::speechcontset() {
	cout << "-------------" << this->m_index << "�ֱ�����ʽ��ʼ��-------------" << endl;
	//��ʱ����������key���� valueѡ�ֱ��
	multimap<double, int, greater<double>>groupscore;
	//��¼��Ա���� 6����ΪһС��
	int num = 0;
	//������Ա����
	vector<int>v_src;
	if (this->m_index == 1) {
		v_src = v1;
	}
	else {
		v_src = v2;
	}
	// �������в���ѡ��
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++) {
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		// ����Ӵ�С
		//greater<double>���ú��������������������н�������
		sort(d.begin(), d.end(), greater<double>());
		//ȥ����ͷ�
		d.pop_back();
		//ȥ����߷�
		d.pop_front();
		//�ܷ�
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		//ƽ����
		double avg = sum / (double)d.size();
		//ÿ����ƽ����
		this->m_speaker[*it].m_score[this->m_index - 1] = avg;
		//6 ����һ�飬����ʱ��������
		groupscore.insert(make_pair(avg, *it));
		if (num % 6 == 0) {
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			//greater<double>���ú��������������������н�������
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end(); it++) {
				cout << "��ţ�" << it->second << "������" << this->m_speaker[it->second].m_name
					<< "�ɼ���" << this->m_speaker[it->second].m_score[this->m_index - 1] << endl;
			}
			int count = 0;
			//ȡǰ����
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end() && count < 3; it++, count++) {
				if (this->m_index == 1) {
					v2.push_back((*it).second);
				}
				else {
					victory.push_back((*it).second);
				}
			}
			groupscore.clear();
			cout << endl;
		}
	}
	cout << "--------------��" << this->m_index << "�ֱ������� --------------" << endl;
	system("pause");
}
//3.��ʾ�������
void speechmanager::showscore() {
	cout << "--------------��" << this->m_index << "�ֽ���������£�--------------" << endl;
	vector<int>v;
	if (this->m_index == 1) {
		v = v2;
	}
	else {
		v = victory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "ѡ�ֱ�ţ�" << *it << "������" << this->m_speaker[*it].m_name << "�÷֣�"
			<< this->m_speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_menu();
}
//�����¼
void speechmanager::saverecord() {
	ofstream ofs;
	//������ķ�ʽ���ļ���д�ļ�
	ofs.open("speech.csv", ios::out | ios::app);
	//��ÿ������д�뵽�ļ��С�
	for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++) {
		ofs << *it << "," << this->m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "�ļ��ѱ���" << endl;
	this->fileisempty = false;
}
//��ȡ��¼
void speechmanager::loadrecord() {
	//���������󣬶�ȡ�ļ�
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open()) {
		this->fileisempty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		this->fileisempty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	this->fileisempty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	while (ifs >> data) {
		vector<string> v;
		int pos = -1;
		int start = 0;
		while (true) {
			pos = data.find(",", start);
			if (pos == -1) {
				break;
			}
			string tmp = data.substr(start, pos - start);
			v.push_back(tmp);
			start = pos + 1;
		}
		this->m_record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

}
//�鿴��¼
void speechmanager::showrecord() {
	if (this->fileisempty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < this->m_record.size(); i++) {
			cout << "��" << i + 1 << "������"
				<< "�ھ���ţ�" << this->m_record[i][0] << "�÷֣�" << this->m_record[i][1] << " "
				<< "�Ǿ���ţ�" << this->m_record[i][2] << "�÷֣�" << this->m_record[i][3] << " "
				<< "������ţ�" << this->m_record[i][4] << "�÷֣�" << this->m_record[i][5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}
//�˳�ϵͳ
void speechmanager::exitsystem() {
	cout << "��ӭ�´�ʹ�ã���" << endl;
	system("pause");
	exit(0);
}
//��ռ�¼
void speechmanager::clearrecord() {
	cout << "ȷ�����" << endl;
	cout << "1.��" << endl;
	cout << "2,��" << endl;
	int select = 0;
	if (select == 1) {
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initspeech();
		this->createspeaker();
		this->loadrecord();
		cout << "��ճɹ�" <<endl;
	}
	system("pause");
	system("cls");
}
//��������
speechmanager::~speechmanager() {

}
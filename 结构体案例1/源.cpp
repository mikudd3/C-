#include<iostream>
#include<string>
#include<ctime>
using namespace std;
struct student {
	string sname;//����
	int score;//����
};
struct teacher {
	string tname;
	struct student sarray[5];
};
void allocateSpace(struct teacher tarray[], int len) {
	string nameseed = "ABCDE";
	for (int i = 0; i < len; i++) {
		//����ʦ��ֵ
		tarray[i].tname = "teacher_";
		tarray[i].tname += nameseed[i];
		//��ѧ����ֵ
		for (int j = 0; j < 5; j++) {
			tarray[i].sarray[j].sname = "student_";
			tarray[i].sarray[j].sname += nameseed[j];

			int random = rand() % 61 + 40;//�������
			tarray[i].sarray[j].score = random;//��ѧ���ķ�����ֵ
		}
	}
}
//��ӡ���
void printInfo(struct teacher tarray[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "��ʦ������" << tarray[i].tname << endl;//�����ʦ
		for (int j = 0; j < 5; j++) {
			cout << "\tѧ��������" << tarray[i].sarray[j].sname <<
				"\t���Է���:" << tarray[i].sarray[j].score << endl;
		}
	}
}
int main() {
	srand((unsigned int)time(NULL);)
	struct teacher tarray[3];//����һ����ʦ������
	int len = sizeof(tarray) / sizeof(tarray[0]);//�����鳤��
	allocateSpace(tarray, len);//����ʦ��ѧ����ֵ
	printInfo(tarray, len);//��ӡ���
	return 0;
}
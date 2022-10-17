#include<iostream>
#include<string>
#include<ctime>
using namespace std;
struct student {
	string sname;//姓名
	int score;//分数
};
struct teacher {
	string tname;
	struct student sarray[5];
};
void allocateSpace(struct teacher tarray[], int len) {
	string nameseed = "ABCDE";
	for (int i = 0; i < len; i++) {
		//给老师赋值
		tarray[i].tname = "teacher_";
		tarray[i].tname += nameseed[i];
		//给学生赋值
		for (int j = 0; j < 5; j++) {
			tarray[i].sarray[j].sname = "student_";
			tarray[i].sarray[j].sname += nameseed[j];

			int random = rand() % 61 + 40;//随机分数
			tarray[i].sarray[j].score = random;//给学生的分数赋值
		}
	}
}
//打印输出
void printInfo(struct teacher tarray[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "老师姓名：" << tarray[i].tname << endl;//输出老师
		for (int j = 0; j < 5; j++) {
			cout << "\t学生姓名：" << tarray[i].sarray[j].sname <<
				"\t考试分数:" << tarray[i].sarray[j].score << endl;
		}
	}
}
int main() {
	srand((unsigned int)time(NULL);)
	struct teacher tarray[3];//创建一个老师的数组
	int len = sizeof(tarray) / sizeof(tarray[0]);//求数组长度
	allocateSpace(tarray, len);//给老师和学生赋值
	printInfo(tarray, len);//打印输出
	return 0;
}
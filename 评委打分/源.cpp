#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
#include<ctime>
class person {
public:
	person(string n, int s) {
		this->name = n;
		this->score = s;
	}
	string name;
	int score;
};
void creatperson(vector<person>& v) {
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "选手";
		name += nameseed[i];
		int score = 0;
		person p(name, score);
		v.push_back(p);
	}
}
void setscore(vector<person>& v) {
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++) {
		deque<int> d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum += *dit;
		}
		int avg = sum / d.size();
		it->score = avg;
	}
}
void showscore(vector<person>& v) {
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "姓名：" << it->name << "平均分：" << it->score << endl;
	}
}
int main() {
	//创建选手容器
	srand((unsigned int)time(NULL));
	vector<person> p;
	creatperson(p);
	setscore(p);
	showscore(p);
	system("pause");
	return 0;
}
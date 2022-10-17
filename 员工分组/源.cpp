#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class worker {
public:
	worker(){}
	worker(string name, int salary) {
		this->m_Name = name;
		this->m_salary = salary;
	}
	string m_Name;
	int m_salary;
};
void createworker(vector<worker>& v) {
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		worker w;
		w.m_Name = "员工";
		w.m_Name += nameseed[i];
		w.m_salary = rand() % 10000 + 10000;

		v.push_back(w);
	}
}
void setgroud(vector<worker>& v, multimap<int, worker>&m) {
	for (vector<worker>::iterator it = v.begin(); it != v.end(); it++) {
		int deptid = rand() % 3;
		m.insert(make_pair(deptid, *it));
	}
}
void showworker(multimap<int, worker>&m) {
	cout << "策划部门：" << endl;
	multimap<int, worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++,index++) {
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_salary << endl;
	}
	cout << "美术部门：" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_salary << endl;
	}
	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_salary << endl;
	}
}
int main() {
	// 1.创建员工
	vector<worker>vworker;
	createworker(vworker);
	//2.员工分组
	multimap<int, worker>mworker;
	setgroud(vworker, mworker);
	//3.展示员工 
	showworker(mworker);

	system("pause");
	return 0;
}
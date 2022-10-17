#include"boss.h"
boss::boss(int id, string name, int did) {
	this->m_id = id;
	this->m_Name = name;
	this->m_Deptid = did;
}
void boss::showInfo() {
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t职工职责：管理公司所有事务" << endl;
}
string boss::getDeptName() {
	return string("老板");
}
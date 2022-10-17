#include"manager.h"
manager::manager(int id, string name, int did) {
	this->m_id = id;
	this->m_Name = name;
	this->m_Deptid = did;
}
void manager::showInfo() {
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t职工职责：完成老板交给的任务，并下发给员工" << endl;
}
string manager::getDeptName() {
	return string("经理");
}
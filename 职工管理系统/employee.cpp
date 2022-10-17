#include"employee.h"
employee::employee(int id, string name, int did) {
	this->m_id = id;
	this->m_Name = name;
	this->m_Deptid = did;
}
void employee::showInfo() {
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t职工职责：完成经理交给的任务" << endl;
}
string employee::getDeptName() {
	return string("员工");
}
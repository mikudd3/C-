#include"employee.h"
employee::employee(int id, string name, int did) {
	this->m_id = id;
	this->m_Name = name;
	this->m_Deptid = did;
}
void employee::showInfo() {
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\tְ��ְ����ɾ�����������" << endl;
}
string employee::getDeptName() {
	return string("Ա��");
}
#include"manager.h"
manager::manager(int id, string name, int did) {
	this->m_id = id;
	this->m_Name = name;
	this->m_Deptid = did;
}
void manager::showInfo() {
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\tְ��ְ������ϰ彻�������񣬲��·���Ա��" << endl;
}
string manager::getDeptName() {
	return string("����");
}
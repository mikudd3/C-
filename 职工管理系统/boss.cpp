#include"boss.h"
boss::boss(int id, string name, int did) {
	this->m_id = id;
	this->m_Name = name;
	this->m_Deptid = did;
}
void boss::showInfo() {
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\tְ��ְ�𣺹���˾��������" << endl;
}
string boss::getDeptName() {
	return string("�ϰ�");
}
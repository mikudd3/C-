#include"hire.h"
#include"elite.h"
hire::hire(char c) {
	this->character = c;
}
hire::hire(double agility, double strength, double speed) {
	this->agility = agility;
	this->speed = strength;
	this->strength = speed;
}
void hire::operator +(hire& h1) {
	if ((character == 'l' && h1.character == 'l')) {
		cout << "���ź������ǲ������" << endl;
	}
	else if ((character == 'm' && h1.character == 'm')) {
		cout << "�������ǿ������" << endl;
	}
	else {
		cout << "��ϲ�������������" << endl;
	}
}
void hire::menu() {
	agility = strength = speed = 0;
	cout << "================" << endl;
	cout << "===1.fox     ===" << endl;
	cout << "===2.bunny   ===" << endl;
	cout << "===3.sloth   ===" << endl;
	cout << "===4.�˳�ϵͳ===" << endl;
	cout << "================" << endl;
}
double hire::fox() {
	agility = strength = speed = 0;
	cout << "Enter agility " << endl;
	cin >> agility;
	cout << " Enter strength" << endl;
	cin >> strength;
	cout << "Hire score:" << hirescore() << endl;
	return hirescore();
}
double hire::bunny() {
	agility = strength = speed = 0;
	cout << "Enter agility " << endl;
	cin >> agility;
	cout << " Enter speed" << endl;
	cin >> speed;
	cout << "Hire score:" << hirescore() << endl;
	return hirescore();
}
double hire::sloth() {
	agility = strength = speed = 0;
	cout << "Enter strength " << endl;
	cin >> strength;
	cout << " Enter speed" << endl;
	cin >> speed;
	cout << "Hire score:" << hirescore() << endl;
	return hirescore();
}
void hire::choose(hire& h) {
	cout << "��������ѡ�����Ը�l/m/h��" << endl;
	cin >> h.character;
	(*this) + h;
}
double hire::hirescore() {
	return 1.8 * agility + 2.16 * strength + 3.24 * speed;
}
void hire::display1() {
	cout << "agility is" << agility << "," << "strength is " << strength << "," << "speed is" << speed << endl;
}

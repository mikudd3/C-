#include<iostream>
using namespace std;
class applicant {
public:
	applicant(float a, float str, float spe) :agility(a), strength(str), speed(spe) {};//���캯��
	void menu();//��ʼ�˵�
	void showmenu();//ѡ��˵�
	void fox();
	void bunny();
	void sloth();
	void display();
private:
	double agility, strength, speed;
};
void applicant::menu() {//��ʼ�˵�
	cout << "================" << endl;
	cout << "===1.fox     ===" << endl;
	cout << "===2.bunny   ===" << endl;
	cout << "===3.sloth   ===" << endl;
	cout << "===4.�˳�ϵͳ===" << endl;
	cout << "================" << endl;
}
void applicant::fox() {//��fox����
	cout << "Enter agility " << endl;
	cin >> agility;
	cout << " Enter strength" << endl;
	cin >> strength;
	cout << "Hire score:" << 1.0 * agility + 2.16 * strength + 3.24 * speed << endl;
}
void applicant::bunny() {//��bunny����
	cout << "Enter agility " << endl;
	cin >> agility;
	cout << " Enter speed" << endl;
	cin >> speed;
	cout << "Hire score:" << 1.0 * agility + 2.16 * strength + 3.24 * speed << endl;
}
void applicant::sloth() {//��sloth����
	cout << "Enter strength " << endl;
	cin >> strength;
	cout << " Enter speed" << endl;
	cin >> speed;
	cout << "Hire score:" << 1.0 * agility + 2.16 * strength + 3.24 * speed << endl;
}
void applicant::showmenu() {//ѡ��˵�
	int flag = 1;
	while (flag) {
		menu();
		cout << " please choose an animal or exist:";
		char x;
		cin >> x;
		switch (x) {
		case '1'://ѡ��fox
			fox();
			display();
			flag = 0;
			break;
		case'2'://ѡ��bunny
			bunny();
			display();
			flag = 0;
			break;
		case'3'://ѡ��sloth
			sloth();
			display();
			flag = 0;
			break;
		case'4':
			std::cout << "good bye!!" << endl;//�˳�����
			flag = 0;
			break;
		default:
			std::cout << "�����������������" << endl;
			break;
		}
	}

}
void applicant::display() {//չʾ����
	cout << "agility is " << agility << "," << "strength is " << strength << "," << "speed is " << speed << endl;
}
int main() {
	applicant user1(0, 0, 0);
	user1.showmenu();
	return 0;
}
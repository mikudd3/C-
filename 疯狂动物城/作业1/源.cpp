#include<iostream>
using namespace std;
class applicant {
public:
	applicant(float a, float str, float spe) :agility(a), strength(str), speed(spe) {};//构造函数
	void menu();//初始菜单
	void showmenu();//选择菜单
	void fox();
	void bunny();
	void sloth();
	void display();
private:
	double agility, strength, speed;
};
void applicant::menu() {//初始菜单
	cout << "================" << endl;
	cout << "===1.fox     ===" << endl;
	cout << "===2.bunny   ===" << endl;
	cout << "===3.sloth   ===" << endl;
	cout << "===4.退出系统===" << endl;
	cout << "================" << endl;
}
void applicant::fox() {//对fox计算
	cout << "Enter agility " << endl;
	cin >> agility;
	cout << " Enter strength" << endl;
	cin >> strength;
	cout << "Hire score:" << 1.0 * agility + 2.16 * strength + 3.24 * speed << endl;
}
void applicant::bunny() {//对bunny计算
	cout << "Enter agility " << endl;
	cin >> agility;
	cout << " Enter speed" << endl;
	cin >> speed;
	cout << "Hire score:" << 1.0 * agility + 2.16 * strength + 3.24 * speed << endl;
}
void applicant::sloth() {//对sloth计算
	cout << "Enter strength " << endl;
	cin >> strength;
	cout << " Enter speed" << endl;
	cin >> speed;
	cout << "Hire score:" << 1.0 * agility + 2.16 * strength + 3.24 * speed << endl;
}
void applicant::showmenu() {//选择菜单
	int flag = 1;
	while (flag) {
		menu();
		cout << " please choose an animal or exist:";
		char x;
		cin >> x;
		switch (x) {
		case '1'://选择fox
			fox();
			display();
			flag = 0;
			break;
		case'2'://选择bunny
			bunny();
			display();
			flag = 0;
			break;
		case'3'://选择sloth
			sloth();
			display();
			flag = 0;
			break;
		case'4':
			std::cout << "good bye!!" << endl;//退出程序
			flag = 0;
			break;
		default:
			std::cout << "输入错误，请重新输入" << endl;
			break;
		}
	}

}
void applicant::display() {//展示数据
	cout << "agility is " << agility << "," << "strength is " << strength << "," << "speed is " << speed << endl;
}
int main() {
	applicant user1(0, 0, 0);
	user1.showmenu();
	return 0;
}
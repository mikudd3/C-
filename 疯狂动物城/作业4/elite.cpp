#include"elite.h"


elite::elite(char c) {
	this->character = c;
}
elite::elite(double insight, double logic) {
	this->insight = insight;
	this->logic = logic;
}
void elite::ischose() {
	double ret = hirescore();
	if (ret > 31.3) {
		cout << "��ϲ���㱻¼����" << endl;
		minimenu();
	}
	else {
		cout << "���ź�����û��¼ȡ" << endl;
	}
}
void elite::showmenu() {
	int flag = 1;
	while (flag) {
		menu();
		cout << " please choose an animal or exist:";
		char x;
		cin >> x;
		switch (x) {
		case '1': {
			fox();
			display1();
			ischose();
			flag = 0;
			break;
		}
		case'2': {
			bunny();
			display1();
			ischose();
			flag = 0;
			break;
		}
		case'3': {
			sloth();
			display1();
			ischose();
			flag = 0;
			break;
		}
		case'4':
			cout << "good bye!!" << endl;
			flag = 0;
			break;
		default:
			std::cout << "�����������������" << endl;
			break;
		}
	}
}
void elite::minimenu() {
	int flag = 1;
	cout << "����������Ը�l/m/h��" << endl;
	cin >> character;
	hire fox('l'), bunny('l'), sloth('l');
	while (flag) {
		cout << "��ѡ����Ĵ" << endl;
		menu();
		char x;
		cin >> x;
		switch (x) {
		case '1':
			choose(fox);
			judge();
			flag = 0;
			break;
		case'2':
			choose(bunny);
			judge();
			flag = 0;
			break;
		case'3':
			choose(sloth);
			judge();
			flag = 0;
			break;
		case'4':
			cout << "good bye!!" << endl;
			flag = 0;
			break;
		default:
			std::cout << "�����������������" << endl;
			break;
		}
	}
}
void elite::judge() {//�ж�
	int flag = 1;
	while (flag) {
		cout << "������insight��" << endl;
		cin >> insight;
		cout << "������logic��" << endl;
		cin >> logic;
		display();
		if ((insight < 0 || insight > 100) && (logic < 0 || logic > 100)) {
			cout << "Invalid values" << endl;
			flag = 0;
			break;
		}
		else if (insight >= 95 && logic >= 95) {
			cout << "Congratulations! Welcome to join our elite team!" << endl;
			flag = 0;
			break;
		}
		else {
			cout << "Unfortunately, you are not fit to our elite team." << endl;
			flag = 0;
			break;
		}
	}
}
void elite::display() {
	cout << "insight is" << insight << "," << "logic is " << logic << endl;
}

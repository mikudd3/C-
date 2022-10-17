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
		cout << "恭喜，你被录用了" << endl;
		minimenu();
	}
	else {
		cout << "很遗憾，你没被录取" << endl;
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
			std::cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
}
void elite::minimenu() {
	int flag = 1;
	cout << "请输入你的性格（l/m/h）" << endl;
	cin >> character;
	hire fox('l'), bunny('l'), sloth('l');
	while (flag) {
		cout << "请选择你的搭档" << endl;
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
			std::cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
}
void elite::judge() {//判断
	int flag = 1;
	while (flag) {
		cout << "请输入insight：" << endl;
		cin >> insight;
		cout << "请输入logic：" << endl;
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

#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class hire {
public:
	hire (char c) :character(c) {};//构造函数
	void menu();//初始菜单
	void showmenu();//选择主菜单
	void minimenu();//选择子菜单
	void choose(hire& h);
	double fox();//计算fox得分
	double bunny();
	double sloth();
	void operator +(hire& h1);//重载+号运算符
	double hirescore();//计算得分
	void ischoose();//判断是否合格
	void display();//展示数据
private:
	double agility, strength, speed;
	char character;
};
void hire::operator +(hire& h1){//重载+号运算符
	if ((character == 'l' && h1.character == 'l'))
		cout << "很遗憾，你们不能组队" << endl;
	else if ((character == 'm' && h1.character == 'm'))
		cout << "不错，你们可以组队" << endl;
	else
		cout << "恭喜，你们是完美搭档" << endl;
}
void hire::menu() {//初始菜单
	agility = strength = speed = 0;
	cout << "================" << endl;
	cout << "===1.fox  ======" << endl;
	cout << "===2.bunny======" << endl;
	cout << "===3.sloth======" << endl;
	cout << "===4.退出系统===" << endl;
	cout << "================" << endl;
}
double hire::fox() {//计算fox得分
	agility = strength = speed = 0;
	cout << "Enter agility " << endl;
	cin >> agility;
	cout << " Enter strength" << endl;
	cin >> strength;
	cout << "Hire score:" << hirescore() << endl;
	return hirescore();
}
double hire::bunny() {//计算bunny得分
	agility = strength = speed = 0;
	cout << "Enter agility " << endl;
	cin >> agility;
	cout << " Enter speed" << endl;
	cin >> speed;
	cout << "Hire score:" << hirescore() << endl;
	return hirescore();
}
double hire::sloth() {//计算sloth得分
	agility = strength = speed = 0;
	cout << "Enter strength " << endl;
	cin >> strength;
	cout << " Enter speed" << endl;
	cin >> speed;
	cout << "Hire score:" << hirescore() << endl;
	return hirescore();
}
void hire::ischoose() {//判断得分是否合格
	double ret = hirescore();
	if (ret > 31.3) {
		cout << "恭喜，你被录用了" << endl;
		minimenu();//合格则跳转子菜单
	}
	else {//不合格则退出程序
		cout << "很遗憾！你没有被录取" << endl;
	}
}
void hire::showmenu() {//主菜单
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
			ischoose();
			double ret = hirescore();
			if (ret > 31.3) {
				cout << "恭喜，你被录用了" << endl;
				minimenu();//合格则跳转子菜单
			}
			else {//不合格则退出程序
				cout << "很遗憾！你没有被录取" << endl;
			}
			flag = 0;
			break;
		case'2'://选择bunny
			bunny();
			display();
			ischoose();
			flag = 0;
			break;
		case'3'://选择sloth
			sloth();
			display();
			ischoose();
			flag = 0;
			break;
		case'4':
			std::cout << "good bye!!" << endl;
			flag = 0;
			break;
		default:
			std::cout << "输入错误" << endl;
			break;
		}
	}

}
void hire::minimenu() {//子菜单
	int flag = 1;
	cout<<"请输入你的性格（l，m，h）: "<<endl;
	cin >> character;//输入性格
	hire fox('l'), bunny('l'), sloth('l');//初始化
	while (flag) {
		cout << "请选择搭档" << endl;
		menu();
		char x;
		cin >> x;
		switch (x) {
		case '1':
			choose(fox);
			flag = 0;
			break;
		case'2':
			choose(bunny);
			flag = 0;
			break;
		case'3':
			choose(sloth);
			flag = 0;
			break;
		case'4':
			std::cout << "good bye!!" << endl;
			flag = 0;
			break;
		default:
			std::cout << "输入错误" << endl;
			break;
		}
	}
}
void hire::choose(hire& h) {
	cout<<"请输入搭档的性格（l,m,h):"<<endl;
	cin>>h.character;//覆盖初始性格
	(*this) + h;//传入性格与覆盖后性格进行+号重载
}
double hire::hirescore() {//计算得分
	return 1.0 * agility + 2.16 * strength + 3.24 * speed;
}
void hire::display() {//展示数据
	cout << "agility is " << agility << "," << "strength is " << strength << "," << "speed is " << speed << endl;
}
int main() {
	hire appl1('l');
	appl1.showmenu();
	return 0;
}
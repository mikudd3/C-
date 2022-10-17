#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class hire
{
private:
	double agi, str, sp;
	char character;
public:
	hire(char c) : character(c) {};//构造函数
	operator int() { return character; }
	hire(int n)//构造函数
	{
		if (n >= 0 && n <= 50)
			character = 'l';
		else if (n > 50 && n <= 80)
			character = 'm';
		else if (n > 80 && n <= 100)
			character = 'h';
		else
			cout << "n必须是不大于100的非负整数" << endl;
	}
	void menu();//初始菜单
	double fox();//计算fox
	double bunny();//计算bunny
	double sloth();//计算sloth
	double hirescore();//计算得分
	void showmenu();//主菜单
	void ischoose();//判断是否录取
	void minimenu();//子菜单
	void operator+(hire& c1);//重载运算符1
	void operator+(int n);//重载运算符2
	void choose(hire& c1);
	void display();

};
void hire::menu() {
	cout << "请选择编号：" << endl;
	cout << "1.fox" << endl;
	cout << "2.bunny" << endl;
	cout << "3.sloth" << endl;
	cout << "4.退出系统" << endl;
}
double hire::fox() {
	agi = str = sp = 0;
	cout << "Enter agility:" << endl;
	cin >> agi;
	cout << "Enter strength:" << endl;
	cin >> str;
	hirescore();
	cout << "Hire Score:" << hirescore() << endl;
	return hirescore();
}
double hire::bunny() {
	agi = str = sp = 0;
	cout << "Enter agility:" << endl;
	cin >> agi;
	cout << "Enter speed:" << endl;
	cin >> sp;
	hirescore();
	cout << "Hire Score:" << hirescore() << endl;
	return hirescore();
}
double hire::sloth() {
	agi = str = sp = 0;
	cout << "Enter strength:" << endl;
	cin >> str;
	cout << "Enter speed:" << endl;
	cin >> sp;
	hirescore();
	cout << "Hire Score:" << hirescore() << endl;
	return hirescore();
}
double hire::hirescore() {
	return 1.8 * agi + 2.16 * str + 3.24 * sp;
}
void hire::ischoose() {
	double r = hirescore();
	if (r > 31.3)
	{
		cout << "恭喜，你被录用了！" << endl;
		cout << "请选择搭档:" << endl;
		minimenu();
	}
}
void hire::choose(hire& c1) {
	cout << "请输入搭档的性格(l/m/h):" << endl;
	cin >> c1.character;
	(*this) + c1;
}
void hire::operator + (hire& c1) {//重载运算符1
	if (character == 'l' && c1.character == 'l')
	{
		cout << "很遗憾，你们不适合组队" << endl;
	}
	else if (character == 'm' && c1.character == 'm')
	{
		cout << "不错，你们可以组队" << endl;
	}
	else
	{
		cout << "恭喜，你们是完美搭档！" << endl;
	}
}
void hire::operator + (int n) {//重载运算符2
	hire a(n);
	if (character == 'l' && a.character == 'l')
	{
		cout << "很遗憾，你们不适合组队" << endl;
	}
	else if (character == 'm' && a.character == 'm')
	{
		cout << "不错，你们可以组队" << endl;
	}
	else
	{
		cout << "恭喜，你们是完美搭档！" << endl;
	}
}
void hire::minimenu() {
	int flag = 1;
	cout << "请输入你的性格(l/m/h):" << endl;
	cin >> character;
	while (flag) {
		menu();
		int j;
		hire fox('l');
		hire bunny('l');
		hire sloth('l');
		cout << "请输入搭档的编号:" << endl;
		cin >> j;
		switch (j){
		case 1:
			choose(fox);
			flag = 0;
			break;
		case 2:
			choose(bunny);
			flag = 0;
			break;
		case 3:
			choose(sloth);
			flag = 0;
			break;
		case 4:
			std::cout << "good bye!!" << endl;
			break;
		default:
			std::cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
}
void hire::showmenu() {
	int flag = 1;
	while (flag){
		menu();
		int i;
		cin >> i;
		switch (i) {
		case 1:
			fox();
			display();
			ischoose();
			flag = 0;
			break;
		case 2:
			bunny();
			display();
			ischoose();
			flag = 0;
			break;
		case 3:
			sloth();
			display();
			ischoose();
			flag = 0;
			break;
		case 4:
			std::cout << "Good bye!" << endl;
			flag = 0;
			break;
		default:
			std::cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
}
void hire::display() {
	cout << "agility is" << agi << "," << "strength is " << str << "," << "speed is" << sp << endl;
}
int main(){
	//测试代码
	hire a1('l');
	hire a2(51);
	//appl1.showmenu();
	a2 + a1;
	a1 + 10;
	cout << 10 + a1 << endl;
	return 0;
}

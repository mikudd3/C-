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
	hire(char c) : character(c) {};//���캯��
	operator int() { return character; }
	hire(int n)//���캯��
	{
		if (n >= 0 && n <= 50)
			character = 'l';
		else if (n > 50 && n <= 80)
			character = 'm';
		else if (n > 80 && n <= 100)
			character = 'h';
		else
			cout << "n�����ǲ�����100�ķǸ�����" << endl;
	}
	void menu();//��ʼ�˵�
	double fox();//����fox
	double bunny();//����bunny
	double sloth();//����sloth
	double hirescore();//����÷�
	void showmenu();//���˵�
	void ischoose();//�ж��Ƿ�¼ȡ
	void minimenu();//�Ӳ˵�
	void operator+(hire& c1);//���������1
	void operator+(int n);//���������2
	void choose(hire& c1);
	void display();

};
void hire::menu() {
	cout << "��ѡ���ţ�" << endl;
	cout << "1.fox" << endl;
	cout << "2.bunny" << endl;
	cout << "3.sloth" << endl;
	cout << "4.�˳�ϵͳ" << endl;
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
		cout << "��ϲ���㱻¼���ˣ�" << endl;
		cout << "��ѡ��:" << endl;
		minimenu();
	}
}
void hire::choose(hire& c1) {
	cout << "���������Ը�(l/m/h):" << endl;
	cin >> c1.character;
	(*this) + c1;
}
void hire::operator + (hire& c1) {//���������1
	if (character == 'l' && c1.character == 'l')
	{
		cout << "���ź������ǲ��ʺ����" << endl;
	}
	else if (character == 'm' && c1.character == 'm')
	{
		cout << "�������ǿ������" << endl;
	}
	else
	{
		cout << "��ϲ���������������" << endl;
	}
}
void hire::operator + (int n) {//���������2
	hire a(n);
	if (character == 'l' && a.character == 'l')
	{
		cout << "���ź������ǲ��ʺ����" << endl;
	}
	else if (character == 'm' && a.character == 'm')
	{
		cout << "�������ǿ������" << endl;
	}
	else
	{
		cout << "��ϲ���������������" << endl;
	}
}
void hire::minimenu() {
	int flag = 1;
	cout << "����������Ը�(l/m/h):" << endl;
	cin >> character;
	while (flag) {
		menu();
		int j;
		hire fox('l');
		hire bunny('l');
		hire sloth('l');
		cout << "�������ı��:" << endl;
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
			std::cout << "�����������������" << endl;
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
			std::cout << "�����������������" << endl;
			break;
		}
	}
}
void hire::display() {
	cout << "agility is" << agi << "," << "strength is " << str << "," << "speed is" << sp << endl;
}
int main(){
	//���Դ���
	hire a1('l');
	hire a2(51);
	//appl1.showmenu();
	a2 + a1;
	a1 + 10;
	cout << 10 + a1 << endl;
	return 0;
}

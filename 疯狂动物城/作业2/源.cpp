#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class hire {
public:
	hire (char c) :character(c) {};//���캯��
	void menu();//��ʼ�˵�
	void showmenu();//ѡ�����˵�
	void minimenu();//ѡ���Ӳ˵�
	void choose(hire& h);
	double fox();//����fox�÷�
	double bunny();
	double sloth();
	void operator +(hire& h1);//����+�������
	double hirescore();//����÷�
	void ischoose();//�ж��Ƿ�ϸ�
	void display();//չʾ����
private:
	double agility, strength, speed;
	char character;
};
void hire::operator +(hire& h1){//����+�������
	if ((character == 'l' && h1.character == 'l'))
		cout << "���ź������ǲ������" << endl;
	else if ((character == 'm' && h1.character == 'm'))
		cout << "�������ǿ������" << endl;
	else
		cout << "��ϲ�������������" << endl;
}
void hire::menu() {//��ʼ�˵�
	agility = strength = speed = 0;
	cout << "================" << endl;
	cout << "===1.fox  ======" << endl;
	cout << "===2.bunny======" << endl;
	cout << "===3.sloth======" << endl;
	cout << "===4.�˳�ϵͳ===" << endl;
	cout << "================" << endl;
}
double hire::fox() {//����fox�÷�
	agility = strength = speed = 0;
	cout << "Enter agility " << endl;
	cin >> agility;
	cout << " Enter strength" << endl;
	cin >> strength;
	cout << "Hire score:" << hirescore() << endl;
	return hirescore();
}
double hire::bunny() {//����bunny�÷�
	agility = strength = speed = 0;
	cout << "Enter agility " << endl;
	cin >> agility;
	cout << " Enter speed" << endl;
	cin >> speed;
	cout << "Hire score:" << hirescore() << endl;
	return hirescore();
}
double hire::sloth() {//����sloth�÷�
	agility = strength = speed = 0;
	cout << "Enter strength " << endl;
	cin >> strength;
	cout << " Enter speed" << endl;
	cin >> speed;
	cout << "Hire score:" << hirescore() << endl;
	return hirescore();
}
void hire::ischoose() {//�жϵ÷��Ƿ�ϸ�
	double ret = hirescore();
	if (ret > 31.3) {
		cout << "��ϲ���㱻¼����" << endl;
		minimenu();//�ϸ�����ת�Ӳ˵�
	}
	else {//���ϸ����˳�����
		cout << "���ź�����û�б�¼ȡ" << endl;
	}
}
void hire::showmenu() {//���˵�
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
			ischoose();
			double ret = hirescore();
			if (ret > 31.3) {
				cout << "��ϲ���㱻¼����" << endl;
				minimenu();//�ϸ�����ת�Ӳ˵�
			}
			else {//���ϸ����˳�����
				cout << "���ź�����û�б�¼ȡ" << endl;
			}
			flag = 0;
			break;
		case'2'://ѡ��bunny
			bunny();
			display();
			ischoose();
			flag = 0;
			break;
		case'3'://ѡ��sloth
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
			std::cout << "�������" << endl;
			break;
		}
	}

}
void hire::minimenu() {//�Ӳ˵�
	int flag = 1;
	cout<<"����������Ը�l��m��h��: "<<endl;
	cin >> character;//�����Ը�
	hire fox('l'), bunny('l'), sloth('l');//��ʼ��
	while (flag) {
		cout << "��ѡ��" << endl;
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
			std::cout << "�������" << endl;
			break;
		}
	}
}
void hire::choose(hire& h) {
	cout<<"���������Ը�l,m,h):"<<endl;
	cin>>h.character;//���ǳ�ʼ�Ը�
	(*this) + h;//�����Ը��븲�Ǻ��Ը����+������
}
double hire::hirescore() {//����÷�
	return 1.0 * agility + 2.16 * strength + 3.24 * speed;
}
void hire::display() {//չʾ����
	cout << "agility is " << agility << "," << "strength is " << strength << "," << "speed is " << speed << endl;
}
int main() {
	hire appl1('l');
	appl1.showmenu();
	return 0;
}
#include<iostream>
using namespace std;
class AstractDrinking {
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	// ���븨��
	virtual void PutSomething() = 0;
	//��������
	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};
//��������
class coffe :public AstractDrinking {
public:
	virtual void Boil() {
		cout << "��ˮ" << endl;
	}
	
	virtual void Brew() {
		cout << "���ݿ���" << endl;
	}
	
	virtual void PourInCup() {
		cout << "���뱭��" << endl;
	}
	
	virtual void PutSomething() {
		cout << "�����ǻ�ţ��" << endl;
	}
};
//������
class tea :public AstractDrinking {
public:
	virtual void Boil() {
		cout << "��ˮ" << endl;
	}

	virtual void Brew() {
		cout << "���ݲ�" << endl;
	}

	virtual void PourInCup() {
		cout << "���뱭��" << endl;
	}

	virtual void PutSomething() {
		cout << "�������" << endl;
	}
};
//����
void doWork(AstractDrinking* abc) {
	abc->makeDrink();
}
void test() {
	cout << "��ѡ������Ҫ������" << endl;
	cout << "1.����" << endl;
	cout << "2.��" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		switch (select) {
		case 1:
			doWork(new coffe);
			break;
		case 2:
			doWork(new tea);
			break;
		default:
			std::cout << "�˳�" << endl;
			break;
		}
		system("pause");
	}
}
int main() {
	test();
	system("pause");
	return 0;
}
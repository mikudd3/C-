#include<iostream>
using namespace std;
//����
class AbstractCalculator {
public:
	virtual int getResult() {
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//�ӷ�
class AddCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 + m_Num2;
	}
};
//����
class SubCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 - m_Num2;
	}
};
//�˷�
class MuiCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 * m_Num2;
	}
};
//����
class DivCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 / m_Num2;
	}
};
int main() {
	int flag = 1;
	while (flag) {
		cout << "��ѡ������Ҫ���е����㣺" << endl;
		cout << "1.�ӷ�" << endl;
		cout << "2.����" << endl;
		cout << "3.�˷�" << endl;
		cout << "4.����" << endl;
		int num1 = 0;
		int num2 = 0;
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:
		{
			AbstractCalculator* abc = new AddCalculator;
			cout << "������num1" << endl;
			cin >> num1;
			abc->m_Num1 = num1;
			cout << "������num2" << endl;
			cin >> num2;
			abc->m_Num2 = num2;
			cout << abc->m_Num1 << "  +  " << abc->m_Num2 << "  =  " << abc->getResult() << endl;
			delete abc;
			break;
		}
		case 2:
		{
			AbstractCalculator* abc = new SubCalculator;
			cout << "������num1" << endl;
			cin >> num1;
			abc->m_Num1 = num1;
			cout << "������num2" << endl;
			cin >> num2;
			abc->m_Num2 = num2;
			cout << abc->m_Num1 << "  -  " << abc->m_Num2 << "  =  " << abc->getResult() << endl;
			delete abc;
			break;
		}
		case 3:
		{
			AbstractCalculator* abc = new MuiCalculator;
			cout << "������num1" << endl;
			cin >> num1;
			abc->m_Num1 = num1;
			cout << "������num2" << endl;
			cin >> num2;
			abc->m_Num2 = num2;
			cout << abc->m_Num1 << "  *  " << abc->m_Num2 << "  =  " << abc->getResult() << endl;
			delete abc;
			break;
		}
		case 4:
		{
			AbstractCalculator* abc = new DivCalculator;
			cout << "������num1" << endl;
			cin >> num1;
			abc->m_Num1 = num1;
			cout << "������num2" << endl;
			cin >> num2;
			abc->m_Num2 = num2;
			cout << abc->m_Num1 << "  /  " << abc->m_Num2 << "  =  " << abc->getResult() << endl;
			delete abc;
			break;
		}
		default:
			std::cout << "�˳�" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
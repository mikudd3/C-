#include<iostream>
using namespace std;
//基类
class AbstractCalculator {
public:
	virtual int getResult() {
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//加法
class AddCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 + m_Num2;
	}
};
//减法
class SubCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 - m_Num2;
	}
};
//乘法
class MuiCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 * m_Num2;
	}
};
//除法
class DivCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 / m_Num2;
	}
};
int main() {
	int flag = 1;
	while (flag) {
		cout << "请选择你想要进行的运算：" << endl;
		cout << "1.加法" << endl;
		cout << "2.减法" << endl;
		cout << "3.乘法" << endl;
		cout << "4.除法" << endl;
		int num1 = 0;
		int num2 = 0;
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:
		{
			AbstractCalculator* abc = new AddCalculator;
			cout << "请输入num1" << endl;
			cin >> num1;
			abc->m_Num1 = num1;
			cout << "请输入num2" << endl;
			cin >> num2;
			abc->m_Num2 = num2;
			cout << abc->m_Num1 << "  +  " << abc->m_Num2 << "  =  " << abc->getResult() << endl;
			delete abc;
			break;
		}
		case 2:
		{
			AbstractCalculator* abc = new SubCalculator;
			cout << "请输入num1" << endl;
			cin >> num1;
			abc->m_Num1 = num1;
			cout << "请输入num2" << endl;
			cin >> num2;
			abc->m_Num2 = num2;
			cout << abc->m_Num1 << "  -  " << abc->m_Num2 << "  =  " << abc->getResult() << endl;
			delete abc;
			break;
		}
		case 3:
		{
			AbstractCalculator* abc = new MuiCalculator;
			cout << "请输入num1" << endl;
			cin >> num1;
			abc->m_Num1 = num1;
			cout << "请输入num2" << endl;
			cin >> num2;
			abc->m_Num2 = num2;
			cout << abc->m_Num1 << "  *  " << abc->m_Num2 << "  =  " << abc->getResult() << endl;
			delete abc;
			break;
		}
		case 4:
		{
			AbstractCalculator* abc = new DivCalculator;
			cout << "请输入num1" << endl;
			cin >> num1;
			abc->m_Num1 = num1;
			cout << "请输入num2" << endl;
			cin >> num2;
			abc->m_Num2 = num2;
			cout << abc->m_Num1 << "  /  " << abc->m_Num2 << "  =  " << abc->getResult() << endl;
			delete abc;
			break;
		}
		default:
			std::cout << "退出" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
#include<iostream>
using namespace std;
class AstractDrinking {
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	// 加入辅料
	virtual void PutSomething() = 0;
	//制作饮料
	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};
//制作咖啡
class coffe :public AstractDrinking {
public:
	virtual void Boil() {
		cout << "煮水" << endl;
	}
	
	virtual void Brew() {
		cout << "冲泡咖啡" << endl;
	}
	
	virtual void PourInCup() {
		cout << "倒入杯中" << endl;
	}
	
	virtual void PutSomething() {
		cout << "加入糖或牛奶" << endl;
	}
};
//制作茶
class tea :public AstractDrinking {
public:
	virtual void Boil() {
		cout << "煮水" << endl;
	}

	virtual void Brew() {
		cout << "冲泡茶" << endl;
	}

	virtual void PourInCup() {
		cout << "倒入杯中" << endl;
	}

	virtual void PutSomething() {
		cout << "加入枸杞" << endl;
	}
};
//制作
void doWork(AstractDrinking* abc) {
	abc->makeDrink();
}
void test() {
	cout << "请选择你需要的饮料" << endl;
	cout << "1.咖啡" << endl;
	cout << "2.茶" << endl;
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
			std::cout << "退出" << endl;
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
#include<iostream>
using namespace std;
class cpu {
public:
	virtual void caculate() = 0;
};
class videocard {
public:
	virtual void display() = 0;
};
class Memory {
public:
	virtual void storage() = 0;
};
class computer {
public:
	computer(cpu* cp, videocard* vc, Memory* mm) {
		m_cp = cp;
		m_vc = vc;
		m_mm = mm;
	}
	void work() {
		m_cp->caculate();
		m_vc->display();
		m_mm->storage();
	}
	~computer() {
		if (m_cp != NULL) {
			delete m_cp;
			m_cp = NULL;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mm != NULL) {
			delete m_mm;
			m_mm = NULL;
		}
	}
private:
	cpu* m_cp;
	videocard* m_vc;
	Memory* m_mm;
};
class intelcpu :public cpu {
	virtual void caculate() {
		cout << " intelcpu " << endl;
	}
};
class intelvideocard :public videocard {
	virtual void display() {
		cout << " intelvideocard " << endl;
	}
};
class intelMemory :public Memory {
	virtual void storage() {
		cout << " intelMemory " << endl;
	}
};
class lenovocpu :public cpu {
	virtual void caculate() {
		cout << " lenovocpu " << endl;
	}
};
class lenovovideocard :public videocard {
	virtual void display() {
		cout << " lenovovideocard " << endl;
	}
};
class lenovoMemory :public Memory {
	virtual void storage() {
		cout << " lenovoMemory " << endl;
	}
};
void test() {
	cpu* intelcpu1 = new intelcpu;
	videocard* intelvideocard1 = new intelvideocard;
	Memory* intelMemory1 = new intelMemory;
	computer* intelcomputer1 = new computer(intelcpu1, intelvideocard1, intelMemory1);
	intelcomputer1->work();
	delete intelcomputer1;
}
int main() {
	test();
	system("pause");
	return 0;
}
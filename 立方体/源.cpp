#include<iostream>
using namespace std;
class cube {
public:
	void setl(int l) { ml = l; }
	void setw(int w) { mw = w; }
	void seth(int h) { mh = h; }
	int getl() { return ml; }
	int getw() { return mw; }
	int geth() { return mh; }
	int area() { return 2 * ml * mw + 2 * ml * mh + 2 * mw * mh; }
	int volume() { return ml * mh * mw; }
	bool issame(cube &c){ 
		if (ml == c.getl() && mw == c.getw() && mh == c.geth()) return true;
		return false;
	}
private:
	int ml;//长
	int mw;//宽
	int mh;//高
};
int main() {
	cube c1;
	c1.setl(10);
	c1.setw(10);
	c1.seth(10);
	cout << c1.area() << endl;
	cout << c1.volume() << endl;
	cube c2;
	c2.setl(11);
	c2.setw(11);
	c2.seth(11);
	cout << c2.area() << endl;
	cout << c2.volume() << endl;
	bool ret = c1.issame(c2);
	if (ret == true) cout << "两个立方体相等" << endl;
	else cout << "两个立方体不相等" << endl;
	return 0;
}
#include<iostream>
using namespace std;
#include"maarray.hpp"
void test01() {
	maarray <int>arr1(5);
	for (int i = 0; i < 5; i++) {
		arr1.push_back(i);
	}
}
int main() {
	test01();
	return 0;
}
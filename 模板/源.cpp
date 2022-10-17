#include<iostream>
using namespace std;

template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}//交换模板
template<typename T>
void mySort(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[max] < arr[j])
				max = j;//更新最大值下标
		}
		if (max != i) {
			mySwap(arr[max], arr[i]);//交换最大值
		}
	}
}//选择排序
template<typename T>
void printarr(T arr[], int len) {
	for (int i = 0; i < len; i++){ 
		cout << arr[i] << " "; 
	}
	cout << endl;
}
int main() {
	//字符
	char chararr[] = "fbcghjade";
	int num1 = sizeof(chararr) / sizeof(char);
	mySort(chararr, num1);
	printarr(chararr, num1);

	//数字
	int intarr[] = { 1,5,6,8,10,9,3,4,7,2 };
	int num2 = sizeof(intarr)/sizeof(int);
	mySort(intarr, num2);
	printarr(intarr, num2);
	return 0;
}
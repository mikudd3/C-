#include<iostream>
#include<string>
using namespace std;
struct hero {
	string name;
	int age;
	string sex;

};
void bubbleSort(struct hero heroarray[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (heroarray[j].age > heroarray[j + 1].age) {
				struct hero temp = heroarray[j];
				heroarray[j] = heroarray[j + 1];
				heroarray[j + 1] = temp;
			}
		}
	}
}
void printInfo(struct hero heroarray[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "Ó¢ÐÛÐÕÃû£º" << heroarray[i].name << "ÄêÁä£º" << heroarray[i].age
			<< "ÐÔ±ð£º" << heroarray[i].sex << endl;
	}
}
int main() {
	struct hero heroarray[5] = {
		{"Áõ±¸",23,"ÄÐ"},
		{"¹ØÓð",22,"ÄÐ"},
		{"ÕÅ·É",20,"ÄÐ"},
		{"ÕÔÔÆ",21,"ÄÐ"},
		{"õõ²õ",19,"Å®"},
	};
	int len = sizeof(heroarray) / sizeof(heroarray[0]);
	bubbleSort(heroarray, len);
	printInfo(heroarray, len);
	return 0;
}
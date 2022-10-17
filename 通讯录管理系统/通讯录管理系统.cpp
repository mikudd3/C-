#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
void showMenu() {//菜单
	cout << "*************************" << endl;
	cout << "*****  1.添加联系人 *****" << endl;
	cout << "*****  2.显示联系人 *****" << endl;
	cout << "*****  3.删除联系人 *****" << endl;
	cout << "*****  4.查找联系人 *****" << endl;
	cout << "*****  5.修改联系人 *****" << endl;
	cout << "*****  6.清空联系人 *****" << endl;
	cout << "*****  0.退出系统   *****" << endl;
	cout << "*************************" << endl;
}
struct Person {
	string m_Name;//姓名
	int m_Sex;//性别，1.男，2.女
	int m_Age;//年龄
	string m_Phone;//电话号码
	string m_Addr;//地址
};
struct Addresbooks {
	struct Person personArray[MAX];//通讯录中最大人员个数
	int m_size;//通讯录中人员个数
};
void addPerson(Addresbooks* abs) {//1.添加联系人
	if (abs->m_size == MAX) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;
		//电话
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;
		//家庭住址
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_Addr = address;
		//更新通讯录人数
		abs->m_size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏
	}
}
void showPerson(Addresbooks* abs) {//2.显示联系人
	if (abs->m_size == 0) cout << "当前记录为空" << endl;
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name <<"	";
			if (abs->personArray[i].m_Sex == 1)
				cout << "性别：" << "男" <<"	";
			else
				cout << "性别：" << "女" <<"	";
			cout << "年龄：" << abs->personArray[i].m_Age <<"	";
			cout << "电话：" << abs->personArray[i].m_Phone <<"	";
			cout << "家庭住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");//清屏
}
int isExist(Addresbooks* abs,string name) {//判断人是否存在
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_Name == name) return i;
	}
	return -1;
}
void deletePerson(Addresbooks* abs) {//3.删除联系人
	cout << "请输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	else cout << "查无此人" << endl;
	system("pause");
	system("cls");//清屏
}
void findPerson(Addresbooks* abs){//4.查找联系人
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名：" << abs->personArray[ret].m_Name <<"	";
		cout << "性别：" << abs->personArray[ret].m_Sex <<"    ";
		cout << "年龄：" << abs->personArray[ret].m_Age <<"    ";
		cout << "电话：" << abs->personArray[ret].m_Phone <<"    ";
		cout << "家庭住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else cout << "查无此人" << endl;
	system("pause");
	system("cls");//清屏
}
void modifyPerson(Addresbooks* abs) {//5.修改联系人
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "请输入你要修改的东西" << endl;
		cout << "1.----修改姓名" << endl;
		cout << "2.----修改性别" << endl;
		cout << "3.----修改年龄" << endl;
		cout << "4.----修改电话" << endl;
		cout << "5.----修改家庭住址" << endl;
		cout << "0.----不修改" << endl;
		int cnt = 0;
		cin >> cnt;
		switch (cnt) {
		case 1:
		{
			string name1;
			cout << "请输入姓名：" << endl;
			cin >> name1;
			abs->personArray[ret].m_Name = name1;
			break;
		}
		case 2: 
		{
			//性别
			cout << "请输入性别：" << endl;
			cout << "1---男" << endl;
			cout << "2---女" << endl;
			int sex1 = 0;
			while (true) {
				cin >> sex1;
				if (sex1 == 1 || sex1 == 2) {
					abs->personArray[ret].m_Sex = sex1;
					break;
				}
				cout << "输入错误，请重新输入" << endl;
			}
			break;
		}
		case 3: 
		{
			//年龄
			cout << "请输入年龄" << endl;
			int age1 = 0;
			cin >> age1;
			abs->personArray[ret].m_Age = age1;
			break;
		}
		case 4:
		{
			//电话
			cout << "请输入电话" << endl;
			string phone1;
			cin >> phone1;
			abs->personArray[ret].m_Phone = phone1;
			break;
		}
		case 5:
		{
			//家庭住址
			cout << "请输入家庭住址" << endl;
			string address1;
			cin >> address1;
			abs->personArray[ret].m_Addr = address1;
			break;
		}
		case 0:
			cout << "已退出" << endl;
			break;
		default:
			break;
		}
	}
	else cout << "查无此人" << endl;
	system("pause");
	system("cls");//清屏
}
void CleanPerson(Addresbooks* abs) {//6.删除通讯录
	int ret = 0;
	cout << "是否真的清空通讯录" << endl;
	cout << "1----是" << endl;
	cout << "2---否" << endl;
	cin >> ret;
	if (ret == 1) {
		abs->m_size = 0;
		cout << "通讯录已删除" << endl;
	}
	system("pause");
	system("cls");//清屏
}
int main() {
	Addresbooks abs; //创建通讯录结构体变量
	abs.m_size = 0;//初始化当前通讯录中人员个数
	int select = 0;
	while (true) {
		showMenu();//菜单调用
		cin >> select;
		switch (select) {
		case 1:// 1.添加联系人
			addPerson(&abs);//利用地址传递，可以修改形参
			break;
		case 2://2.显示联系人
			showPerson(&abs);
			break;
		case 3://3.删除联系人
			deletePerson(&abs);
			break;
		case 4://4.查找联系人 
			findPerson(&abs);
			break;
		case 5://5.修改联系人
			modifyPerson(&abs);
			break;
		case 6://6.清空联系人
			CleanPerson(&abs);
			break;
		case 0://0.退出系统
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

	}
	system("pause");
	return 0;
}
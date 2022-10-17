#include"workermanager.h"
workermanager:: workermanager() {//构造函数
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		//cout << "文件不存在" << endl;
		this->m_empNum = 0;//初始化人数
		this->m_empArray = NULL;//初始化数组
		this->m_FileIsEmpty = true;
		ifs.close();
		return ;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()){//文件存在，但没有记录
		//cout << "文件为空" << endl;
		this->m_empNum = 0;//初始化人数
		this->m_empArray = NULL;//初始化数组
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，并且记录数据
	int num = this->get_EmpNum();
	//cout << "职工人数为：" << num << endl;
	this->m_empNum = num;

	this->m_empArray = new worker * [this->m_empNum];//开辟空间
	this->init_Emp();//将文件中的数据，存到数组中
	/*for (int i = 0; i < this->m_empNum; i++) {
		cout << " 职工编号：" << this->m_empArray[i]->m_id
			<< " 姓名：" << this->m_empArray[i]->m_Name
			<< " 部门编号：" << this->m_empArray[i]->m_Deptid << endl;
	}*/
}
void workermanager::show_menu() {
	cout << "******************************************" << endl;
	cout << "********** 欢迎使用职工管理系统 **********" << endl;
	cout << "************** 0.退出管理系统 ************" << endl;
	cout << "************** 1.增加职工信息 ************" << endl;
	cout << "************** 2.显示职工信息 ************" << endl;
	cout << "************** 3.删除职工信息 ************" << endl;
	cout << "************** 4.修改职工信息 ************" << endl;
	cout << "************** 5.查找职工信息 ************" << endl;
	cout << "************** 6.按照编号排序 ************" << endl;
	cout << "************** 7.清空所有文档 ************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}
void workermanager::exitSystem() {
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}
void workermanager::Add_emp() {//增加员工
	cout << "请输入增加职工数量：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		int newsize = this->m_empNum + addNum;//计算新空间大小
		worker** newSpace = new worker * [newsize];//开辟新空间
		if (this->m_empArray != NULL) {//将原空间内容存放到新空间
			for (int i = 0; i < this->m_empNum; i++) {
				newSpace[i] = this->m_empArray[i];
			}
		}
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "请输入" << i + 1 << "个职工编号" << endl;
			cin >> id;
			cout << "请输入" << i + 1 << "个职工姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			worker* worker = NULL;
			switch (dSelect) {
			case 1://普通员工
				worker = new employee(id, name, 1);
				break;
			case 2://经理
				worker = new manager(id, name, 2);
				break;
			case 3://老板
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_empNum + i] = worker;
		}
		delete[] this->m_empArray;//释放原有空间
		this->m_empArray = newSpace;

		this->m_empNum = newsize;//更新个数
		this->m_FileIsEmpty = false;//更新职工不为空标记
		this->save();
		cout << "成功添加" << addNum << "名新职工" << endl;
	}
	else {
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}
void workermanager::show_emp(){//显示职工信息
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		for (int i = 0; i < m_empNum; i++) {
			this->m_empArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
int workermanager::IsExist(int id) {//判断该职工是否存在
	int index = -1;
	for (int i = 0; i < m_empNum; i++) {
		if (this->m_empArray[i]->m_id = id) {
			index = i;
			break;
		}
	}
	return index;
}
void workermanager::delete_emp() {//删除职工信息
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入职工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);//判断该职工是否存在
		if (index != -1) {
			for (int i = 0; i < this->m_empNum - 1; i++) {
				this->m_empArray[i] = this->m_empArray[i + 1];
			}
			this->m_empNum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "删除失败，未找到该员工" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workermanager::mod_emp() {//修改职工信息
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入想要修改的员工编号" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {
			cout << "请输入想要修改的内容：" << endl;
			cout << "1.编号" << endl;
			cout << "2.姓名" << endl;
			cout << "3.部门编号" << endl;
			int newid = 0;
			string newname = "";
			int newdid = 0;
			int select = 0;
			cin >> select;
			switch (select) {
				case 1:
					cout << "请输入修改后的编号：" << endl;
					cin >> newid;
					this->m_empArray[index]->m_id = newid;
					break;
				case 2:
					cout << "请输入修改后的姓名：" << endl;
					cin >> newname;
					this->m_empArray[index]->m_Name = newname;
					break;
				case 3:
					cout << "请输入修改后的部门编号：" << endl;
					cin >> newdid;
					this->m_empArray[index]->m_Deptid = newdid;
					break;
				default:
					break;
			}
			this->save();
			cout << "修改成功" << endl;
		}
		else {
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workermanager::find_emp() {//查找职工信息
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入查找的方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			int id;
			cout << "请输入想要查找的职工编号" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1) {
				cout << "查找成功" << endl;
				this->m_empArray[ret]->showInfo();
			}
			else {
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2) {
			string name;
			cout << "请输入想要查找的人的姓名" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_empNum; i++) {
				if (m_empArray[i]->m_Name == name) {
					cout << "查找成功，职工编号为;"
						<< m_empArray[i]->m_id
						<< "号的信息如下：" << endl;
					flag = true;
					this->m_empArray[i]->showInfo();
				}
			}
			if (flag == false) {
				cout << "查找失败，查无此人" << endl;
			}
		}
		else {
			cout << "输入选项错误" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workermanager::sort_emp() {//按照编号排序
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工号进行升序" << endl;
		cout << "2.按职工号进行降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_empNum; i++) {
			int minOrmax = i;
			for (int j = i + 1; j < m_empNum; j++) {
				if (select == 1) {//升序
					if (this->m_empArray[minOrmax]->m_id > this->m_empArray[j]->m_id) {
						minOrmax = j;
					}
				}
				else {//降序
					if (this->m_empArray[minOrmax]->m_id < this->m_empArray[j]->m_id) {
						minOrmax = j;
					}
				}
			}
			if (i != minOrmax) {
				worker* temp = m_empArray[i];
				m_empArray[i] = m_empArray[minOrmax];
				m_empArray[minOrmax] = temp;
			}
		}
		cout << "排序成功，排序后结果为：" << endl;
		this->save();
		this->show_emp();
	}
}
void workermanager::clean_file() {//清空所有文档
	cout << "确定清空：" << endl;
	cout << "1.yes" << endl;
	cout << "2.no" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_empArray != NULL) {
			for (int i = 0; i < this->m_empNum; i++) {
				if (this->m_empArray[i] != NULL) {
					delete this->m_empArray[i];
				}
			}
			this->m_empNum = 0;
			delete[] this->m_empArray;
			this->m_empArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
void workermanager::save() {//保存文件
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_empNum; i++) {
		ofs << this->m_empArray[i]->m_id << " "
			<< this->m_empArray[i]->m_Name << " "
			<< this->m_empArray[i]->m_Deptid << endl;
	}
	//关闭文件
	ofs.close();
}
int workermanager::get_EmpNum(){//统计人数
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		num++;
	}
	ifs.close();
	return num;
}
void workermanager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		worker* worker = NULL;
		if (did == 1) {
			worker = new employee(id, name, did);
		}
		else if (did == 2) {
			worker = new manager(id, name, did);
		}
		else {
			worker = new boss(id, name, did);
		}
		this->m_empArray[index] = worker;
		index++;
	}
	ifs.close();
}
workermanager::~workermanager() {//析构函数
	if (this->m_empArray != NULL) {
		delete[] this->m_empArray;
		this->m_empArray = NULL;
	}
}
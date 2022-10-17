#include "speechmanager.h"
//构造函数
speechmanager::speechmanager() {
	//初始化属性
	this->initspeech();
	//创建选手
	this->createspeaker();
	//读取记录
	this->loadrecord();
}
//菜单功能
void speechmanager::show_menu() {
	cout << "********************************************" << endl;
	cout << "************* 欢迎参加演讲比赛 *************" << endl;
	cout << "************* 1.开始演讲比赛   *************" << endl;
	cout << "************* 2.查看往届记录   *************" << endl;
	cout << "************* 3.清空比赛记录   *************" << endl;
	cout << "************* 0.退出比赛程序   *************" << endl;
	cout << "********************************************" << endl;

}
//初始化属性
void speechmanager::initspeech() {
	//容器保证为空
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_speaker.clear();
	this->m_index = 1;
	this->m_record.clear();
}
//创建选手
void speechmanager:: createspeaker() {
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameseed.size(); i++) {
		string name = "选手";
		name += nameseed[i];
		speaker sp;
		sp.m_name = name;
		for (int i = 0; i < 2; i++) {
			sp.m_score[i] = 0;
		}
		//12名选手编号
		this->v1.push_back(i + 10001);
		//把选手编号以及对应的选手存放到map容器中
		this->m_speaker.insert(make_pair(i + 10001, sp));
	}
}
//开始比赛
void speechmanager::startspeech() {
	//第一轮比赛
	//1.抽签
	speechdraw();
	//2.比赛
	speechcontset();
	//3.显示晋级结果
	showscore();
	this->m_index++;
	//第二轮比赛

	//1.抽签
	speechdraw();
	//2.比赛
	speechcontset();
	//3.显示晋级结果
	showscore();
	//4.保存分数
	saverecord();
	//初始化属性
	this->initspeech();
	//创建选手
	this->createspeaker();
	//读取往届记录
	this->loadrecord();

	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");
}
//1.抽签
void speechmanager::speechdraw() {
	cout << "第" << this->m_index << "轮比赛选手正在抽签"<< endl;
	cout << "----------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	if (this->m_index == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "----------------------" << endl;
	system("pause");
}
//2.比赛
void speechmanager::speechcontset() {
	cout << "-------------" << this->m_index << "轮比赛正式开始：-------------" << endl;
	//临时容器，保存key分数 value选手编号
	multimap<double, int, greater<double>>groupscore;
	//记录人员个数 6个人为一小组
	int num = 0;
	//比赛人员容器
	vector<int>v_src;
	if (this->m_index == 1) {
		v_src = v1;
	}
	else {
		v_src = v2;
	}
	// 遍历所有参数选手
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++) {
		num++;
		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		// 排序从大到小
		//greater<double>内置函数对象，用来给容器进行降序排列
		sort(d.begin(), d.end(), greater<double>());
		//去掉最低分
		d.pop_back();
		//去掉最高分
		d.pop_front();
		//总分
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		//平均分
		double avg = sum / (double)d.size();
		//每个人平均分
		this->m_speaker[*it].m_score[this->m_index - 1] = avg;
		//6 个人一组，用临时容器保存
		groupscore.insert(make_pair(avg, *it));
		if (num % 6 == 0) {
			cout << "第" << num / 6 << "小组比赛名次；" << endl;
			//greater<double>内置函数对象，用来给容器进行降序排列
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end(); it++) {
				cout << "编号：" << it->second << "姓名：" << this->m_speaker[it->second].m_name
					<< "成绩：" << this->m_speaker[it->second].m_score[this->m_index - 1] << endl;
			}
			int count = 0;
			//取前三名
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end() && count < 3; it++, count++) {
				if (this->m_index == 1) {
					v2.push_back((*it).second);
				}
				else {
					victory.push_back((*it).second);
				}
			}
			groupscore.clear();
			cout << endl;
		}
	}
	cout << "--------------第" << this->m_index << "轮比赛结束 --------------" << endl;
	system("pause");
}
//3.显示晋级结果
void speechmanager::showscore() {
	cout << "--------------第" << this->m_index << "轮晋级结果如下：--------------" << endl;
	vector<int>v;
	if (this->m_index == 1) {
		v = v2;
	}
	else {
		v = victory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "选手编号：" << *it << "姓名：" << this->m_speaker[*it].m_name << "得分："
			<< this->m_speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_menu();
}
//保存记录
void speechmanager::saverecord() {
	ofstream ofs;
	//用输出的方式打开文件，写文件
	ofs.open("speech.csv", ios::out | ios::app);
	//将每个数据写入到文件中、
	for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++) {
		ofs << *it << "," << this->m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "文件已保存" << endl;
	this->fileisempty = false;
}
//读取记录
void speechmanager::loadrecord() {
	//输入流对象，读取文件
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open()) {
		this->fileisempty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->fileisempty = true;
		ifs.close();
		return;
	}
	//文件不为空
	this->fileisempty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	while (ifs >> data) {
		vector<string> v;
		int pos = -1;
		int start = 0;
		while (true) {
			pos = data.find(",", start);
			if (pos == -1) {
				break;
			}
			string tmp = data.substr(start, pos - start);
			v.push_back(tmp);
			start = pos + 1;
		}
		this->m_record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

}
//查看记录
void speechmanager::showrecord() {
	if (this->fileisempty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		for (int i = 0; i < this->m_record.size(); i++) {
			cout << "第" << i + 1 << "届结果："
				<< "冠军编号：" << this->m_record[i][0] << "得分：" << this->m_record[i][1] << " "
				<< "亚军编号：" << this->m_record[i][2] << "得分：" << this->m_record[i][3] << " "
				<< "季军编号：" << this->m_record[i][4] << "得分：" << this->m_record[i][5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}
//退出系统
void speechmanager::exitsystem() {
	cout << "欢迎下次使用！！" << endl;
	system("pause");
	exit(0);
}
//清空记录
void speechmanager::clearrecord() {
	cout << "确定清空" << endl;
	cout << "1.是" << endl;
	cout << "2,否" << endl;
	int select = 0;
	if (select == 1) {
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initspeech();
		this->createspeaker();
		this->loadrecord();
		cout << "清空成功" <<endl;
	}
	system("pause");
	system("cls");
}
//析构函数
speechmanager::~speechmanager() {

}
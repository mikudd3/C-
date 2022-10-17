//自己通用的数组类
#pragma once
#include<iostream>
using namespace std;
template<class T>
class maarray {
public:
	//有参构造
	maarray(int c) {
		this->m_capacity = c;
		this->m_size = 0;
		this->paddress = new T[this->m_capacity];
	}
	//拷贝构造函数
	maarray(const maarray& arr) {
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//深拷贝
		this->paddress = new T[arr.m_capacity];
		for (int i = 0; i < this.m_size; i++) {
			this->paddress[i] = arr.paddress[i];
		}
	}
	maarray& operator=(const maarray& arr) {
		if (this->paddress != NULL) {
			delete[]this->paddress;
			this->paddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//深拷贝
		this->paddress = new T[arr.m_capacity];
		for (int i = 0; i < this.m_size; i++) {
			this->paddress[i] = arr.paddress[i];
		}
		return *this;
	}
	//尾插法
	void push_back(const T& val) {
		//判断容量是否等于大小
		if (this->m_capacity == this->m_size) {
			return;
		}
		this->paddress[this->m_size] = val;
		this->m_size++;
	}
	//尾删法
	void pop_back() {
		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		if (this->m_size == 0) {
			return;
		}
		this->m_size--;
	}
	//通过下标方式访问数组中的元素
	T& operator[](int index) {
		return this->paddress[index];
	}
	//返回数组容量
	int getcapacity() {
		return this->m_capacity;
	}
	//返回容量大小
	int getsize() {
		return this->m_size;
	}


	//析构函数
	~maarray() {
		if (this->paddress != NULL) {
			delete[]this->paddress;
			this->paddress = NULL;
		}
	}

private:
	T* paddress;//指针指向堆区开辟的真实数组
	int m_capacity;//数组容量
	int m_size;//数组大小
};


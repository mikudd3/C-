//�Լ�ͨ�õ�������
#pragma once
#include<iostream>
using namespace std;
template<class T>
class maarray {
public:
	//�вι���
	maarray(int c) {
		this->m_capacity = c;
		this->m_size = 0;
		this->paddress = new T[this->m_capacity];
	}
	//�������캯��
	maarray(const maarray& arr) {
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//���
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
		//���
		this->paddress = new T[arr.m_capacity];
		for (int i = 0; i < this.m_size; i++) {
			this->paddress[i] = arr.paddress[i];
		}
		return *this;
	}
	//β�巨
	void push_back(const T& val) {
		//�ж������Ƿ���ڴ�С
		if (this->m_capacity == this->m_size) {
			return;
		}
		this->paddress[this->m_size] = val;
		this->m_size++;
	}
	//βɾ��
	void pop_back() {
		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼�ɾ��
		if (this->m_size == 0) {
			return;
		}
		this->m_size--;
	}
	//ͨ���±귽ʽ���������е�Ԫ��
	T& operator[](int index) {
		return this->paddress[index];
	}
	//������������
	int getcapacity() {
		return this->m_capacity;
	}
	//����������С
	int getsize() {
		return this->m_size;
	}


	//��������
	~maarray() {
		if (this->paddress != NULL) {
			delete[]this->paddress;
			this->paddress = NULL;
		}
	}

private:
	T* paddress;//ָ��ָ��������ٵ���ʵ����
	int m_capacity;//��������
	int m_size;//�����С
};


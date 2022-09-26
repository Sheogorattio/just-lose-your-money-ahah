#pragma once
#include <iostream>
using namespace std;
template<class T=int>
class queue
{
	T* arr;
	size_t maxLength;
	size_t currentLength;
public:
	queue(size_t size);
	~queue();
	void push(const T& val);
	void extract()const;
	bool isEmpty();
	bool isFull();
	void clear();
	T getVal();
	size_t getCount();
	void show();
	queue<T>& operator =( queue<T>&& obj);
};

template<class T>
queue<T>::queue(size_t size) {
	arr = new T[size];
	maxLength = size;
	currentLength = 0;
}

template<class T>
queue<T>::~queue() {
	delete[] arr;
}

template<class T>
void queue<T>::push(const T& val) {
	if (!isFull()) {
		arr[currentLength++] = val;
	}
}

template<class T>
void queue<T>::extract()const {
	T temp = arr[0];
	for (int i = 1; i < currentLength; i++) {
		arr[i - 1] = arr[i];
	}
	arr[currentLength - 1] = temp;
}

template<class T>
bool queue<T>::isEmpty() {
	return currentLength == 0;
}

template<class T>
bool queue<T>::isFull() {
	return currentLength == maxLength;
}

template<class T>
void queue<T>::clear() {
	currentLength = 0;
}

template<class T>
T queue<T>::getVal() {
	return arr[0];
}

template<class T>
size_t queue<T>::getCount() {
	return currentLength;
}

template<class T>
void queue<T>::show() {
	for (int i = 0; i < currentLength; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
queue<T>& queue<T>::operator=(queue<T>&& obj) {
	delete[] arr;
	arr = obj.arr;
	obj.arr = nullptr;
	maxLength = obj.maxLength;
	currentLength = obj.currentLength;
	obj.~queue();
	return *this;
}
#include <iostream>
#include<Windows.h>
#include "queue.h"
#include<ctime>
using namespace std;

template<class T>
void initObj(queue<T>& obj, const size_t size) {
	for (int i = 0; i < size; i++) {
		obj.push(i);
	}
}

template<class T>
void rotate(queue<T>& obj) {
	int temp = rand() % 8 + 3;
	for (int i = 0; i < temp; i++) {
		cout << obj.getVal();
		obj.extract();
		Sleep(50);
		cout << "\b";
	}
	cout << obj.getVal();
	cout << " ";
	Sleep(200);
}


int main() {
	srand(time(NULL));
	const size_t size = 7;
	queue<>obj1(size);
	queue<>obj2(size);
	queue<>obj3(size);
	initObj(obj1, size);
	initObj(obj2, size);
	initObj(obj3, size);
	char exit='\n';
	while (exit == '\n') {
		rotate(obj1);
		rotate(obj2);
		rotate(obj3);
		cout << '\n';
		Sleep(500);
		if (obj1.getVal() == obj2.getVal() && obj1.getVal()  == obj3.getVal()) {
			if (obj1.getVal() == 7) {
				cout << "you won a perfect void!!!!!\ncongratulations!!!!!!!!!"; 
			}
			else {
				cout << "ok, you won. meh\n"; 
			}
		}
		else { cout << "loser\n"; }
		exit = getchar();
		system("cls");
	}
}
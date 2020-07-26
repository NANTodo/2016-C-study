#include <iostream>
using namespace std;

#include "Container.h"

Container::Container(char* name, int initialSize) {
	this->name = name;
	size = initialSize;
}

bool Container::consume(int n) { // 통에서 n 분만큼 재료 소모
	if(size < n) return false;
	size -= n;
	return true;
}

void Container::show() { // 통에 현재 남은 재료 량을 '*'로 출력
	cout << name + "\t";
	for(int i=0; i<size; i++)
		cout << "*";
	cout << endl;
}
#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <cstdlib>
using namespace std;

#include "define.h"

class Container { // 통을 표현하는 클래스
	string name;
	int size; // 통의 크기
public:
	Container(char* name="", int initialSize=MAXSIZE);
	bool consume(int n=1); // 재료 소비
	void fill() { size = MAXSIZE; } // 재료 채우기
	int getSize() { return size; } // 현재 남은 재료의 량 리턴
	bool isEmpty() { 	return size==0?true:false; }
	bool isFull() { return size==MAXSIZE?true:false; }
	void put() { size++; } // 재료 량 1 증가
	void setName(string name) { this->name = name; }
	void show(); // 통의 상황 출력
};

#endif
#include <iostream>
#include <string>
using namespace std;

#include "define.h"
#include "Engine.h"
#include "VendingMachine.h"

VendingMachine::VendingMachine(string name) {
	this->name = name;
	con = new Container[6]; // 통 생성
	con[COFFEE].setName("Coffee");
	con[KOKOA].setName("Kokoa");
	con[SUGAR].setName("Sugar");
	con[CREAM].setName("Cream");
	con[WATER].setName("Water");
	con[CUP].setName("Cup");
	engine = new Engine(con); // 엔진 생성
}

VendingMachine::~VendingMachine() {
	delete engine; // 엔진 소멸
	delete [] con; // 생성한 모든 통 객체 소멸
}

void VendingMachine::powerOn() { // 자판기가 켜질 때를 시뮬레이션하는 함수
	cout << "------" << name << "켭니다.------" << endl;
	engine->run(); // 엔진 시작 시킴
}
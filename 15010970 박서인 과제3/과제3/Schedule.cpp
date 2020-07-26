#include <iostream>
using namespace std;

#include "Seat.h"
#include "Schedule.h"
#include "Console.h"

Schedule::Schedule() {
	seat = new Seat[8];
	time = "";
}

Schedule::~Schedule() {
	delete[] seat;
}

void Schedule::setTime(string time) {
	this->time = time;
}

void Schedule::view() {
	cout << time << ":";
	cout << endl;
	for (int i = 0; i < 8; i++) {
		cout << "\t";
			seat[i].view();
			cout << endl;
		}
}

void Schedule::book(int no, string name, int hydrates, int food) {	//예약함수, hydrates와 food 추가
	seat[no-1].book(name, hydrates, food);
}

void Schedule::fee(int hydrates, int food) {	//전체 추가요금 계산을 위한 함수 Console로 연결
	Console::fee(hydrates, food);
}

bool Schedule::booling(int no) {	//예약하거나 변경할경우 자리가 겹치는 경우를 구분하기위해 seat.h에 있던 bool함수 isBooked를 사용.
	if (seat[no - 1].isBooked() == true)
		return false;
	else
		return true;
}

void Schedule::cancel(int no, string name) {
	return seat[no - 1].cancel(name);
}
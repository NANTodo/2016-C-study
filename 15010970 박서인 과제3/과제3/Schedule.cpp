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

void Schedule::book(int no, string name, int hydrates, int food) {	//�����Լ�, hydrates�� food �߰�
	seat[no-1].book(name, hydrates, food);
}

void Schedule::fee(int hydrates, int food) {	//��ü �߰���� ����� ���� �Լ� Console�� ����
	Console::fee(hydrates, food);
}

bool Schedule::booling(int no) {	//�����ϰų� �����Ұ�� �ڸ��� ��ġ�� ��츦 �����ϱ����� seat.h�� �ִ� bool�Լ� isBooked�� ���.
	if (seat[no - 1].isBooked() == true)
		return false;
	else
		return true;
}

void Schedule::cancel(int no, string name) {
	return seat[no - 1].cancel(name);
}
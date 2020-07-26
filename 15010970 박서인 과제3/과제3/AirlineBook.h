#pragma once
#ifndef AIRLINEBOOK_H
#define AIRLINEBOOK_H

#include <string>
using namespace std;

class Schedule;

class AirlineBook {
	string name; // 예약 시스템 이름
	int nSchedules; // 스케쥴 개수
	int hydrates; //위탁수화물 갯수
	int food;
	int menu_choice;
	Schedule *sche; // 스케쥴 배열

	void book();
	void cancel();
	void view();
	void view(int s);
	void change();
public:
	AirlineBook(string name, int nSchedules, string scheduleTime[], int hydrates, int food);
	~AirlineBook();
	void run(); // 예약 시스템을 작동시키는 함수
};

#endif

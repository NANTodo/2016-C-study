#ifndef SCHEDULE_H
#define SCHEDULE_H

#include<string>
using namespace std;

class Seat;

class Schedule {
	string time; // 스케쥴 타임
	Seat* seat;
public:
	Schedule();
	~Schedule();
	bool booling(int no);
	void book(int no, string name, int hydrates, int food);
	void cancel(int no, string name);
	void view();
	void fee(int hydrates, int food);
	void setTime(string time);
};

#endif
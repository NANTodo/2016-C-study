#pragma once
#ifndef AIRLINEBOOK_H
#define AIRLINEBOOK_H

#include <string>
using namespace std;

class Schedule;

class AirlineBook {
	string name; // ���� �ý��� �̸�
	int nSchedules; // ������ ����
	int hydrates; //��Ź��ȭ�� ����
	int food;
	int menu_choice;
	Schedule *sche; // ������ �迭

	void book();
	void cancel();
	void view();
	void view(int s);
	void change();
public:
	AirlineBook(string name, int nSchedules, string scheduleTime[], int hydrates, int food);
	~AirlineBook();
	void run(); // ���� �ý����� �۵���Ű�� �Լ�
};

#endif

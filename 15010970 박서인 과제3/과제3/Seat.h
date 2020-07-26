#pragma once

#ifndef SEAT_H
#define SEAT_H

#include <string>
using namespace std;

class Seat {
	string name;
	int hydrates;
	int food;

public:
	Seat();
	void book(string name, int hydrates, int food);
	bool isBooked();
	void cancel(string name);
	void view();
};

#endif
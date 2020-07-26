#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H

#include<string>
using namespace std;

class Console {

public:
	static int getMainMenu();
	static int getScheduleMenu();
	static string getName();
	static int getSeatNo();
	static int hydrate();
	static int food();
	static void print(string);
	static void fee(int, int);
};

#endif
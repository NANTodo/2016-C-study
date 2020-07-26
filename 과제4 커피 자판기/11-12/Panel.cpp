#include <iostream>
using namespace std;

#include "define.h"
#include "Panel.h"

int Panel::getButton() {
	int menu;
	cout <<"보통 커피:"<< NORMAL_COFFEE << ", ";
	cout <<"설탕 커피:"<< SUGAR_COFFEE << ", ";
	cout <<"블랙 커피:"<< BLACK_COFFEE << ", ";
	cout << "핫 초코:" << HOT_KOKOA << ", ";
	cout <<"채우기:"<< FILL << ", ";
	cout << "종료:" << EXIT << ">> ";

	cin >> menu;
	return menu;
}
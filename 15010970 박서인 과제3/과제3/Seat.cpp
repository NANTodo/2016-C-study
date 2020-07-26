#include <iostream>
using namespace std;

#include "Seat.h"

Seat::Seat() {
	name = "";
}

// 예약
void Seat::book(string name, int hydrates, int food) {	//자리예약함수
	this->name = name;	//name파트에 입력받은 name들어감
	this->hydrates = hydrates;	//hydrates파트에 입력받은 hydrates(수화물수)들어감
	this->food = food;	//food파트에 입력받은 food(기내식 메뉴번호)들어감

}

// 예약 확인
bool Seat::isBooked() {
	if (name.size() == 0)	//name에 들어가는 값이 없으면 false
		return false;
	else
		return true;	//들어가는 값이 있으면 ture
}

// 예약 취소
void Seat::cancel(string name) {
	this->name = ""; // 이름 삭제
}

// 예약자 이름 출력
void Seat::view() {
	if (isBooked()) {
		if (food == 0) {	//기내식 메뉴를 선택하지 않았을 경우
			cout << name << " / " << hydrates << " / " << "신청안함" << "\t";
		}
		else		
			cout << name << " / " << hydrates << " / " << "메뉴" << food << "\t";	//기내식 메뉴 선택했을경우
	}
	else
		cout << "---" << " / " << "--" << " / " << "--" << "\t";	//어떤 입력도 들어가지 않았을 경우
}
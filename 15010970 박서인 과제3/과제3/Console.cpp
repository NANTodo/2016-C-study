#include <iostream>
using namespace std;
#include <string>
#include <cstring>

#include "Console.h"


int Console::getMainMenu() {	//mainmenu에 변경메뉴 추가
	cout << "예약:1, 취소:2, 현황:3, 변경:4, 끝내기:5 >>";
	int menu;
	cin >> menu;
	return menu;
}

int Console::getScheduleMenu() {	//19시 시간 추가
	cout << "7시:1, 12시:2, 17시:3, 19시:4 >>";
	int menu;
	cin >> menu;
	return menu;
}

string Console::getName() {
	cout << "이름 입력 >>";
	string name;
	cin >> name;
	return name;
}

int Console::getSeatNo() {
	cout << "좌석 번호 >> ";
	int no;
	cin >> no;
	if (no > 8) {
		cout << "좌석은 8번까지입니다" << endl;
		getSeatNo();
	}
	else
		return no;
}

int Console::hydrate() {	//hydrate(): 위탁수하물 갯수 입력 함수
	cout << "위탁수화물 수(최대 2개)" << endl;
	cout << "개당 20000KRW의 요금이 추가됩니다" << endl;
	cout << ">> ";
	int num;
	cin >> num;
	if ((-1 < num) && (num < 3)) {	//0~2 만의 입력을 받는다.
		return num;
	}
	else {	//그거 아니면 거부하고 재입력 요구.
		cout << "수화물은 최대 두 개까지만 위탁가능합니다" << endl;
		hydrate();
	}
}

int Console::food() {	//기내식 메뉴선택 함수
		cout << "\t기내식 메뉴를 선택해주세요" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "메뉴1 : 스테이크와 레드 와인 / 20000KRW" << endl;
		cout << "메뉴2 : 생선요리와 화이트 와인 / 15000KRW" << endl;
		cout << "메뉴3 : 꾸러기 도시락 / 20000KRW" << endl;
		cout << "메뉴4 : 저칼로리 도시락 / 20000KRW" << endl;
		cout << "===============================================" << endl;
		cout << ">> ";
		int menu_choice;
		cin >> menu_choice;
			switch (menu_choice) {
			case 1:	//메뉴1: 스테이크와 레드 와인
				cout << "20000KRW의 요금이 추가됩니다 " << endl;
				return menu_choice;
				break;
			case 2:	//메뉴2 : 생선요리와 화이트 와인
				cout << "15000KRW의 요금이 추가됩니다" << endl;
				return menu_choice;
				break;
			case 3:	//메뉴3 : 꾸러기 도시락
				cout << "20000KRW의 요금이 추가됩니다" << endl;
				return menu_choice;
			case 4:	//메뉴4 : 저칼로리 도시락
				cout << "20000KRW의 요금이 추가됩니다" << endl;
				return menu_choice;
				break;
			default:	//그 외의것 입력하는 경우
				cout << "잘못 입력하셨습니다" << endl;
			}
	}
void Console::fee(int hydrates, int food) {	//추가 요금들을 계산 하는 함수

	int menuprice[4] = { 20000, 15000, 20000, 20000 };	//기내식 메뉴 네가지의 가격
	int fee;
	if (food == 0) {	//기내식을 신청하지 않았을경우
		fee = hydrates * 20000;	//신청한 수하물 수x20000원으로 계산
	}
	else if (food < 5 && food>0) {	//기내식을 신청한 경우
		fee = (hydrates * 20000) + menuprice[food - 1];	//요금은 (신청한 수하물 수 x20000원) 더하기 선택한 기내식메뉴의 가격
	}
	cout << "최종 추가 요금은 " << fee << "KRW입니다" << endl;

}
void Console::print(string msg) {
	cout << msg;
}
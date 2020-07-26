#include <iostream>
#include <conio.h>
using namespace std;
#include <string>

#include "AirlineBook.h"
#include "Schedule.h"
#include "Console.h"
#include "Seat.h"


// 생성자
AirlineBook::AirlineBook(string name, int nSchedules, string scheduleTime[], int hydrates, int food) {
	this->name = name; // 이름
	this->nSchedules = nSchedules; // 스케쥴 개수
	this->hydrates = hydrates;
	this->food = food;	
	sche = new Schedule[nSchedules]; // 4 개의 스케쥴 객체 생성

									 // 각 스케쥴에 해당 시간 설정
	for (int i = 0; i < nSchedules; i++)
		sche[i].setTime(scheduleTime[i]);
}

// 소멸자
AirlineBook::~AirlineBook() {
	if (sche)
		delete[] sche;
}

// 예약 시스템을 시작하는 함수
void AirlineBook::run() {
	cout << "*** " << name << "에 오신것을 환영합니다." << " ***" << endl;
	cout << endl;

	while (true) {
		int menu = Console::getMainMenu(); // 메인 메뉴 입력
		switch (menu) {
		case 1:
			book(); // 예약
			break;
		case 2:
			cancel(); // 취소
			break;
		case 3:
			view(); // 예약 보기
			break;
		case 4:
			change();	//예약 변경
			break;
		case 5:
			cout << "예약 시스템을 종료합니다.\n" << endl;
			return;
		default:
			cout << "잘못입력하였습니다.\n" << endl;
			break;
		}
		cout << endl;
	}
}

// 스케쥴을 예약한다.
void AirlineBook::book() {
	int s, ask;
	string bookName;
	int seatNo, plusHydrate, meal;

	s = Console::getScheduleMenu(); // 사용자가 선택한 스케쥴을 입력 받는다.
	view(s); // 스케쥴 s의 예약 상황을 출력한다.
	seatNo = Console::getSeatNo(); // 좌석 번호를 입력받는다.
	if (sche[s - 1].booling(seatNo) == true) {	//입력한 좌석번호에 저장되어있는 정보가 없다면
		bookName = Console::getName(); // 예약자의 이름을 입력받는다.
		plusHydrate = Console::hydrate();	//위탁 수화물 갯수를 입력받는다
		cout << "기내식을 추가하시겠습니까?" << endl;	//기내식 추가여부 확인
		cout << "\t" << "Yes : 1     No : 2 " << endl;
		cin >> ask;
		switch (ask) {
		case 1:	//추가하는 경우
			meal = Console::food();
			break;
		case 2:	//추가 하지 않는 경우
			cout << "기내식을 추가하지 않습니다" << endl;
			meal = 0;
		}
		sche[s - 1].book(seatNo, bookName, plusHydrate, meal);// 해당 스케쥴 예약
		sche[s - 1].fee(plusHydrate, meal);	//해당 스케쥴의 추가요금 계산
		cout << "예약 완료되었습니다" << endl;
	}
	else {	//해당 좌석에 이미 예약이 있는 경우
		cout << "예약이 찬 좌석입니다" << endl;
		cout << "메인으로 돌아갑니다" << endl;
	}
}

// 스케쥴을 취소한다.
void AirlineBook::cancel() {
	system("cls");
	int s, ask;
	string bookName;
	int seatNo;

	s = Console::getScheduleMenu(); // 사용자가 선택한 스케쥴을 입력 받는다.
	view(s); // 스케쥴 s의 예약 상황을 출력한다.
	seatNo = Console::getSeatNo(); // 좌석 번호를 입력받는다.
	bookName = Console::getName(); // 예약자의 이름을 입력받는다.
	cout << "예약자 명 " << bookName << "의 " << s << "시 비행기의 " << seatNo << "번석를 취소하겠습니까?" << endl;
	cout << "1. YES		2. NO" << endl;
	cin >> ask;
	switch (ask) {
	case 1:
		sche[s - 1].cancel(seatNo, bookName);
		cout << "예약 취소되었습니다" << endl;
	case 2:
		cout << "실행 취소되었습니다" << endl;
		cout << "메인으로 돌아갑니다" << endl;
	}
}



// 현재 모든 스케쥴의 예약 상황을 출력한다.
void AirlineBook::view() {
	system("cls");
	for (int i = 0; i < 4; i++) {
		sche[i].view();
	}
	cout << endl;
}
void AirlineBook::change() {	//예약을 변경한다
	system("cls");	//화면 지우기
	int s, change;	//스케쥴 입력을 위한 변수s와 무엇을 변경할지 고르기 위한 변수 change
	string bookName;
	int seatNo, plusHydrate;	//예약한 자리 번호와 수화물갯수를 위한 변수
	int meal, meal_change;	//신청했던 기내식메뉴번호와 바꿀 기내식 메뉴번호를 받기위한 변수

	s = Console::getScheduleMenu(); // 사용자가 선택한 스케쥴을 입력 받는다.
	view(s); // 스케쥴 s의 예약 상황을 출력한다.
	seatNo = Console::getSeatNo(); // 좌석 번호를 입력받는다.
	if (sche[s - 1].booling(seatNo) == true) {	//해당 좌석이 예약되어있지 않은 좌석일 경우
		cout << "예약정보가 없습니다" << endl;
	}
	else {	//예약이 된 좌석인 경우
		bookName = Console::getName(); // 예약자의 이름을 입력받는다.
		plusHydrate = Console::hydrate();	//예약자가 신청한 수화물 수를 받는다
		cout << "선택하신 기내식 메뉴 번호를 입력하세요(신청 안하신 경우 0) >> ";
		cin >> meal;	//예약자가 신청한 기내식 번호를 받는다.
		system("cls");	//화면 지우기
		cout << "무엇을 변경하시겠습니까?" << endl;
		cout << "1. 탑승자명   2. 비행기 시간   3. 좌석   4. 위탁수화물   5. 기내식   6. 돌아가기" << endl;
		cout << "\t(비행기 시간 변경시 좌석도 다시 선택하셔야 합니다) >> ";
		cin >> change;
		switch (change) {
		case 1:	//탑승자명 변경
			cout << "변경하실 탑승자 명을 입력하세요" << endl;
			cout << ">> ";
			sche[s - 1].cancel(seatNo, bookName);	//해당좌석의 예약을 취소
			bookName = Console::getName();	//탑승자명 새로 받는다
			sche[s - 1].book(seatNo, bookName, plusHydrate, meal);	//새로받은 탑승자명으로 다시 예약
			view(s);	//결과화면을 보인다
			break;
		case 2:	//비행기 시간 변경
			cout << "변경하실 비행기 시간을 입력하세요" << endl;
			cout << ">> ";
			sche[s - 1].cancel(seatNo, bookName);	//해당 좌석의 예약을 취소
			s = Console::getScheduleMenu();	//변경할 비행기 시간을 입력받는다
			view(s);	//해당 비행기 시간을 보인다
			seatNo = Console::getSeatNo();	//해당 비행기 시간에서 앉을 좌석번호를 받는다.
			if (sche[s - 1].booling(seatNo) == true) {	//만약 좌석이 비어있다면
				sche[s - 1].book(seatNo, bookName, plusHydrate, meal);// 해당 스케쥴 예약
				view(s);	//결과화면을 보인다
			}
			else
				cout << "예약이 찬 좌석입니다" << endl;	//예약이 찬 상태라면
			break;
		case 3:	//좌석 변경
			cout << "변경하실 좌석번호를 입력하세요" << endl;
			cout << ">> ";
			sche[s - 1].cancel(seatNo, bookName);	//해당 좌석의 예약을 취소
			seatNo = Console::getSeatNo();
			if (sche[s - 1].booling(seatNo) == true) {
				sche[s - 1].book(seatNo, bookName, plusHydrate, meal);// 해당 스케쥴 예약
				view(s);
			}
			else
				cout << "예약이 찬 좌석입니다" << endl;
			break;
		case 4:	//위탁 수화물 갯수 변경
			cout << "변경하실 위탁수화물 수를 입력하세요" << endl;
			cout << ">> ";
			plusHydrate = Console::hydrate();	//변경할 위탁 수화물 수 입력
			sche[s - 1].cancel(seatNo, bookName);	//해당 좌석의 예약을 취소
			sche[s - 1].book(seatNo, bookName, plusHydrate, meal);	//변경받은 위탁 수화물 수로 다시 예약
			cout << endl;
			sche[s - 1].fee(plusHydrate, meal);	//바뀐 요금을 계산한다.
			break;

		case 5:	//기내식 변경
			cout << "기내식 추가 : 1    기내식 취소 : 2    기내식 변경 : 3" << endl;
			cout << " >> ";
			cin >> meal_change;
			switch (meal_change) {
			case 1:	//기내식 추가
				if (meal == 0) {	//기내식을 신청하지 않았을 경우
					sche[s - 1].cancel(seatNo, bookName);	//해당 좌석의 예약을 취소한다
					meal = Console::food();	//신청할 기내식 메뉴번호를 받는다
					sche[s - 1].book(seatNo, bookName, plusHydrate, meal);	//변경할 기내식 메뉴번호로 다시 해당좌석을 예약한다.
					sche[s - 1].fee(plusHydrate, meal);	//바뀐 추가요금을 계산하여 표시한다.
					break;
				}
				else {	//기내식을 이미 신청한 경우
					cout << "이미 기내식을 신청하셨습니다!" << endl;
					break;
				}
			case 2:	//기내식 취소
				if (meal == 0) {	//기내식을 신청하지 않았을 경우
					cout << "기내식을 신청하지 않으셨습니다!" << endl;
					break;
				}
				else {	//기내식을 신청했을 경우
					sche[s - 1].cancel(seatNo, bookName);	//해당 좌석의 예약을 취소한다
					meal = 0;	//기내식번호를 받는 변수에 0 주어준다.
					sche[s - 1].book(seatNo, bookName, plusHydrate, meal);	//meal값에 0을 넣어 다시 해당좌석 예약한다.
					cout << "기내식 신청을 취소하였습니다" << endl;
					sche[s - 1].fee(plusHydrate, meal);	//바뀐 추가요금을 계산하여 표시한다.
					break;
				}
			case 3:	//기내식 변경
				if (meal == 0) {	//기내식을 신청하지 않았을 경우
					cout << "기내식을 신청하지 않으셨습니다!" << endl;
					break;
				}
				else {	//기내식을 신청했을 경우
					sche[s - 1].cancel(seatNo, bookName);	//해당 좌석의 예약을 취소한다
					meal = Console::food();	//meal값에 새로운 기내식메뉴 번호를 받는다.
					sche[s - 1].book(seatNo, bookName, plusHydrate, meal);
					cout << "기내식 변경을 완료하였습니다" << endl;
					sche[s - 1].fee(plusHydrate, meal);	// 바뀐 추가요금을 계산하여 표시한다.
					break;
				}
			}
			break;

		case 6:	//돌아가기
			cout << "변경 취소되었습니다" << endl;
			cout << "메인으로 돌아갑니다" << endl;
		}
	}
}

// 스케쥴 s의 좌석 예약 상황을 출력한다. s는 1,2,3
void AirlineBook::view(int s) {
	system("cls");
	sche[s - 1].view(); //배열의 인덱스는 0부터 시작
}
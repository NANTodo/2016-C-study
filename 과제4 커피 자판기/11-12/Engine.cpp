#include <iostream>
using namespace std;

#include "define.h"
#include "Container.h"
#include "Engine.h"
#include "Panel.h"

Engine::Engine(Container con[]) { // 커피 자판기에 존재하는 통들에 대한 포인터 전달 받음
	this->con = con;
}

void Engine::run() { // 엔진 작동
	show(); // 현재 커피 자판기 상태 출력. 현재 각 통의 용량 출력

	while(true) {
		int menu = Panel::getButton(); // 사용자로부터 커피 종류 선택하여 리턴
		switch(menu) {
			case BLACK_COFFEE :
				if(!con[COFFEE].consume()) { // 커피 줄임
					printWarning(COFFEE);
					break;
				}
				if(!con[WATER].consume()) { // 물 줄임
					printWarning(WATER);
					break;
				}
				if(!con[CUP].consume()) { // 컵 줄임
					printWarning(CUP);
					break;
				}
				cout << "맛있는 블랙 커피 나왔습니다~~" << endl;
				break;
			case SUGAR_COFFEE :
				if(!con[COFFEE].consume()) { // 커피 줄임
					printWarning(COFFEE); // 커피가 없을 때 경고 메시지 출력
					break;
				}
				if(!con[WATER].consume()) { // 물 줄임
					printWarning(WATER);
					break;
				}
				if(!con[CUP].consume()) { // 컵 줄임
					printWarning(CUP);
					break;
				}
				if(!con[SUGAR].consume()) { // 설탕 줄임
					printWarning(SUGAR);
					break;
				}
				cout << "맛있는 설탕 커피 나왔습니다~~" << endl;
				break;
			case NORMAL_COFFEE:
				if(!con[COFFEE].consume()) { // 커피 줄임
					printWarning(COFFEE);
					break;
				}
				if(!con[WATER].consume()) { // 물 줄임
					printWarning(WATER);
					break;
				}
				if(!con[CUP].consume()) { // 컵 줄임
					printWarning(CUP);
					break;
				}
				if(!con[SUGAR].consume()) { // 설탕 줄임
					printWarning(SUGAR);
					break;
				}
				if(!con[CREAM].consume()) { // 크림 줄임
					printWarning(CREAM);
					break;
				}
				cout << "맛있는 다방 커피 나왔습니다~~" << endl;
				break;
			case HOT_KOKOA:
				if (!con[KOKOA].consume()) {
					printWarning(KOKOA);
					break;
				}
				if (!con[WATER].consume()) { // 물 줄임
					printWarning(WATER);
					break;
				}
				if (!con[CUP].consume()) { // 컵 줄임
					printWarning(CUP);
					break;
				}
				if (!con[SUGAR].consume()) { // 설탕 줄임
					printWarning(SUGAR);
					break;
				}
				cout << "맛있는 핫초코 나왔습니다~~" << endl;
				break;

			case FILL: // 모든 재료를 최대로 채운다.
				cout << "모든 통을 채웁니다.~~" << endl;
				for(int i=0;  i<6; i++) con[i].fill(); // 모든 통에 재료 최대로 채움
				break;
			case EXIT: // 종료 메뉴
				return; // 엔진 종료
			default:
				cout << "잘못 입력하셨습니다" << endl;
				break;
		}
		show();
	}
}

void Engine::watertemp() {
	int temp = 90 + (rand() % 10);// 10으로 나눈 나머지 값이므로 0~9사이. 고로 90~99도 사이의 온도
	cout << "현재 온수 온도는 " << temp << "℃입니다" << endl;
}

void Engine::show() {
	for(int i=0;  i<6; i++) 
		con[i].show();
	watertemp();
	cout << endl;
}

void Engine::printWarning(int id) {
	switch(id) {
		case COFFEE : cout << "커피가 없습니다." <<endl;  break;
		case KOKOA: cout << "코코아가 없습니다." << endl; break;
		case SUGAR : cout << "설탕이 없습니다." <<endl;  break;
		case CREAM : cout << "크림이 없습니다." <<endl;  break;
		case WATER : cout << "물이 없습니다." <<endl;  break;
		case CUP : cout << "컵이 없습니다." <<endl;  break;
	}
}
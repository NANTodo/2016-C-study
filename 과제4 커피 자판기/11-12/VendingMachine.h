#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <string>
using namespace std;

class Engine;
class Container;

class VendingMachine { // 커피 자판기 전체를 관리하는 클래스
	Container *con; // 커피, 물 등의 통들을 배열로 관리하기 위한 포인터
	string name; // 자판기 이름
	Engine *engine; // 사용자의 커피 종류 선택에서 부터 자판기를 시뮬레이션하는 엔진에 대한 포인터
public:
	VendingMachine(string name);
	~VendingMachine();
	void powerOn(); // 커피 자판기 시작. 이 함수가 끝나면 커피 자판기 종료
};
#endif
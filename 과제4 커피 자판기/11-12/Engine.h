#ifndef ENGINE_H
#define ENGINE_H

#include <string>
using namespace std;

#include "Container.h"

// 커피 자판기의 핵심 클래스로서, 사용자의 커피 선택으로부터
// 각 통에 들어 있는 재료를 줄이거나 늘리는 등, 
// 커피 자판기를 시뮬레이션 하는 클래스
class Engine { 
	Container *con; // 전체 통들에 대한 포인터
public:
	Engine(Container []);
	void run(); // 엔진 작동 
	void watertemp();
	void show();
	void printWarning(int id);
};

#endif
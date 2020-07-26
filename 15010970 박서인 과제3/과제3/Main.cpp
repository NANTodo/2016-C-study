// 이 프로젝트는 사용자의 입력 오류를 걸러내지 않는 버전입니다.
// 그러므로 사용자가 주의하여 입력하여야 합니다.
// 이 버전을 제공하는 이유는 비교적 소스 라인을 줄여서 독자들의 소스 분석을 쉽게 하기 위함입니다.

#include <string>
using namespace std;

#include "AirlineBook.h"

int main() {
	string sheduleTime[] = { "7시", "12시", "17시", "19시" };
	AirlineBook *p = new AirlineBook("WPP항공", 4, sheduleTime, 2, 4);
	p->run();

	delete p;
}
// �� ������Ʈ�� ������� �Է� ������ �ɷ����� �ʴ� �����Դϴ�.
// �׷��Ƿ� ����ڰ� �����Ͽ� �Է��Ͽ��� �մϴ�.
// �� ������ �����ϴ� ������ ���� �ҽ� ������ �ٿ��� ���ڵ��� �ҽ� �м��� ���� �ϱ� �����Դϴ�.

#include <string>
using namespace std;

#include "AirlineBook.h"

int main() {
	string sheduleTime[] = { "7��", "12��", "17��", "19��" };
	AirlineBook *p = new AirlineBook("WPP�װ�", 4, sheduleTime, 2, 4);
	p->run();

	delete p;
}
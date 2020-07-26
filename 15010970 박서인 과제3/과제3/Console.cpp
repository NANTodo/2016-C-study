#include <iostream>
using namespace std;
#include <string>
#include <cstring>

#include "Console.h"


int Console::getMainMenu() {	//mainmenu�� ����޴� �߰�
	cout << "����:1, ���:2, ��Ȳ:3, ����:4, ������:5 >>";
	int menu;
	cin >> menu;
	return menu;
}

int Console::getScheduleMenu() {	//19�� �ð� �߰�
	cout << "7��:1, 12��:2, 17��:3, 19��:4 >>";
	int menu;
	cin >> menu;
	return menu;
}

string Console::getName() {
	cout << "�̸� �Է� >>";
	string name;
	cin >> name;
	return name;
}

int Console::getSeatNo() {
	cout << "�¼� ��ȣ >> ";
	int no;
	cin >> no;
	if (no > 8) {
		cout << "�¼��� 8�������Դϴ�" << endl;
		getSeatNo();
	}
	else
		return no;
}

int Console::hydrate() {	//hydrate(): ��Ź���Ϲ� ���� �Է� �Լ�
	cout << "��Ź��ȭ�� ��(�ִ� 2��)" << endl;
	cout << "���� 20000KRW�� ����� �߰��˴ϴ�" << endl;
	cout << ">> ";
	int num;
	cin >> num;
	if ((-1 < num) && (num < 3)) {	//0~2 ���� �Է��� �޴´�.
		return num;
	}
	else {	//�װ� �ƴϸ� �ź��ϰ� ���Է� �䱸.
		cout << "��ȭ���� �ִ� �� �������� ��Ź�����մϴ�" << endl;
		hydrate();
	}
}

int Console::food() {	//�⳻�� �޴����� �Լ�
		cout << "\t�⳻�� �޴��� �������ּ���" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "�޴�1 : ������ũ�� ���� ���� / 20000KRW" << endl;
		cout << "�޴�2 : �����丮�� ȭ��Ʈ ���� / 15000KRW" << endl;
		cout << "�޴�3 : �ٷ��� ���ö� / 20000KRW" << endl;
		cout << "�޴�4 : ��Į�θ� ���ö� / 20000KRW" << endl;
		cout << "===============================================" << endl;
		cout << ">> ";
		int menu_choice;
		cin >> menu_choice;
			switch (menu_choice) {
			case 1:	//�޴�1: ������ũ�� ���� ����
				cout << "20000KRW�� ����� �߰��˴ϴ� " << endl;
				return menu_choice;
				break;
			case 2:	//�޴�2 : �����丮�� ȭ��Ʈ ����
				cout << "15000KRW�� ����� �߰��˴ϴ�" << endl;
				return menu_choice;
				break;
			case 3:	//�޴�3 : �ٷ��� ���ö�
				cout << "20000KRW�� ����� �߰��˴ϴ�" << endl;
				return menu_choice;
			case 4:	//�޴�4 : ��Į�θ� ���ö�
				cout << "20000KRW�� ����� �߰��˴ϴ�" << endl;
				return menu_choice;
				break;
			default:	//�� ���ǰ� �Է��ϴ� ���
				cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			}
	}
void Console::fee(int hydrates, int food) {	//�߰� ��ݵ��� ��� �ϴ� �Լ�

	int menuprice[4] = { 20000, 15000, 20000, 20000 };	//�⳻�� �޴� �װ����� ����
	int fee;
	if (food == 0) {	//�⳻���� ��û���� �ʾ������
		fee = hydrates * 20000;	//��û�� ���Ϲ� ��x20000������ ���
	}
	else if (food < 5 && food>0) {	//�⳻���� ��û�� ���
		fee = (hydrates * 20000) + menuprice[food - 1];	//����� (��û�� ���Ϲ� �� x20000��) ���ϱ� ������ �⳻�ĸ޴��� ����
	}
	cout << "���� �߰� ����� " << fee << "KRW�Դϴ�" << endl;

}
void Console::print(string msg) {
	cout << msg;
}
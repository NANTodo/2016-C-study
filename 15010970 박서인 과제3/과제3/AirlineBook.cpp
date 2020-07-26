#include <iostream>
#include <conio.h>
using namespace std;
#include <string>

#include "AirlineBook.h"
#include "Schedule.h"
#include "Console.h"
#include "Seat.h"


// ������
AirlineBook::AirlineBook(string name, int nSchedules, string scheduleTime[], int hydrates, int food) {
	this->name = name; // �̸�
	this->nSchedules = nSchedules; // ������ ����
	this->hydrates = hydrates;
	this->food = food;	
	sche = new Schedule[nSchedules]; // 4 ���� ������ ��ü ����

									 // �� �����쿡 �ش� �ð� ����
	for (int i = 0; i < nSchedules; i++)
		sche[i].setTime(scheduleTime[i]);
}

// �Ҹ���
AirlineBook::~AirlineBook() {
	if (sche)
		delete[] sche;
}

// ���� �ý����� �����ϴ� �Լ�
void AirlineBook::run() {
	cout << "*** " << name << "�� ���Ű��� ȯ���մϴ�." << " ***" << endl;
	cout << endl;

	while (true) {
		int menu = Console::getMainMenu(); // ���� �޴� �Է�
		switch (menu) {
		case 1:
			book(); // ����
			break;
		case 2:
			cancel(); // ���
			break;
		case 3:
			view(); // ���� ����
			break;
		case 4:
			change();	//���� ����
			break;
		case 5:
			cout << "���� �ý����� �����մϴ�.\n" << endl;
			return;
		default:
			cout << "�߸��Է��Ͽ����ϴ�.\n" << endl;
			break;
		}
		cout << endl;
	}
}

// �������� �����Ѵ�.
void AirlineBook::book() {
	int s, ask;
	string bookName;
	int seatNo, plusHydrate, meal;

	s = Console::getScheduleMenu(); // ����ڰ� ������ �������� �Է� �޴´�.
	view(s); // ������ s�� ���� ��Ȳ�� ����Ѵ�.
	seatNo = Console::getSeatNo(); // �¼� ��ȣ�� �Է¹޴´�.
	if (sche[s - 1].booling(seatNo) == true) {	//�Է��� �¼���ȣ�� ����Ǿ��ִ� ������ ���ٸ�
		bookName = Console::getName(); // �������� �̸��� �Է¹޴´�.
		plusHydrate = Console::hydrate();	//��Ź ��ȭ�� ������ �Է¹޴´�
		cout << "�⳻���� �߰��Ͻðڽ��ϱ�?" << endl;	//�⳻�� �߰����� Ȯ��
		cout << "\t" << "Yes : 1     No : 2 " << endl;
		cin >> ask;
		switch (ask) {
		case 1:	//�߰��ϴ� ���
			meal = Console::food();
			break;
		case 2:	//�߰� ���� �ʴ� ���
			cout << "�⳻���� �߰����� �ʽ��ϴ�" << endl;
			meal = 0;
		}
		sche[s - 1].book(seatNo, bookName, plusHydrate, meal);// �ش� ������ ����
		sche[s - 1].fee(plusHydrate, meal);	//�ش� �������� �߰���� ���
		cout << "���� �Ϸ�Ǿ����ϴ�" << endl;
	}
	else {	//�ش� �¼��� �̹� ������ �ִ� ���
		cout << "������ �� �¼��Դϴ�" << endl;
		cout << "�������� ���ư��ϴ�" << endl;
	}
}

// �������� ����Ѵ�.
void AirlineBook::cancel() {
	system("cls");
	int s, ask;
	string bookName;
	int seatNo;

	s = Console::getScheduleMenu(); // ����ڰ� ������ �������� �Է� �޴´�.
	view(s); // ������ s�� ���� ��Ȳ�� ����Ѵ�.
	seatNo = Console::getSeatNo(); // �¼� ��ȣ�� �Է¹޴´�.
	bookName = Console::getName(); // �������� �̸��� �Է¹޴´�.
	cout << "������ �� " << bookName << "�� " << s << "�� ������� " << seatNo << "������ ����ϰڽ��ϱ�?" << endl;
	cout << "1. YES		2. NO" << endl;
	cin >> ask;
	switch (ask) {
	case 1:
		sche[s - 1].cancel(seatNo, bookName);
		cout << "���� ��ҵǾ����ϴ�" << endl;
	case 2:
		cout << "���� ��ҵǾ����ϴ�" << endl;
		cout << "�������� ���ư��ϴ�" << endl;
	}
}



// ���� ��� �������� ���� ��Ȳ�� ����Ѵ�.
void AirlineBook::view() {
	system("cls");
	for (int i = 0; i < 4; i++) {
		sche[i].view();
	}
	cout << endl;
}
void AirlineBook::change() {	//������ �����Ѵ�
	system("cls");	//ȭ�� �����
	int s, change;	//������ �Է��� ���� ����s�� ������ �������� ���� ���� ���� change
	string bookName;
	int seatNo, plusHydrate;	//������ �ڸ� ��ȣ�� ��ȭ�������� ���� ����
	int meal, meal_change;	//��û�ߴ� �⳻�ĸ޴���ȣ�� �ٲ� �⳻�� �޴���ȣ�� �ޱ����� ����

	s = Console::getScheduleMenu(); // ����ڰ� ������ �������� �Է� �޴´�.
	view(s); // ������ s�� ���� ��Ȳ�� ����Ѵ�.
	seatNo = Console::getSeatNo(); // �¼� ��ȣ�� �Է¹޴´�.
	if (sche[s - 1].booling(seatNo) == true) {	//�ش� �¼��� ����Ǿ����� ���� �¼��� ���
		cout << "���������� �����ϴ�" << endl;
	}
	else {	//������ �� �¼��� ���
		bookName = Console::getName(); // �������� �̸��� �Է¹޴´�.
		plusHydrate = Console::hydrate();	//�����ڰ� ��û�� ��ȭ�� ���� �޴´�
		cout << "�����Ͻ� �⳻�� �޴� ��ȣ�� �Է��ϼ���(��û ���Ͻ� ��� 0) >> ";
		cin >> meal;	//�����ڰ� ��û�� �⳻�� ��ȣ�� �޴´�.
		system("cls");	//ȭ�� �����
		cout << "������ �����Ͻðڽ��ϱ�?" << endl;
		cout << "1. ž���ڸ�   2. ����� �ð�   3. �¼�   4. ��Ź��ȭ��   5. �⳻��   6. ���ư���" << endl;
		cout << "\t(����� �ð� ����� �¼��� �ٽ� �����ϼž� �մϴ�) >> ";
		cin >> change;
		switch (change) {
		case 1:	//ž���ڸ� ����
			cout << "�����Ͻ� ž���� ���� �Է��ϼ���" << endl;
			cout << ">> ";
			sche[s - 1].cancel(seatNo, bookName);	//�ش��¼��� ������ ���
			bookName = Console::getName();	//ž���ڸ� ���� �޴´�
			sche[s - 1].book(seatNo, bookName, plusHydrate, meal);	//���ι��� ž���ڸ����� �ٽ� ����
			view(s);	//���ȭ���� ���δ�
			break;
		case 2:	//����� �ð� ����
			cout << "�����Ͻ� ����� �ð��� �Է��ϼ���" << endl;
			cout << ">> ";
			sche[s - 1].cancel(seatNo, bookName);	//�ش� �¼��� ������ ���
			s = Console::getScheduleMenu();	//������ ����� �ð��� �Է¹޴´�
			view(s);	//�ش� ����� �ð��� ���δ�
			seatNo = Console::getSeatNo();	//�ش� ����� �ð����� ���� �¼���ȣ�� �޴´�.
			if (sche[s - 1].booling(seatNo) == true) {	//���� �¼��� ����ִٸ�
				sche[s - 1].book(seatNo, bookName, plusHydrate, meal);// �ش� ������ ����
				view(s);	//���ȭ���� ���δ�
			}
			else
				cout << "������ �� �¼��Դϴ�" << endl;	//������ �� ���¶��
			break;
		case 3:	//�¼� ����
			cout << "�����Ͻ� �¼���ȣ�� �Է��ϼ���" << endl;
			cout << ">> ";
			sche[s - 1].cancel(seatNo, bookName);	//�ش� �¼��� ������ ���
			seatNo = Console::getSeatNo();
			if (sche[s - 1].booling(seatNo) == true) {
				sche[s - 1].book(seatNo, bookName, plusHydrate, meal);// �ش� ������ ����
				view(s);
			}
			else
				cout << "������ �� �¼��Դϴ�" << endl;
			break;
		case 4:	//��Ź ��ȭ�� ���� ����
			cout << "�����Ͻ� ��Ź��ȭ�� ���� �Է��ϼ���" << endl;
			cout << ">> ";
			plusHydrate = Console::hydrate();	//������ ��Ź ��ȭ�� �� �Է�
			sche[s - 1].cancel(seatNo, bookName);	//�ش� �¼��� ������ ���
			sche[s - 1].book(seatNo, bookName, plusHydrate, meal);	//������� ��Ź ��ȭ�� ���� �ٽ� ����
			cout << endl;
			sche[s - 1].fee(plusHydrate, meal);	//�ٲ� ����� ����Ѵ�.
			break;

		case 5:	//�⳻�� ����
			cout << "�⳻�� �߰� : 1    �⳻�� ��� : 2    �⳻�� ���� : 3" << endl;
			cout << " >> ";
			cin >> meal_change;
			switch (meal_change) {
			case 1:	//�⳻�� �߰�
				if (meal == 0) {	//�⳻���� ��û���� �ʾ��� ���
					sche[s - 1].cancel(seatNo, bookName);	//�ش� �¼��� ������ ����Ѵ�
					meal = Console::food();	//��û�� �⳻�� �޴���ȣ�� �޴´�
					sche[s - 1].book(seatNo, bookName, plusHydrate, meal);	//������ �⳻�� �޴���ȣ�� �ٽ� �ش��¼��� �����Ѵ�.
					sche[s - 1].fee(plusHydrate, meal);	//�ٲ� �߰������ ����Ͽ� ǥ���Ѵ�.
					break;
				}
				else {	//�⳻���� �̹� ��û�� ���
					cout << "�̹� �⳻���� ��û�ϼ̽��ϴ�!" << endl;
					break;
				}
			case 2:	//�⳻�� ���
				if (meal == 0) {	//�⳻���� ��û���� �ʾ��� ���
					cout << "�⳻���� ��û���� �����̽��ϴ�!" << endl;
					break;
				}
				else {	//�⳻���� ��û���� ���
					sche[s - 1].cancel(seatNo, bookName);	//�ش� �¼��� ������ ����Ѵ�
					meal = 0;	//�⳻�Ĺ�ȣ�� �޴� ������ 0 �־��ش�.
					sche[s - 1].book(seatNo, bookName, plusHydrate, meal);	//meal���� 0�� �־� �ٽ� �ش��¼� �����Ѵ�.
					cout << "�⳻�� ��û�� ����Ͽ����ϴ�" << endl;
					sche[s - 1].fee(plusHydrate, meal);	//�ٲ� �߰������ ����Ͽ� ǥ���Ѵ�.
					break;
				}
			case 3:	//�⳻�� ����
				if (meal == 0) {	//�⳻���� ��û���� �ʾ��� ���
					cout << "�⳻���� ��û���� �����̽��ϴ�!" << endl;
					break;
				}
				else {	//�⳻���� ��û���� ���
					sche[s - 1].cancel(seatNo, bookName);	//�ش� �¼��� ������ ����Ѵ�
					meal = Console::food();	//meal���� ���ο� �⳻�ĸ޴� ��ȣ�� �޴´�.
					sche[s - 1].book(seatNo, bookName, plusHydrate, meal);
					cout << "�⳻�� ������ �Ϸ��Ͽ����ϴ�" << endl;
					sche[s - 1].fee(plusHydrate, meal);	// �ٲ� �߰������ ����Ͽ� ǥ���Ѵ�.
					break;
				}
			}
			break;

		case 6:	//���ư���
			cout << "���� ��ҵǾ����ϴ�" << endl;
			cout << "�������� ���ư��ϴ�" << endl;
		}
	}
}

// ������ s�� �¼� ���� ��Ȳ�� ����Ѵ�. s�� 1,2,3
void AirlineBook::view(int s) {
	system("cls");
	sche[s - 1].view(); //�迭�� �ε����� 0���� ����
}
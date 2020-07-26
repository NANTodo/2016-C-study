#include <iostream>
using namespace std;

#include "Seat.h"

Seat::Seat() {
	name = "";
}

// ����
void Seat::book(string name, int hydrates, int food) {	//�ڸ������Լ�
	this->name = name;	//name��Ʈ�� �Է¹��� name��
	this->hydrates = hydrates;	//hydrates��Ʈ�� �Է¹��� hydrates(��ȭ����)��
	this->food = food;	//food��Ʈ�� �Է¹��� food(�⳻�� �޴���ȣ)��

}

// ���� Ȯ��
bool Seat::isBooked() {
	if (name.size() == 0)	//name�� ���� ���� ������ false
		return false;
	else
		return true;	//���� ���� ������ ture
}

// ���� ���
void Seat::cancel(string name) {
	this->name = ""; // �̸� ����
}

// ������ �̸� ���
void Seat::view() {
	if (isBooked()) {
		if (food == 0) {	//�⳻�� �޴��� �������� �ʾ��� ���
			cout << name << " / " << hydrates << " / " << "��û����" << "\t";
		}
		else		
			cout << name << " / " << hydrates << " / " << "�޴�" << food << "\t";	//�⳻�� �޴� �����������
	}
	else
		cout << "---" << " / " << "--" << " / " << "--" << "\t";	//� �Էµ� ���� �ʾ��� ���
}
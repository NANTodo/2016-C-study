#include <iostream>
#include <string>
using namespace std;
class SuperHero {
private:
	string pHeroName; //����θ�
	string team; //�Ҽ���
	int Movie; //�⿬��ȭ����
	string Programmer;
public:
	SuperHero(); //�⺻������(�ʱ�ȭ�۾�)
	SuperHero(string p, string t, int a); // �μ�3��������(�����۾�)
	string Getteam(); //�Ҽ��������Լ�
	void SetTeam(char* t);
	void SetMovie(int a); //�⿬��ȭ���������Լ�
	void SetHeroName(char* p); //����θ����Լ�
	void Disp(); //����Լ�
	void copyright(char *c);
};

SuperHero::SuperHero()
{
	pHeroName[0] = NULL;
	team[0] = NULL;
	Movie = 0;
}

SuperHero::SuperHero(string p, string t, int a)
{
	pHeroName = p;
	team = t;
	Movie = a;
}

string SuperHero::Getteam()
{
	return this->team;
}

void SuperHero::SetTeam(char *t)
{
	cout << this->pHeroName << "�� �Ҽ����� " << this->team << "���� "
		<< t << "���� ����\n" << endl;
	team = t;
}

void SuperHero::SetMovie(int a)
{
	cout << this->pHeroName << "�� �⿬ ��ȭ ������ " << this->Movie << "������ "
		<< a << "���� ����\n" << endl;
	this->Movie = a;
}

void SuperHero::SetHeroName(char* p)
{
	cout << this->pHeroName << "�̶�� ����θ��� " << p << "�� ����\n" << endl;
	pHeroName = p;
}

void SuperHero::Disp()
{
	cout << "����θ�: " << pHeroName << endl;
	cout << "�Ҽ���: " << team << endl;
	cout << "�⿬ ��ȭ��: " << Movie << "��\n" << endl;
}

void SuperHero::copyright(char *c)
{
		cout << "������ : " << c << endl;
}
int main()
{
	SuperHero call;
	SuperHero *superHero[5];
	superHero[0] = new SuperHero("Spider Man", "Team Iron Man", 6);
	superHero[1] = new SuperHero("Iron Man", "Team Iron Man", 6);
	superHero[2] = new SuperHero("Captain America", "Team Captain", 5);
	superHero[3] = new SuperHero("Black Widow", "Team Iron Man", 5);
	superHero[4] = new SuperHero("Falcon", "Team Captain", 4);
	
	for (int i = 0; i < 5; i++)
		superHero[i]->Disp();
	
	superHero[0]->SetTeam("Team Captain");

	superHero[0]->Disp();

	call.copyright("�ڼ���");
	
	return 0;
}
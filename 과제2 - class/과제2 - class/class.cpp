#include <iostream>
#include <string>
using namespace std;
class SuperHero {
private:
	string pHeroName; //히어로명
	string team; //소속팀
	int Movie; //출연영화갯수
	string Programmer;
public:
	SuperHero(); //기본생성자(초기화작업)
	SuperHero(string p, string t, int a); // 인수3개생성자(대입작업)
	string Getteam(); //소속팀리턴함수
	void SetTeam(char* t);
	void SetMovie(int a); //출연영화갯수변경함수
	void SetHeroName(char* p); //히어로명변경함수
	void Disp(); //출력함수
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
	cout << this->pHeroName << "의 소속팀을 " << this->team << "에서 "
		<< t << "으로 변경\n" << endl;
	team = t;
}

void SuperHero::SetMovie(int a)
{
	cout << this->pHeroName << "의 출연 영화 갯수를 " << this->Movie << "개에서 "
		<< a << "개로 변경\n" << endl;
	this->Movie = a;
}

void SuperHero::SetHeroName(char* p)
{
	cout << this->pHeroName << "이라는 히어로명을 " << p << "로 변경\n" << endl;
	pHeroName = p;
}

void SuperHero::Disp()
{
	cout << "히어로명: " << pHeroName << endl;
	cout << "소속팀: " << team << endl;
	cout << "출연 영화수: " << Movie << "개\n" << endl;
}

void SuperHero::copyright(char *c)
{
		cout << "개발자 : " << c << endl;
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

	call.copyright("박서인");
	
	return 0;
}
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct Machine
{
	string Drink_name;
	float cost;
	int num_drinks;
};

struct Machine drink[] = { { "coke", .75, 2 },{ "A and W", .75, 20 },{ "sprite", .75, 20 },
{ "shasta", .80, 20 },{ "minute maid", .80, 20 } };

int main()
{
	int menu_choice = 0;
	float moneyin;
	float moneyout;
	float temp;
	while (menu_choice != 6)
	{
		cout << "which drink would you like to buy:" << endl;
		cout << "1-coke" << endl;
		cout << "2-A and W" << endl;
		cout << "3-sprite" << endl;
		cout << "4-shasta" << endl;
		cout << "5-minute maid" << endl;
		cout << "6-Quit\n " << endl;
		cin >> menu_choice;

		if (menu_choice != 6) {

			if (drink[menu_choice - 1].num_drinks < 1) {
				cout << "That beverage is SOLD OUT!!!" << endl;
				cout << "Please press another beverage" << endl;
			}
			else {
				cout << "enter money to inserted into machine between 0 and $1.00" << endl;
				cin >> moneyin;

				while (moneyin < drink[menu_choice - 1].cost)
				{
					cout << "enter" << drink[menu_choice - 1].cost << endl;
					cin >> moneyin;
				}
				cout << "great" << endl;

				if (moneyin > drink[0].cost)
					cout << " your change is:" << (moneyin - drink[menu_choice - 1].cost) << endl;
			}
			(drink[menu_choice - 1].num_drinks)--;
			cout << "" << drink[menu_choice - 1].num_drinks << "left"<< endl;
		}
	}
	return 0;
}


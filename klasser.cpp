#include <iostream>
#include <math.h>
using namespace std;
//KLASS(Combatsystem)
class Combat
{

	public:
//int-variabler
//funktioner
	void spells();
	void fireblast();
	void kicknscream();
	void Pyrotorment();
};
//KLASS(weakmage)
class character
{
	public:
//Int-variabler
	int hp = 100;
};
//KLASS(terrible foe)
class foe
{
	public:
//int-variabler
	int dmg;
	int hp = 100;
//funktioner
	void remaininghp();
};

void foe::remaininghp()
{
	cout << dmg << endl;
	cout << "Press enter to check functionality of function\n";
	//cin >> getline;
	hp = hp-dmg;
	cout << "\n Your enemy has " << endl;
	cout << hp;
}

void Combat::fireblast()
{
foe dmgtofoe;
foe hpcheck;
	auto roll = (rand() % 10) + 1;
	if (roll <= 3){
	cout << "\n Your attack was lacking in both focus and general competence - and missed";	
	}else if (roll >= 3){
	roll+10;
	cout << roll << endl;
	//dmgtofoe.dmg = roll
	hpcheck.remaininghp();
	}

}
			
	



void Combat::spells()
{
	cout << "\n Which spell would you like to use?\n";
	cout << "Type(1): Fireblast\n Type(2): Kick and scream\n Type(3): Pyrotorment";
}

int main()
{
Combat my_object;
	cout << "\n You've encountered a terrible foe, you're a weak mage and you left your pumped up kicks at home.";
	cout << "\n Running is not an option";
	my_object.fireblast();
}
//auto val = (rand() % 10) + 1;

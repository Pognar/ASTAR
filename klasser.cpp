#include <iostream>
#include <math.h>
#include <stdlib.h> 
using namespace std;

//KLASS(Combatsystem)
class Combat
{
	public:
//int-variabler
	int fireblast_dmg = 15;
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
//----Int-variabler
	int hp = 100;
};
//KLASS(terrible foe)
class foe
{
	public:
//-----int-variabler
	int dmg = 0;
	int hp = 100;
//funktioner
	void remaininghp();
};

void foe::remaininghp()
{
foe dmg_func;
foe hp_func;
Combat fireblast_sub;
Combat go_to_spells;
	
//ANVÄND &HP POINTER
	//hp = hp-fireblast_sub.fireblast_dmg;
	cout << "Your enemy has ";
	cout << hp;
	cout << "HP left" << endl;


	//cout << dmg_func.dmg << endl;
	//cout << "Press enter to check functionality of function\n";
	//hp_func.hp = hp_func.hp-dmg_func.dmg;
	//cout << "\n Your enemy has " << endl;
	//cout << hp_func.hp;
go_to_spells.spells();
}



void Combat::fireblast(foe &enemy)
{
foe go_to_enemy;
	
	enemy.hp = enemy.hp-fireblast_dmg;
	cout << "Your fireblast did ";
	cout << fireblast_dmg;
	cout << " Damage " << endl;
	//cout << "Your enemy has ";
	//cout << hpcheck.hp;
	//enemy.remaininghp();
	//auto roll = (rand() % 10) + 1;
	//auto i = roll;
	//cout << roll << endl;
	//if (i <= 3){
	//cout << "\n Your attack was lacking in both focus and general competence - and missed";	
	//}else if (i >= 3){
	//i+10;
	//cout << roll << endl;
	//dmgtofoe.dmg = roll;
	//hpcheck.remaininghp();
	//}
	

}
			
	



void Combat::spells()
{
Combat go_to_spell;
	
	cout << "\n Which spell would you like to use?\n";
	cout << "Type(1): Fireblast\n Type(2): Kick and scream\n Type(3): Pyrotorment" << endl;
	int i;
	cin >> i;
	if (i <= 1){
	go_to_spell.fireblast();
  	} else if (i <= 2){
	go_to_spell.spells();
	}
	
}

int main()
{
Combat my_object;
	cout << "\n You've encountered a terrible foe, you're a weak mage and you left your pumped up kicks at home.";
	cout << "\n Running is not an option";
	my_object.spells();
}
//auto val = (rand() % 10) + 1;

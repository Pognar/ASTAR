#include <iostream>
#include <math.h>
#include <stdlib.h> 
using namespace std;

class character
{
	public:
	int my_hp = 100;
	int foe_hp = 100;
	
	void hpcheck();
};

class combat
{
	public:
	int fireblast_dmg = 15;
	int kick_dmg = 10;

	void fireblast(character &enemy);
	void kicknscream(character &enemy2);	
	
	void spell_list();

};


//funktionsdeklarationer

void combat::fireblast(character &enemy)
{
	enemy.foe_hp = enemy.foe_hp - fireblast_dmg;
	cout << enemy.foe_hp << endl;
}

void combat::kicknscream(character &enemy2)
{
	enemy2.foe_hp = enemy2.foe_hp - kick_dmg;
	cout << enemy2.foe_hp << endl;

}

void character::hpcheck()
{
combat func_call;
character foe;
character hp_check;
	cout << "Hello" << endl;
	
	
	int i;
	do
	{	
	cout << "\n Which spell would you like to use?\n";
	cout << "Type(1): Fireblast\n Type(2): Kick and scream\n Type(3): Pyrotorment" << endl;
	cin >> i;
		if (i <= 1){
			func_call.fireblast(foe);
  				}else if (i <= 2){
					func_call.kicknscream(foe);
						}
							}while(foe_hp >= 0 || my_hp >=0);


		
}
	





int main(){
combat func_call;
character foe;
character hp_check;

	hp_check.hpcheck();	 

	

}

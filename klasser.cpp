#include <iostream>
#include <math.h>
#include <stdlib.h> 
#include <math.h>
using namespace std;

class character
{
	public:
	int foe_hp = 100;
	void hpcheck(character &foe);
};

class combat
{
	public:
	int enemy_damage = 2;
	int fireblast_dmg = 15;
	int kick_dmg = 35;
	float rolls[3] = {1, 0.5, 0};
	void fireblast(character &enemy);
	void kicknscream(character &enemy2);
	void nastycurse(character &enemy);
	void some_dmg(character &enemy);
};
class interac
{
	public:
	void end(character &myhealth);

};
//funktionsdeklarationer

void interac::end(character &myhealth)
{
interac go_to_victory;
	if(myhealth.foe_hp <= 0)
	{
		cout << "You are dead" << endl;
	}else if(myhealth.foe_hp >= 0){
		cout << "You are victorious, every dog has it's day" << endl;
	}
}

void combat::some_dmg(character &enemy)
{
	auto roll = (rand() % 10) + 1;
	enemy.foe_hp = enemy.foe_hp - roll*enemy_damage;
	cout << "You have " << enemy.foe_hp << " HP left" << endl;
	if(roll <=3){
		cout << "Your enemy was busy flicking his glorious blond locks out of his beautiful eyes and barely touched you with his attack" << endl;
	}else if (roll >= 4 && roll <= 7){
		cout << "Your enemy's uppercut actually made your face prettier." << endl;
	}else if (roll >= 8){
		cout << "Your enemy uses the attack (Gaze of the gods) - Causing critical damage." << endl; 
	} 	
}

void combat::fireblast(character &enemy)
{
combat fireman;

	auto roll = (rand() % 10) + 1;
	if(roll <= 3){
		fireblast_dmg = fireman.fireblast_dmg*rolls[2];
		enemy.foe_hp = enemy.foe_hp - fireblast_dmg;
		cout << "Handsome Muscular foe:"  "Pathic, you barley lit my extraordinarily masculine cigar with that puff of smoke!" << endl;
		cout << "Your handsome enemy has: " << enemy.foe_hp << " HP left" << endl;
		}else if (roll >= 4 && roll <= 7){
			fireblast_dmg = fireman.fireblast_dmg*rolls[1];
			enemy.foe_hp = enemy.foe_hp - fireblast_dmg;
			cout << "Handsome Muscular foe: Do you need match or something? SOMEONE PLEASE GIVE THIS MAGE SOME MANA!" << endl;
			cout << "Your handsome enemy has: " << enemy.foe_hp << " HP left" << endl;
		}else if(roll >= 8){
			fireblast_dmg = fireman.fireblast_dmg*rolls[0];
			enemy.foe_hp = enemy.foe_hp - fireblast_dmg;
			cout << "The handsome Muscular foe falls to the ground screaming in agony after that terrible fire curse!" << endl;
			cout << "Your handsome enemy has: " << enemy.foe_hp << " HP left" << endl;
}
}	

void combat::kicknscream(character &enemy2)
{
combat brucelee;
	auto roll = (rand() % 10) + 1;
	if(roll <= 7){
		kick_dmg = brucelee.kick_dmg*rolls[2];
		enemy2.foe_hp = enemy2.foe_hp - kick_dmg;
		cout << "Your flailing, crying and screaming is not helping anyone " << endl;
		cout << "Your handsome enemy has: " << enemy2.foe_hp << " HP left" << endl;
		}else if (roll >= 8){
			kick_dmg = brucelee.kick_dmg*rolls[0];
			enemy2.foe_hp = enemy2.foe_hp - kick_dmg;
			cout << "Your kicking and screaming caused you to accidentally kick your enemy in the chin, causing critical damage" << endl;
			cout << "Your handsome enemy has: " << enemy2.foe_hp << " HP left" << endl;
		}
}

void combat::nastycurse(character &enemy)
{
character func_dial;
	auto roll = (rand() % 10) + 1;
	if(roll >= 7){
		cout << "Your nasty curse hit your opponent in his testicles! Giving you two extra turns to attack while your enemy writhes in agony!" << endl;
		for(int i = 0; i<=2; i++)
		{
		func_dial.hpcheck(enemy);
		}
		}else if(roll >=4 && roll <=6){
		cout << "Your nasty curse made your opponent reflect opon his life choices! Giving you 1 extra turn while your enemy questions his existence" << endl;
		for(int i = 0; i<=1; i++)
		{
		func_dial.hpcheck(enemy);
		}
		}else if(roll <=3){
		cout << "Your nasty curse backfired causing you to miss your opportunity to attack!" << endl;
	}
}
	

void character::hpcheck(character &foe)
{
combat func_call;
	
	
	int i;	
	cout << "\n Which spell would you like to use?\n";
	cout << "Type(1): Fireblast\n Type(2): Kick and scream\n Type(3): Unfair Nasty Curse" << endl;
	cin >> i;
	if (i <= 1){
		func_call.fireblast(foe);
  	}else if (i <= 2){
		func_call.kicknscream(foe);
	}else if (i <=3){
		func_call.nastycurse(foe);
	}
}

int main(){
interac end_call;
combat func_call;
character foe;
character hp_check;
character player;
	cout << "You've encountered the chad of chads minding his own business, you are a weak mage with an inferiority complex so you decide to fight him" << endl;
	do
	{	
	player.hpcheck(player);
	cout << "ENEMY ATTACKING" << endl;
	func_call.some_dmg(foe);
	}while(foe.foe_hp >= 0 && player.foe_hp >= 0);
	end_call.end(foe);

}

#include <iostream>
using namespace std;

class Combat{

	public:
	int hp = 100;
	int dmg;
	void spells();
};

void Combat::spells(){
	cout << "\n Which spell would you like to use?\n";
	cout << "Type in the corresponding key\n";
	cout << "Type(1): Fireblast\n Type(2): Kick and scream\n Type(3): Pyrotorment"
}

int main(){
cout << "\n You've encountered a terrible foe, you're a weak mage and you left your pumped up kicks at home.";
cout << "\n Running is not an option";
Combat::spells();



}
//auto val = (rand() % 10) + 1;

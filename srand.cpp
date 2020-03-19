#include <iostream>
#include <time.h>
#include <stdlib.h> 

using namespace std;

int main(){
	int tal = 0;
	int seed = 4;
	srand(time(NULL));
	cout << time(NULL) << endl;
	cout << "Rulla mellan 1-20 med time som seed, gör detta 10 ggr \n";
	for(int i=0;i<10;i++){
		tal = rand()%19+1;
		cout << tal << " ";
	}
	cout << endl;
	srand(4);
	cout << "Rulla mellan 1-20 med siffra som seed, gör detta 10 ggr \n";
	for(int i=0;i<10;i++){
		tal = rand()%19+1;
		cout << tal << " ";
	}
	cout << endl;



}

#include <iostream>

using namespace std;

int main(){

    string namn[4] = {"tobbe", "Fredrik", "Neo", "Sara"};
    cout << "Nuvarande namn: " << endl;
    //Skriv ut namn:
    for(int i=0; i<4; i++){

            cout << namn[i] << endl;


    }

    // Förändra arrayen

    for(int i=0; i<4; i++){

        cout << "Skriv in namn nummer: " << i+1 << ": ";
        cin >> namn[i];


    }
}

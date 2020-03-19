// factorial calculator
#include <iostream>
#include <unistd.h>

using namespace std;

void wait(int sekunder){
    int mikrosekunder;
    mikrosekunder = sekunder * 1000000;
    usleep(mikrosekunder);
}


int countdown (int a){
    if (a > 0){
        cout << a << endl;
        wait(1);
        return (countdown(a-1));
    }

    else{
        cout << "Take off!";
        return 0;
    }
}


int main ()
{
    int tid = 9;
    countdown(tid);
    return 0;
}


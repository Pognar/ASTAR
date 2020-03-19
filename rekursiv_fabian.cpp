#include <iostream>
#include <string>

using namespace std;

int utrakning=1;

void calculation(int siffra) {

if (siffra>1){
	utrakning*=siffra;
	cout << utrakning << endl;
	calculation(siffra-1);
}
else
{
cout << utrakning << endl;
}
}
int main()
{
	int a=5;
	calculation(a);
}

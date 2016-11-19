#include <iostream>
#include <string.h>

using namespace std;

void hazardloop()
{
		cout<<"\nPlease type H,";
}

void leftloop()
{
		cout<<"\nPlea";
}

void rightloop()
{
		cout<<"\nP";
		cout<<""
}

void WaitforEnter()
{
	char R[] = "R";
	char H[] = "H";
	char L[] = "L";
	char input[5];
    	cin >> input;
	if (!strcmp(input, H))
    		hazardloop();
   	else if (!strcmp(input, R))
    		rightloop();
    	else
    		cout << "Nope man";  

}

int main ()
{
	char* lol;
	cout<<"This is a T Bird Simulation Program";
	cout<<"\nPlease type H, L, or R whenever you see fit as many times as you like.";
	WaitforEnter();
	
	
	
	// Just wait till user input to close.
}

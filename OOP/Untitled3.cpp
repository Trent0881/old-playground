#include <iostream>
#include <string.h>
#include <windows.h>
#define xDim 15
#define yDim 10
using namespace std;


//  MAIN PROGRAM STARTS HERE
int main ()
{
	Sleep(3000);
	cout << "INCOMING!";
	if (GetAsyncKeyState('w'))
	cout << "lol";
	else 
	cout << "Failure";
	Sleep(5000);
		
}


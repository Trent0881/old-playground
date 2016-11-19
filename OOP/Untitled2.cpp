#include <iostream>
#include <string.h>
#include <windows.h>
#define xDim 15
#define yDim 10
using namespace std;

int UpdateScreen(char Screen[yDim][xDim], int currLoc, char codedAction[5])
{
	int currX;
	int currY;
	int temp;
	
          if (GetAsyncKeyState('w'))
			currLoc = currLoc - 1;
     else if (GetAsyncKeyState('a'))
			currLoc = currLoc - 10;
	else if (GetAsyncKeyState('s'))
			currLoc = currLoc + 1;
	else if (GetAsyncKeyState('d'))		
			currLoc = currLoc + 10;
	else
		cout << "lol";
	
	// Interpret currLoc variable
	temp = currLoc;
	currY = temp % 10;  // Isolate the rightmost digit
	while ( (temp % 10) != 0 )
		temp--;
	currX = temp/10;
	temp = 10*currX + currY;
	//cout << "X and Y are: " << currX << " and " << currY;
	if (currX <= 0 || currX >= xDim || currY <= 0 || currY >= yDim)
		cout << "Error type 2 found";
		
	strcpy(&Screen[currY][currX],"X");
	return temp;
}
void PrintScreen(char Screen[yDim][xDim])
{
	cout << "\n\n";
	for (int i = 0; i <= yDim; i++)
	{
		cout << "\n";
		for (int j = 0; j <= xDim; j++)
		{
			cout << Screen[i][j];
		}
	}
	cout << "\n\n";
}
void ResetScreen(char Screen[yDim][xDim] )
{
	for (int i = 0; i <= yDim; i++)
	{
		for (int j = 0; j <= xDim; j++)
		{
			strcpy(&Screen[i][j],"_");
		}
	}	
}

//  MAIN PROGRAM STARTS HERE
int main ()
{

	int currLoc = 36;    // Current location; first digit is xloc, second digit is yloc
	char userInput[5] = "E";
	char Screen[yDim][xDim];
	char e[] = "e";    // User presses 'e' to quit the game
	cout << userInput;
	ResetScreen(Screen);

	while (strcmp(userInput, "e") != 0)
	{
		PrintScreen(Screen);
		currLoc = UpdateScreen(Screen, currLoc, userInput);
		Sleep(1000);
	}
		
		
		
}















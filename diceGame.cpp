#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
	Author : Darren Tam
	Lab Assignment #2
	Purpose : To let the user play the dice game "craps".
		  The dice is rolled automatically for the user and
		  it takes an input 'Y' or 'N' to choose whether or not
		  the player wants to play again.
*/

//Calculating one dice roll.
int diceRoll(){
	int i = rand() % 6 + 1;
	return i;

}

//Calculating the total number of both rolls.
int rollTotal(int i, int j){
	int Roll = 0;
	Roll = i+j;
	cout << "player rolled " << i << " + " << j << " = " << Roll << endl;
	return Roll;
}

void playGame(){
//Defining all variables used
int Roll = 0;
int Point = 0; 
int getout = 0;

//First roll
Roll = rollTotal(diceRoll(), diceRoll());
if (Roll == 2 || Roll == 3 || Roll == 12){
	cout << "player loses" << endl;
}
else if (Roll == 7 || Roll == 11){
	cout << "player wins" << endl;
}
else if (Roll == 4 || Roll == 5 || Roll == 6 || Roll == 8 || Roll == 9 || Roll == 10) { //There was no win or lose on the first roll so we continue
	      //Now we look for the point for a win or a 7 for a loss.
	Point = Roll;
	cout << "point is " << Roll << endl;
	while(!getout){
		Roll = rollTotal(diceRoll(), diceRoll());
		if(Roll == Point){
			cout << "player wins";
			getout = 1;
		}
		else if(Roll == 7){
			cout << "player loses";
			getout = 1;
		}
	}
        cout << endl << endl << endl;

}


}

int main( ) {
  char ans;
  bool done = false;
  while ( !done ) {
         playGame();
         cout << "Play again (y/n) ? ";
         cin >> ans;
         if ( ans == 'n' || ans == 'N') done = true;
             else done = false;
  }
  return 0;
}

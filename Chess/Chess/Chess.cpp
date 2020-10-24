#include <iostream>
#include<string>
#include <Windows.h>
#include <fstream>
#include "Board.h"
#include"Piece.h"
#include "GamePlay.h"

using namespace std;

int main() {



	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 700, TRUE);

	/*string playerOne;
    string playerTwo;
    cout << "Let's play Chess!!!" << endl;
    cout << "Player One please enter your name:";;
    cin >> playerOne;
    cout << "Player Two please enter your name:";;
    cin >> playerTwo;

	
	ofstream file_1;
	file_1.open("PlayerOne.txt");
	if (file_1.is_open())
	{
		file_1 << playerTwo<<" 1 \n";
	}
	ofstream file_2;
	file_2.open("PlayerTwo.txt");
	if (file_2.is_open())
	{
		file_2 << playerOne<<" 1 \n";
	}*/


	GamePlay G;
	G.Game();
	


}
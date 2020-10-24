#include "GamePlay.h"

#include<iostream>


#include <cmath>


using namespace std;


int i, j;
int	k;
char gameField[28][65];

bool CheckMoveFormat(string move) {

	//a valid move has 9 characters
	if (move.length() != 10)
	{
		cout << "INVALIDE MOVE FORMAT!" << endl;
		cout << "Please check the move format and enter your move!" << endl;
		return false;
	}

	//this basically just checkes each of the characters in the 3 sections of the move
	//format to ensure that the user has entered a valid range of inputs
	if (move[2] != 'a' && move[2] != 'b' && move[2] != 'c' && move[2] != 'd' &&
		move[2] != 'e' && move[2] != 'f' && move[2] != 'g' && move[2] != 'h')
	{
		cout << "INVALIDE MOVE FORMAT!" << endl;
		cout << "Please check the move format and enter your move!" << endl;
		return false;
	}

	//make sure the number of the board index is valid	
	if (move[3] != '1' && move[3] != '2' && move[3] != '3' && move[3] != '4' && move[1] != '5'
		&& move[3] != '6' && move[3] != '7' && move[3] != '8')
	{
		cout << "INVALIDE MOVE FORMAT!" << endl;
		cout << "Please check the move format and enter your move!" << endl;
		return false;
	}

	
	if (move[1] != ':' || move[4] != ' ' || move[5] != 't' || move[6] != 'o' || move[7] != ' ')
	{
		cout << "INVALIDE MOVE FORMAT!" << endl;
		cout << "Please check the move format and enter your move!" << endl;
		return false;
	}

	//valid ranger of letters for destination index
	if (move[8] != 'a' && move[8] != 'b' && move[8] != 'c' && move[8] != 'd' && move[8] != 'e'
		&& move[8] != 'f' && move[8] != 'g' && move[8] != 'h')
	{
		cout << "INVALIDE MOVE FORMAT!" << endl;
		cout << "Please check the move format and enter your move!" << endl;
		return false;
	}

	//valid range of numbers for destination index
	if (move[9] != '1' && move[9] != '2' && move[9] != '3' && move[9] != '4' && move[9] != '5'
		&& move[9] != '6' && move[9] != '7' && move[9] != '8')
	{
		return false;
		cout << "INVALIDE MOVE FORMAT!" << endl;
		cout << "Please check the move format and enter your move!" << endl;
	}

	else return true;
}

bool CheckMoveRules(string moveComand, Board board[8][8], int currPlayer)  {

	//converting the income to ints
	int leftLetter;
	int leftNumber;
	int rightLetter;
	int rightNumber;


	if (moveComand[2] == 'a')
		leftLetter = 0;
	else if (moveComand[2] == 'b')
		leftLetter = 1;
	else if (moveComand[2] == 'c')
		leftLetter = 2;
	else if (moveComand[2] == 'd')
		leftLetter = 3;
	else if (moveComand[2] == 'e')
		leftLetter = 4;
	else if (moveComand[2] == 'f')
		leftLetter = 5;
	else if (moveComand[2] == 'g')
		leftLetter = 6;
	else
		leftLetter = 7;


	if (moveComand[8] == 'a')
		rightLetter = 0;
	else if (moveComand[8] == 'b')
		rightLetter = 1;
	else if (moveComand[8] == 'c')
		rightLetter = 2;
	else if (moveComand[8] == 'd')
		rightLetter = 3;
	else if (moveComand[8] == 'e')
		rightLetter = 4;
	else if (moveComand[8] == 'f')
		rightLetter = 5;
	else if (moveComand[8] == 'g')
		rightLetter = 6;
	else
		rightLetter = 7;


	if (moveComand[3] == '1')
		leftNumber = 0;
	else if (moveComand[3] == '2')
		leftNumber = 1;
	else if (moveComand[3] == '3')
		leftNumber = 2;
	else if (moveComand[3] == '4')
		leftNumber = 3;
	else if (moveComand[3] == '5')
		leftNumber = 4;
	else if (moveComand[3] == '6')
		leftNumber = 5;
	else if (moveComand[3] == '7')
		leftNumber = 6;
	else
		leftNumber = 7;


	if (moveComand[9] == '1')
		rightNumber = 0;
	else if (moveComand[9] == '2')
		rightNumber = 1;
	else if (moveComand[9] == '3')
		rightNumber = 2;
	else if (moveComand[9] == '4')
		rightNumber = 3;
	else if (moveComand[9] == '5')
		rightNumber = 4;
	else if (moveComand[9] == '6')
		rightNumber = 5;
	else if (moveComand[9] == '7')
		rightNumber = 6;
	else
		rightNumber = 7;



	if (board[leftNumber][leftLetter].piece == nullptr) {

		cout << "There's no piece at the specified location." << endl << endl;
		return false;

	}

	//checks to see if the piece the player is trying to move is actually theirs (current player must match piece's player)
	if (board[leftNumber][leftLetter].piece != nullptr && currPlayer != board[leftNumber][leftLetter].piece->player) {

		cout << "That's not your piece!" << endl << endl;

		return false;

	}

	//checks to see if the player has a friendly piece at the desired move location
	if (board[rightNumber][rightLetter].piece != nullptr && currPlayer == board[rightNumber][rightLetter].piece->player) {

		cout << "You already have a piece there." << endl << endl;

		return false;
	}

	//X AND Y DIFFERENCES
	int rowDiff = leftNumber - rightNumber;
	int colDiff = leftLetter - rightLetter;
	//IMPORTANT
	//-----------------------------------------------------------------------------------------------------//
	//P2'S PAWN MOVEMENT RULES 
	if (board[leftNumber][leftLetter].piece->name.compare("Pawn") == 0 && currPlayer == 2) {

		//this is to take into account that pawns can move 2 spaces on their first move, but not after
		if (leftNumber != 1 && rowDiff <= -2) {

			cout << "Pawns can't move like that." << endl << endl;
			return false;	//false indicates invalid move.

		}

		//if it is the pawn's first move and they try to move like 12 spaces.
		else if (leftNumber == 1 && rowDiff < -2) {

			cout << "Pawns may move 2 spaces forward their first move." << endl << endl;
			return false;

		}

		//can't go back
		else if (rowDiff >= 0) {

			cout << "Pawns can't move like that." << endl << endl;
			return false;

		}

		//no matter what pawns can only move a maximum of one column over at a time
		else if (abs(colDiff) > 1) {

			cout << "Pawns can't move like that." << endl << endl;
			return false;

		}

		//if they try to move diagonally without there being an enemy piece there
		else if (abs(colDiff) == 1 && rowDiff == -1 && board[rightNumber][rightLetter].piece == nullptr) {

			cout << "There must be an enemy piece on that position for you to move there." << endl << endl;
			return false;

		}

		//if they try to move 1 space forward but there's an enemy there.
		else if (rowDiff == -1 && colDiff == 0 && board[rightNumber][rightLetter].piece != nullptr && board[rightNumber][rightLetter].piece->player == 2) {

			cout << "An enemy piece is blocking your move!" << endl << endl;
			return false;

		}

		//if they try to move diagonally to a space and there's an enemy piece there
		else if (rowDiff == -1 && abs(colDiff) == 1 && board[rightNumber][rightLetter].piece->player == 2) {

			cout << "You have taken the enemy's " << board[rightNumber][rightLetter].piece->name << "!" << endl << endl;

			board[rightNumber][rightLetter].piece = board[leftNumber][leftLetter].piece;	//piece taken
			board[leftNumber][leftLetter].piece = nullptr;

			

			return true;

		}

		//valid forward move with no enemy pieces in the way.
		else {

			cout << "Move successful!" << endl << endl;
			board[rightNumber][rightLetter].piece = board[leftNumber][leftLetter].piece;
			board[leftNumber][leftLetter].piece = nullptr;

			

			return true;

		}
	}

	//P1'S PAWN MOVEMENT RULES 
	else if (board[leftNumber][leftLetter].piece->name.compare("Pawn") == 0 && currPlayer == 1) {

		//this is to take into account that pawns can move 2 spaces on their first move, but not after
		if (leftNumber != 6 && rowDiff >= 2) {

			cout << "Pawns can't move like that." << endl << endl;
			return false;	//false indicates invalid move...just in case I didn't specify that already.

		}

		//if it is the pawn's first move and they try to move like 12 spaces.
		else if (leftNumber == 6 && rowDiff > 2) {

			cout << "Pawns may move not more than 2 spaces forward their first move." << endl << endl;
			return false;

		}

		//rowDiff must ALWAYS be negative...no backwards or side to side movement for pawns
		else if (rowDiff <= 0) {

			cout << "Pawns can't move like that." << endl << endl;
			return false;

		}

		//no matter what pawns can only move a maximum of one column over at a time
		else if (abs(colDiff) > 1) {

			cout << "Pawns can't move like that." << endl << endl;
			return false;

		}

		//if they try to move diagonally without there being an enemy piece there
		else if (abs(colDiff) == 1 && rowDiff == 1 && board[rightNumber][rightLetter].piece == nullptr) {

			cout << "There must be an enemy piece for you to move there." << endl << endl;
			return false;

		}

		//if they try to move 1 space forward but there's an enemy there.
		else if (rowDiff == 1 && colDiff == 0 && board[rightNumber][rightLetter].piece != nullptr && board[rightNumber][rightLetter].piece->player == 1) {

			cout << "An enemy piece is blocking your move!" << endl << endl;
			return false;

		}

		//if they try to move diagonally to a space and there's an enemy piece there.
		else if (rowDiff == 1 && abs(colDiff) == 1 && board[rightNumber][rightLetter].piece->player == 1) {

			cout << "You have taken the enemy's " << board[rightNumber][rightLetter].piece->name << "!" << endl << endl;

			board[rightNumber][rightLetter].piece = board[leftNumber][leftLetter].piece;	//piece taken
			board[leftNumber][leftLetter].piece = nullptr;

			

			return true;

		}

		//valid forward move with no enemy pieces in the way.
		else {

			cout << "Move successful!" << endl << endl;
			board[rightNumber][rightLetter].piece = board[leftNumber][leftLetter].piece;
			board[leftNumber][leftLetter].piece = nullptr;

			

			return true;

		}
	}

	else if (board[leftNumber][leftLetter].piece->name.compare("King") == 0) {

		//if they try to move more than one space at a time.
		if (abs(rowDiff) > 1 || abs(colDiff) > 1) {

			cout << "Kings may only move one space at a time." << endl << endl;
			return false;

		}


		if (board[rightNumber][rightLetter].piece != nullptr && board[rightNumber][rightLetter].piece->player != currPlayer) {

			cout << "You have taken the enemy's " << board[rightNumber][rightLetter].piece->name << "!" << endl << endl;

			board[rightNumber][rightLetter].piece = board[leftNumber][leftLetter].piece;	//piece taken
			board[leftNumber][leftLetter].piece = nullptr;

			

			return true;

		}

		else {

			cout << "Move successful!" << endl << endl;
			board[rightNumber][rightLetter].piece = board[leftNumber][leftLetter].piece;
			board[leftNumber][leftLetter].piece = nullptr;

			

			return true;

		}
	}


	else if (board[leftNumber][leftLetter].piece->name.compare("Queen") == 0) {

		
		//if they just try to move to some random spot
		if (abs(rowDiff) != abs(colDiff) && rowDiff != 0 && colDiff != 0) {

			cout << "Queens can do a lot of things, but they can't apparate." << endl << endl;
			return false;

		}

		//
		if (rowDiff > 0 && colDiff > 0) {

			

			for (int i = leftNumber - 1; i > rightNumber; i--) {
				int a = leftLetter;
				for (a; a > rightLetter; a--) {
					a--;
					if (board[i][a].piece != nullptr) {

						cout << "There's a piece blocking your move!" << endl << endl;
						return false;
					}
					break;
				}
			}
		}

		else if (rowDiff < 0 && colDiff < 0) {

			
			int a = leftLetter;
			for (int i = leftNumber + 1; i < rightNumber; i++) {

				for (a; a < rightLetter; a++) {
					a++;
					if (board[i][a].piece != nullptr) {

						cout << "There's a piece blocking your move!" << endl << endl;
						return false;
					}
					break;
				}
			}
		}

		else if (rowDiff > 0 && colDiff < 0) {

			
			int a = leftLetter;
			for (int i = leftNumber - 1; i > rightNumber; i--) {
				a++;
				for (a; a < rightLetter; a++) {

					if (board[i][a].piece != nullptr)
					{
						cout << "There's a piece blocking your move!" << endl << endl;
						return false;
					}
					break;
				}
			}
		}

		else if (rowDiff < 0 && colDiff > 0) {

			
			int a = leftNumber;
			for (int i = leftNumber + 1; i < rightNumber; i++) {

				for (a; a > rightLetter; a--) {
					a--;
					if (board[i][a].piece != nullptr) {

						cout << "There's a piece blocking your move!" << endl << endl;
						return false;

					}
				}
			}
		}

		else if (rowDiff == 0 && colDiff > 0) {

			

			for (int i = leftLetter - 1; i >= rightLetter; i--) {

				if (board[leftNumber][i].piece != nullptr) {

					cout << "There's a piece blocking your move!" << endl << endl;
					return false;

				}
			}
		}

		else if (rowDiff == 0 && colDiff < 0) {

			

			for (int i = leftLetter + 1; i < rightLetter; i++) {

				if (board[leftNumber][i].piece != nullptr) {

					cout << "There's a piece blocking your move!" << endl << endl;
					return false;

				}
			}
		}

		else if (rowDiff > 0 && colDiff == 0) {

			

			for (int i = leftNumber - 1; i > rightNumber; i--) {

				if (board[i][leftLetter].piece != nullptr) {

					cout << "There's a piece blocking your move!" << endl << endl;
					return false;

				}
			}
		}

		else if (rowDiff < 0 && colDiff == 0) {

			

			for (int i = leftNumber + 1; i < rightNumber; i++) {

				if (board[i][leftLetter].piece != nullptr) {

					cout << "There's a piece blocking your move!" << endl << endl;
					return false;

				}
			}
		}

		


		if (board[rightNumber][rightLetter].piece != nullptr && board[rightNumber][rightLetter].piece->player != currPlayer) {

			cout << "You have taken the enemy's " << board[rightNumber][rightLetter].piece->name << "!" << endl << endl;

			board[rightNumber][rightLetter].piece = board[leftNumber][leftLetter].piece;	//piece taken
			board[leftNumber][leftLetter].piece = nullptr;


			return true;

		}

		else {

				cout << "Move successful!" << endl << endl;
				board[rightNumber][rightLetter].piece = board[leftNumber][leftLetter].piece;
				board[leftNumber][leftLetter].piece = nullptr;


				return true;

			}
	}

	else if (board[leftNumber][leftLetter].piece->name.compare("Knight") == 0) {

		
		if (abs(rowDiff) * abs(colDiff) != 2) {

			cout << "Knights can't move like that." << endl << endl;
			return false;


		}

		if (board[rightNumber][rightLetter].piece != nullptr && board[rightNumber][rightLetter].piece->player != currPlayer) {

			cout << "You have taken the enemy's " << board[rightNumber][rightLetter].piece->name << "!" << endl << endl;

			board[rightNumber][rightLetter].piece = board[leftNumber][leftLetter].piece;	//piece taken
			board[leftNumber][leftLetter].piece = nullptr;

			

			return true;

		}

		else {

			cout << "Move successful!" << endl << endl;
			board[rightNumber][rightLetter].piece = board[leftNumber][leftLetter].piece;
			board[leftNumber][leftLetter].piece = nullptr;

			

			return true;

		}
	}

	else if (board[leftNumber][leftLetter].piece->name.compare("Bishop") == 0) {

		//just specifying diagonal movmement only
		if (abs(rowDiff) != abs(colDiff)) {

			cout << "Bishops can't move like that." << endl;
			return false;

		}

		
		if (rowDiff > 0 && colDiff > 0) {
			int a = leftLetter;
			for (int i = leftNumber - 1; i > rightNumber; i--) {
				
				for (a; a > rightLetter; a--) {
					a--;
					if (board[i][a].piece != nullptr) {

						cout << "There's a piece blocking your move!" << endl << endl;
						return false;
					}
					break;
				}
			}
		}

		else if (rowDiff < 0 && colDiff < 0) {
			int a = leftLetter;
			for (int i = leftNumber + 1; i < rightNumber; i++) {

				for (a; a < rightLetter; a++) {
					a++;
					if (board[i][a].piece != nullptr) {

						cout << "There's a piece blocking your move!" << endl << endl;
						return false;
					}
					break;
				}
			}
		}

		else if (rowDiff > 0 && colDiff < 0) {
			int a = leftLetter;
			for (int i = leftNumber - 1; i > rightNumber; i--) {

				for (a; a < rightLetter; a++) {
					a++;
					if (board[i][a].piece != nullptr) {

						cout << "There's a piece blocking your move!" << endl << endl;
						return false;
					}
					break;
				}
			}
		}

		else if (rowDiff < 0 && colDiff > 0) {
			int a = leftLetter;
			for (int i = leftNumber + 1; i < rightNumber; i++) {

				for (a; a > rightLetter; a--) {
					a--;
					if (board[i][a].piece != nullptr) {

						cout << "There's a piece blocking your move!" << endl << endl;
						return false;
					}
					break;
				}
			}
		}

		//STANDARD PIECE TAKING CODE (SAME FOR ALL PIECES FOR P1)
		if (board[rightNumber][rightLetter].piece != nullptr && board[rightNumber][rightLetter].piece->player != currPlayer) {

			cout << "You have taken the enemy's " << board[rightNumber][rightLetter].piece->name << "!" << endl << endl;

			board[rightNumber][rightLetter].piece = board[leftNumber][leftLetter].piece;	//piece taken
			board[leftNumber][leftLetter].piece = nullptr;

			

			return true;


		}

		else {

			cout << "Move successful!" << endl << endl;
			board[rightNumber][rightLetter].piece = board[leftNumber][leftLetter].piece;
			board[leftNumber][leftLetter].piece = nullptr;

			

			return true;


		}
	}

	else if (board[leftNumber][leftLetter].piece->name.compare("Rook") == 0) {

		if (rowDiff != 0 && colDiff != 0) {

			cout << "Rooks can't move like that." << endl << endl;
			return false;

		}

		
		if (rowDiff == 0 && colDiff > 0) {

			for (int i = leftLetter - 1; i > rightLetter; i--) {

				if (board[leftNumber][i].piece != nullptr) {

					cout << "There's a piece blocking your move!" << endl << endl;
					return false;

				}
			}
		}

		else if (rowDiff == 0 && colDiff < 0) {

			for (int i = leftLetter + 1; i < rightLetter; i++) {

				if (board[leftNumber][i].piece != nullptr) {

					cout << "There's a piece blocking your move!" << endl << endl;
					return false;

				}
			}
		}

		else if (rowDiff > 0 && colDiff == 0) {

			for (int i = leftNumber - 1; i > rightNumber; i--) {

				if (board[i][leftLetter].piece != nullptr) {

					cout << "There's a piece blocking your move!" << endl << endl;
					return false;

				}
			}
		}

		else if (rowDiff < 0 && colDiff == 0) {

			for (int i = leftNumber + 1; i < rightNumber; i++) {

				if (board[i][leftLetter].piece != nullptr) {

					cout << "There's a piece blocking your move!" << endl << endl;
					return false;

				}
			}
		}

		if (board[rightNumber][rightLetter].piece != nullptr && board[rightNumber][rightLetter].piece->player != currPlayer) {

			cout << "You have taken the enemy's " << board[rightNumber][rightLetter].piece->name << "!" << endl << endl;

			board[rightNumber][rightLetter].piece = board[leftNumber][leftLetter].piece;	//piece taken
			board[leftNumber][leftLetter].piece = nullptr;

			

			return true;

		}

		else {

			cout << "Move successful!" << endl << endl;
			board[rightNumber][rightLetter].piece = board[leftNumber][leftLetter].piece;
			board[leftNumber][leftLetter].piece = nullptr;


			return true;


		}
	}

	else return false;

}
void FillingTheBoard()
{
	//filling this matrix 
	for (i = 0; i < 28; i++)

	{
		for (j = 0; j < 65; j++)
		{
			gameField[i][j] = ' ';
		}
	}
}
void PaintingGameField()
{
	//painting the board
	for (i = 3; i < 27; i++)
	{
		for (j = 7; j < 63; j++)
		{
			if ((((i > 2 && i < 6) || (i > 8 && i < 12) || (i > 14 && i < 18) || (i > 20 && i < 24))
				&& ((j > 6 && j < 14) || (j > 20 && j < 28) || (j > 34 && j < 42) || (j > 48 && j < 56))) ||
				(((i > 5 && i < 9) || (i > 11 && i < 15) || (i > 17 && i < 21) || (i > 23 && i < 27))
					&& ((j > 13 && j < 21) || (j > 27 && j < 35) || (j > 41 && j < 49) || (j > 55 && j < 63))))
				gameField[i][j] = 219;
		}
	}
}
void PrintBorders() {
	for (i = 3; i < 27; i++)
	{
		gameField[i][5] = 186;
		gameField[i][64] = 186;
	}
	gameField[2][5] = 201;
	gameField[2][64] = 187;
	gameField[27][64] = 188;
	gameField[27][5] = 200;
	for (j = 6; j < 64; j++)
	{
		gameField[2][j] = 205;
		gameField[27][j] = 205;
	}
}
void PrintNumbering()
{
	k = 0;
	//colom nameing
	for (j = 10; j < 63; j += 7)
	{
		gameField[1][j] = 65 + k;
		k++;
	}
	//line numbering
	for (i = 4; i < 27; i += 3)
	{
		{
			gameField[i][3] = 41 + k;
			k++;
		}
	}
}
void FigureSpaceCleaning()
{
	//freeing space for figures
	for (i = 4; i < 27; i += 3)
	{
		for (j = 10; j < 63; j += 7)
		{
			gameField[i][j - 1] = '  ';
			gameField[i][j] = '  ';
			gameField[i][j + 1] = '  ';
		}
	}
}
void PiecesPlacingAndPrint(Board board[8][8])
{
	//Taking the coordinats of where pieces will be placed
	const int R1 = 4; 				const int C1 = 10;
	const int R2 = 7;				const int C2 = 17;
	const int R3 = 10;				const int C3 = 24;
	const int R4 = 13;				const int C4 = 31;
	const int R5 = 16;				const int C5 = 38;
	const int R6 = 19;				const int C6 = 45;
	const int R7 = 22;				const int C7 = 52;
	const int R8 = 25;				const int C8 = 59;

	int row, col;

	for (int i = 0; i < 8; i++)
	{
		if (i == 0)row = R1;
		else if (i == 1)row = R2;
		else if (i == 2)row = R3;
		else if (i == 3)row = R4;
		else if (i == 4)row = R5;
		else if (i == 5)row = R6;
		else if (i == 6)row = R7;
		else if (i == 7)row = R8;
		for (int j = 0; j < 8; j++)
		{
			if (j == 0)col = C1;
			else if (j == 1)col = C2;
			else if (j == 2)col = C3;
			else if (j == 3)col = C4;
			else if (j == 4)col = C5;
			else if (j == 5)col = C6;
			else if (j == 6)col = C7;
			else if (j == 7)col = C8;


			if (board[i][j].piece == nullptr) gameField[row][col] = ' ';
			else if (board[i][j].piece->name == "Pawn" && board[i][j].piece->player == 1) gameField[row][col] = 'P';
			else if (board[i][j].piece->name == "King" && board[i][j].piece->player == 1) gameField[row][col] = 'K';
			else if (board[i][j].piece->name == "Queen" && board[i][j].piece->player == 1) gameField[row][col] = 'Q';
			else if (board[i][j].piece->name == "Rook" && board[i][j].piece->player == 1) gameField[row][col] = 'R';
			else if (board[i][j].piece->name == "Knight" && board[i][j].piece->player == 1) gameField[row][col] = 'N';
			else if (board[i][j].piece->name == "Bishop" && board[i][j].piece->player == 1) gameField[row][col] = 'B';
			else if (board[i][j].piece->name == "Pawn" && board[i][j].piece->player == 2) gameField[row][col] = 'p';
			else if (board[i][j].piece->name == "King" && board[i][j].piece->player == 2) gameField[row][col] = 'k';
			else if (board[i][j].piece->name == "Queen" && board[i][j].piece->player == 2) gameField[row][col] = 'q';
			else if (board[i][j].piece->name == "Rook" && board[i][j].piece->player == 2) gameField[row][col] = 'r';
			else if (board[i][j].piece->name == "Knight" && board[i][j].piece->player == 2) gameField[row][col] = 'n';
			else if (board[i][j].piece->name == "Bishop" && board[i][j].piece->player == 2) gameField[row][col] = 'b';


		}
	}
	//printing the board
	for (i = 0; i < 28; i++)
	{
		for (j = 0; j < 65; j++)
		{
			cout << gameField[i][j];
		}
		cout << endl;
	}
}
void PrintGameField(Board board[8][8])
{
	FillingTheBoard();
	PrintNumbering();
	PaintingGameField();
	FigureSpaceCleaning();
	PrintBorders();
	PiecesPlacingAndPrint(board);
}


GamePlay::GamePlay()
{
}



GamePlay::~GamePlay()
{
}


void GamePlay::Game()
{

	WhiteKing wK("King", 1);				  		BlackKing bK("King", 2);
	WhiteQueen wQ("Queen", 1);			  			BlackQueen bQ("Queen", 2);
	WhiteRook wR1("Rook", 1);				  		BlackRook bR1("Rook", 2);
	WhiteRook wR2("Rook", 1);				  		BlackRook bR2("Rook", 2);
	WhiteBishop wB1("Bishop", 1);			  		BlackBishop bB1("Bishop", 2);
	WhiteBishop wB2("Bishop", 1);			  		BlackBishop bB2("Bishop", 2);
	WhiteKnight wN1("Knight", 1);			  		BlackKnight bN1("Knight", 2);
	WhiteKnight wN2("Knight", 1);			  		BlackKnight bN2("Knight", 2);
	WhitePawn wP1("Pawn", 1);				  		BlackPawn bP1("Pawn", 2);
	WhitePawn wP2("Pawn", 1);				  		BlackPawn bP2("Pawn", 2);
	WhitePawn wP3("Pawn", 1);				  		BlackPawn bP3("Pawn", 2);
	WhitePawn wP4("Pawn", 1);				  		BlackPawn bP4("Pawn", 2);
	WhitePawn wP5("Pawn", 1);				  		BlackPawn bP5("Pawn", 2);
	WhitePawn wP6("Pawn", 1);				  		BlackPawn bP6("Pawn", 2);
	WhitePawn wP7("Pawn", 1);				  		BlackPawn bP7("Pawn", 2);
	WhitePawn wP8("Pawn", 1);				  		BlackPawn bP8("Pawn", 2);
	//placing the player1 pieces on the board	 //placing the player2 pieces on the board
	board[0][0].piece = &bR1;					 board[7][0].piece = &wR1;
	board[0][1].piece = &bN1;					 board[7][1].piece = &wN1;
	board[0][2].piece = &bB1;					 board[7][2].piece = &wB1;
	board[0][3].piece = &bQ;					 board[7][3].piece = &wQ;
	board[0][4].piece = &bK;					 board[7][4].piece = &wK;
	board[0][5].piece = &bB2;     				 board[7][5].piece = &wB2;
	board[0][6].piece = &bN2;					 board[7][6].piece = &wN2;
	board[0][7].piece = &bR2;					 board[7][7].piece = &wR2;

	board[1][0].piece = &bP1;					 board[6][0].piece = &wP1;
	board[1][1].piece = &bP2;					 board[6][1].piece = &wP2;
	board[1][2].piece = &bP3;					 board[6][2].piece = &wP3;
	board[1][3].piece = &bP4;					 board[6][3].piece = &wP4;
	board[1][4].piece = &bP5;					 board[6][4].piece = &wP5;
	board[1][5].piece = &bP6;					 board[6][5].piece = &wP6;
	board[1][6].piece = &bP7;					 board[6][6].piece = &wP7;
	board[1][7].piece = &bP8;					 board[6][7].piece = &wP8;

	
	int currPlayer = 2;

	//this indicates each player figures in the filed
	int player1Pieces = 16;	
	int player2Pieces = 16;
// this string will be taken from the player who is on turn
	string moveComand;
	
	cout << "Lets play Chess!!!" << endl;
	cout << "Every player has to write a valid form of comand" << endl;
	cout << "It should look like this example:" << endl;
	cout << "P:a1 to b7"<<endl
		<<"Here the first letter stands for the name of the figure  " << endl
		<< "and 'a1' & 'b7' are the position on wich the figure is"<<endl
		<<"and the position where we want it to go" << endl << endl;
	//this loop will work till the end of the game
	while (true)
	{
		//after every valid move we will change Current player
		if (currPlayer == 1)
			currPlayer = 2;
		else
			currPlayer = 1;


		PrintGameField(board);

		cout << endl << endl;
		cout << "It is Player " << currPlayer<< " turn. Please enter your move:" << endl;
		getline(cin, moveComand);
		// the player will enter string with the following format
		//'<Piece_name> <column_name><roll_name> to <column_name><roll_name>'
		//p:a5 to c7
		
		while (CheckMoveFormat(moveComand) == false)
		{
			getline(cin, moveComand);
		}
		while (CheckMoveRules(moveComand,board, currPlayer) == false)
		{
			cout << "Please re-enter your move." << endl;
			getline(cin, moveComand);
		}
		

	}

}


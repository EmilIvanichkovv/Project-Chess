#pragma once
#include "Board.h"

#include "WhitePawn.h"
#include "WhiteBishop.h"
#include "WhiteKing.h"
#include "WhiteKnight.h"
#include "WhiteRook.h"
#include "WhiteQueen.h"


#include "BlackPawn.h"
#include "BlackBishop.h"
#include "BlackKing.h"
#include "BlackKnight.h"
#include "BlackRook.h"
#include "BlackQueen.h"


class GamePlay
{
public:
	Board board[8][8];

	GamePlay();

	~GamePlay();
	 void Game();
	// void TestPrint(Board board[8][8]);
};   

//p:a5 to c7
//0123456789
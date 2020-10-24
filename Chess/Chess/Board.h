#pragma once
#include "Piece.h"
class Board
{
public:
	Board();
	~Board();

	Piece* piece;	//pointer to piece on the square. 
	
	Board(Piece*);
	
};


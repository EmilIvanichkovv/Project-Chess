#include "Board.h"


Board::Board()
{
	piece = nullptr;	
}

Board::Board(Piece* piece)
{
	this->piece = piece;
}

Board::~Board()
{

}

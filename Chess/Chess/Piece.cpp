#include "Piece.h"



Piece::Piece()
{
	name = "";
	player = 0;
}
Piece::Piece(string name, int player)
{
	this->name = name;
	this->player = player;
}


Piece::~Piece()
{

}

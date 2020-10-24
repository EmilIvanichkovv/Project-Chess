#pragma once
#include "Piece.h"
class BlackQueen :public Piece
{
public:
	BlackQueen() :Piece() {}
	BlackQueen(string name, int player)
		:Piece(name, player) {}
};
#pragma once
#pragma once
#include "Piece.h"
class BlackKing :public Piece
{
public:
	BlackKing() :Piece() {}
	BlackKing(string name, int player)
		:Piece(name, player) {}
};
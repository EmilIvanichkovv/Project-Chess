#pragma once
#include "Piece.h"
class BlackKnight :public Piece
{
public:
	BlackKnight() :Piece() {}
	BlackKnight(string name, int player)
		:Piece(name, player) {}
};
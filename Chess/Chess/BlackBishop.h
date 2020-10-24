#pragma once
#include "Piece.h"
class BlackBishop :public Piece
{
public:
	BlackBishop() :Piece() {}
	BlackBishop(string name, int player)
		:Piece(name, player) {}
};
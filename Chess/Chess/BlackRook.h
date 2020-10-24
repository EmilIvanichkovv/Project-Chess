#pragma once
#include "Piece.h"
class BlackRook :public Piece
{
public:
	BlackRook() :Piece() {}
	BlackRook(string name, int player)
		:Piece(name, player) {}
};
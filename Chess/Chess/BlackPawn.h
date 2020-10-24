#pragma once
#include "Piece.h"

class BlackPawn :public Piece
{
public:
	BlackPawn() :Piece() {}
	BlackPawn(string name, int player)
		:Piece(name, player) {}

};
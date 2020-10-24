#pragma once
#include <string>
using namespace std;


class Piece
{
public:
	string name;
	int player;

	Piece();
	Piece(string name, int player);
	~Piece();
};


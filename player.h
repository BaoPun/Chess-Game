#ifndef PLAYERH
#define PLAYERH

#include "./pawn.h"
#include "./rook.h"
#include "./bishop.h"
#include "./knight.h"
#include "./queen.h"
#include "./king.h"

class Player{
	private:
		Pawn pawn;
		Rook rook;
		Bishop bishop;
		Knight knight;
		Queen queen;
		King king;
	public:
		Player();

};

#endif

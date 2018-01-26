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
		Pawn initializePawn(int, int, int, char); //all the pieces' parameters: player #, x coordinate, y coordinate, character representation
		Rook initializeRook(int, int, int, char);
		Bishop initializeBishop(int, int, int, char);
		Knight initializeKnight(int, int, int, char);
		Queen initializeQueen(int, int, int, char);
		King initializeKing(int, int, int, char);
};

#endif

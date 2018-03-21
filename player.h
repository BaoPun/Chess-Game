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
		Pawn pawn[8];
		Rook rook[2];
		Bishop bishop[2];
		Knight knight[2];
		Queen queen;
		King king;
	public:
		Player();
		Pawn initializePawn(int, int, int, int, char); //all the pieces' parameters: piece id #, player #, x coordinate, y coordinate, character representation
		Rook initializeRook(int, int, int, int, char);
		Bishop initializeBishop(int, int, int, int, char);
		Knight initializeKnight(int, int, int, int, char);
		Queen initializeQueen(int, int, int, char);
		King initializeKing(int, int, int, char);
		bool pawnFirstMove(int); //based on the id of the pawn, determine if the pawn has made its move yet
		void changeFirstStatus(int);
		int getCastleStatus();
		void changeCastleStatus();
		int getCheckStatus();
		void changeCheckStatus(bool);
};

#endif

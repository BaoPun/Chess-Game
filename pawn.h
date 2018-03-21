#ifndef PAWNH
#define PAWNH

#include "./piece.h"

class Pawn : public Piece{
	private:
		bool first; //indicates if pawn made its first move yet
	public:
		Pawn(); //4 arguments: 'P', x coordinate, y coordinate, player
		bool firstMove();  //get pawn's current location on the board, check if it matches its starting coordinate
		void changeFirstStatus();
	
};

#endif

#ifndef PAWNH
#define PAWNH

#include "./piece.h"

class Pawn : public Piece{
	private:
		bool first; //indicates if pawn made its first move yet
		int firstX, firstY; //record a pawn's first coordinates 
	public:
		Pawn(); //4 arguments: 'P', x coordinate, y coordinate, player
		void initializeX(int); //after setting the x coordinate for the first time, record it (one time use)
		void initializeY(int); //after setting the y coordinate for the first time, record it (one time use)
		bool firstMove(int, int);  //get pawn's current location on the board, check if it matches its starting coordinate
	
};

#endif

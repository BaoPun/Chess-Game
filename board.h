#ifndef BOARDH
#define BOARDH

#include "./player.h"

class Board{
	private:
		Piece chessboard[8][8]; //static 2d array of chess board, which is 8x8
		Player player[2]; //2 players
	public:
		Board(); //constructor sets up the board with all the pieces
		void displayBoard();
	
};

#endif

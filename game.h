#ifndef CHESSH
#define CHESSH

#include "./board.h"

class Game{
	private:
		Board chess;
		Player player[2]; //refactor the players in here, instead of in class Board.
	public:
		Game();
		void displayBoard();
		bool movePawn(int, int, int, int, int);
		bool moveKing(int, int, int, int, int);
		int firstTurn();		
		void play();

};

#endif

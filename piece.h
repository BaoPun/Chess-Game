#ifndef PIECEH
#define PIECEH

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

class Piece{
	
	private:
		char piece; //identifying the piece on the board
		int x, y; //coordinates of the piece
		int player; //the piece of the player (1 or 2)
	public:
		Piece();
		int getHorizontal();
		int getVertical();
		void setImage(char);
		void setHorizontal(int);
		void setVertical(int);
		void setPlayer(int);
};

#endif
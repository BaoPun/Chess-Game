#ifndef PIECEH
#define PIECEH

#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

class Piece{
	
	private:
		char piece; //identifying the piece on the board
		int x, y; //coordinates of the piece
		int player; //the piece of the player (1 or 2)
		int ID; //for pawns, rooks, bishops, and knights, by #
	public:
		Piece();
		int getHorizontal();
		int getVertical();
		char getImage();
		int getPlayer();
		int getID();
		void setImage(char);
		void setHorizontal(int);
		void setVertical(int);
		void setPlayer(int);
		void setID(int);
};

#endif
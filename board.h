#ifndef BOARDH
#define BOARDH

#include "./player.h"

class Board{
	private:
		Piece chessboard[8][8]; //static 2d array of chess board, which is 8x8
	public:
		Board(); //constructor sets up the board with all the pieces
		void setBoardArea(Piece, int, int);
		void displayBoard();
		bool chooseValidPiece(int, int, int); //piece belongs to the player 
		bool checkValidMovement(int, int, int); //selected piece from chooseValidPiece() can move	
		
		bool pawnCanMove(int, int, int);
		bool rookCanMove(int, int, int);
		bool knightCanMove(int, int, int);
		bool bishopCanMove(int, int, int);
		bool queenCanMove(int, int, int);
		bool kingCanMove(int, int, int);
		
		int getPieceID(int, int);
		int getPieceOfPlayer(int, int);
		char getChessPiece(int, int);
		bool moveRook(int, int, int, int);
		bool moveBishop(int, int, int, int);
		bool moveKnight(int, int, int, int, int); //same thing as knightCanMove
		bool moveQueen(int, int, int, int);
		bool moveKing(int, int, int, int);
		
		void movePiece(int, int, int, int);
		void capturePiece(int, int, int, int);
		
};

#endif

#ifndef KINGH
#define KINGH

#include "./piece.h"

class King : public Piece{
	private:
		int check, castle;
	public:
		King();
		int getCastleStatus();
		int getCheckStatus();
		void changeCastle();
		void changeCheck(bool);
};

#endif

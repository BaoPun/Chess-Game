#include "./pawn.h"

Pawn::Pawn(){
	
}

void Pawn::initializeX(){
	x = firstX;
}

void Pawn::initializeY(){
	y = firstY;
}

bool Pawn::firstMove(int a, int b){
	return (firstX == a && firstY == b);
}
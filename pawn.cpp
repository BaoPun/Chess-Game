#include "./pawn.h"

Pawn::Pawn(){
	first = false; //initially set to false, make it true once pawn makes move
}

void Pawn::initializeX(int a){
	firstX = a;
}

void Pawn::initializeY(int b){
	firstY = b;
}

bool Pawn::firstMove(int a, int b){
	return (firstX == a && firstY == b);
}
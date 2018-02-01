#include "./pawn.h"

Pawn::Pawn(){
	first = false; //initially set to false, make it true once pawn makes move
}

bool Pawn::firstMove(){
	return (first == false);
}

void Pawn::changeFirstStatus(){
	first = true;
}
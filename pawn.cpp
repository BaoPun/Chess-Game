#include "./pawn.h"

Pawn::Pawn(){
	first = false; //initially set to false, make it true once pawn makes move
}

bool Pawn::firstMove(){
	if(first == false){ //if the pawn hasn't made its first move, now change first to true and return true
		first = true;
		return first;
	}
	return false;
}
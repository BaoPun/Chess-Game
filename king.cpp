#include "./king.h"

King::King(){
	check = 0; //if set to 1, then the king is in a state of check
	castle = 0; //if set to 1, then the king has performed a castle already
}

int King::getCastleStatus(){
	return castle;
}

int King::getCheckStatus(){
	return check;
}

void King::changeCastle(){
	castle = 1;
}

void King::changeCheck(bool b){
	/*if(b)
		check = 1;
	else
		check = 0;*/
	check = (b == true) ? 1 : 0; //equivalent to if/else statement: says to assign check equal to either 1 or 0, depending if parameter b IS true. if b true, check = 1, else check = 0 
}
#include "./piece.h"

Piece::Piece(){
	piece = ' ';
	x = 0;
	y = 0;
}

int Piece::getHorizontal(){
	return x;
}

int Piece::getVertical(){
	return y;
}

void Piece::setImage(char p){
	piece = p;
}

void Piece::setHorizontal(int i){
	x = i;
}

void Piece::setVertical(int j){
	y = j;
}

void Piece::setPlayer(int p){
	player = p;
}


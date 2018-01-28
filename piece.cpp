#include "./piece.h"

Piece::Piece(){
	piece = '_';
	x = -1;
	y = -1;
	player = 0;
	ID = 0;
}

char Piece::getImage(){
	return piece;
}

int Piece::getHorizontal(){
	return x;
}

int Piece::getVertical(){
	return y;
}

int Piece::getPlayer(){
	return player;
}

int Piece::getID(){
	return ID;
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

void Piece::setID(int i){
	ID = i;
}

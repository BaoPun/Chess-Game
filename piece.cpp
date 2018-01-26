#include "./piece.h"

Piece::Piece(){
	piece = '_';
	x = 0;
	y = 0;
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


#include "./player.h"

Player::Player(){

}

Pawn Player::initializePawn(int p, int x, int y, char i){
	pawn.setPlayer(p);
	pawn.setHorizontal(x);
	pawn.setVertical(y);
	pawn.setImage(i);
	return pawn;
}

Rook Player::initializeRook(int p, int x, int y, char i){
	rook.setPlayer(p);
	rook.setHorizontal(x);
	rook.setVertical(y);
	rook.setImage(i);
	return rook;
}

Bishop Player::initializeBishop(int p, int x, int y, char i){
	bishop.setPlayer(p);
	bishop.setHorizontal(x);
	bishop.setVertical(y);
	bishop.setImage(i);
	return bishop;
}

Knight Player::initializeKnight(int p, int x, int y, char i){
	knight.setPlayer(p);
	knight.setHorizontal(x);
	knight.setVertical(y);
	knight.setImage(i);
	return knight;
}

Queen Player::initializeQueen(int p, int x, int y, char i){
	queen.setPlayer(p);
	queen.setHorizontal(x);
	queen.setVertical(y);
	queen.setImage(i);
	return queen;
}

King Player::initializeKing(int p, int x, int y, char i){
	king.setPlayer(p);
	king.setHorizontal(x);
	king.setVertical(y);
	king.setImage(i);
	return king;
}

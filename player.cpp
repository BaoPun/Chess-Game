#include "./player.h"

Player::Player(){

}

Pawn Player::initializePawn(int k, int p, int x, int y, char i){
	pawn[k].setPlayer(p);
	pawn[k].setHorizontal(x);
	pawn[k].setVertical(y);
	pawn[k].setImage(i);
	pawn[k].setID(k + 1);
	return pawn[k];
}

Rook Player::initializeRook(int k, int p, int x, int y, char i){
	rook[k].setPlayer(p);
	rook[k].setHorizontal(x);
	rook[k].setVertical(y);
	rook[k].setImage(i);
	return rook[k];
}

Bishop Player::initializeBishop(int k, int p, int x, int y, char i){
	bishop[k].setPlayer(p);
	bishop[k].setHorizontal(x);
	bishop[k].setVertical(y);
	bishop[k].setImage(i);
	return bishop[k];
}

Knight Player::initializeKnight(int k, int p, int x, int y, char i){
	knight[k].setPlayer(p);
	knight[k].setHorizontal(x);
	knight[k].setVertical(y);
	knight[k].setImage(i);
	return knight[k];
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

bool Player::pawnFirstMove(int i){
	return pawn[i - 1].firstMove();
}

void Player::changeFirstStatus(int i){
	pawn[i - 1].changeFirstStatus();
}

int Player::getCastleStatus(){
	return king.getCastleStatus();
}


void Player::changeCastleStatus(){
	king.changeCastle();
}


int Player::getCheckStatus(){
	return king.getCheckStatus();
}


void Player::changeCheckStatus(bool){
	
}


#include "./game.h"

int main(){
	srand((unsigned int)time(NULL));
	cout << "Welcome to Bao Phung's C++ version of Chess" << endl;
	
	Game chess;
	chess.play();
	
	return 0;
}
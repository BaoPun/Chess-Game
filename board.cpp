#include "./board.h"

Board::Board(){
	//rest of the board:
	for(int i = 2; i < 6; i++){
		for(int j = 0; j < 8; j++){
			chessboard[i][j].setPlayer(0);
			chessboard[i][j].setImage('_');
			chessboard[i][j].setHorizontal(i);
			chessboard[i][j].setVertical(j);
			chessboard[i][j].setID(0);
		}
	}
}

void Board::setBoardArea(Piece p, int a, int b){
	chessboard[a][b] = p;
}

void Board::displayBoard(){
	cout << "\n\t\t\t" << "\033[1m\033[31m" << "Displaying the Chess Board" << endl << "\033[0m";
	for(int i = 0; i < 8; i++){
		cout << "\t\t\t";
		for(int j = 0; j < 8; j++){
			cout << "\033[36m";
			if(chessboard[i][j].getImage() == 'P'){
				if(chessboard[i][j].getPlayer() == 1) //player 1
					cout << "[1]";
				else
					cout << "[2]";
			}
			else
				cout << "[" << chessboard[i][j].getImage() << "]";
			cout << "\033[0m";
		}
		cout << endl;
	}
	cout << endl;
}

bool Board::chooseValidPiece(int player, int a, int b){
	return (chessboard[a][b].getPlayer() == player);
}

bool Board::checkValidMovement(int p, int a, int b){
	int pawnID, rookID, bishopID, knightID;
	if(!chooseValidPiece(p, a, b))
		return false;
	else{
		//retrieve the piece that was selected, and then check to see if that piece can move at any valid spot on the map
		char piece = chessboard[a][b].getImage();
		switch(piece){
			case 'P':
				return pawnCanMove(p, a, b);
			case 'R':
				return rookCanMove(p, a, b);
			case 'B':
				return bishopCanMove(p, a, b);
			case 'L':
				return knightCanMove(p, a, b);
			case 'Q':
				return queenCanMove(p, a, b);
			case 'K':
				return queenCanMove(p, a, b);
		}
		return true; 
	}
}

bool Board::pawnCanMove(int p, int a, int b){
	//determine which player is moving the pawn
	if(p == 1){ //player 1
		if(chessboard[a - 1][b].getImage() == '_')
			return true;
		else{
			if(b != 0 && b != 7) //pawn is NOT on edge, check the upper diagonals for the existence of an enemy piece
				return (chessboard[a - 1][b - 1].getPlayer() == 2 || chessboard[a - 1][b + 1].getPlayer() == 2);
			else if(b == 0)
				return (chessboard[a - 1][b + 1].getPlayer() == 2);
			else if(b == 7)
				return (chessboard[a - 1][b - 1].getPlayer() == 2);
			else
				return false;
		}
	}
	else{ //player 2
		if(chessboard[a + 1][b].getImage() == '_')
			return true;
		else{
			if(b != 0 && b != 7) //pawn is NOT on edge, check the upper diagonals for the existence of an enemy piece
				return (chessboard[a + 1][b - 1].getPlayer() == 1 || chessboard[a + 1][b + 1].getPlayer() == 1);
			else if(b == 0)
				return (chessboard[a + 1][b + 1].getPlayer() == 1);
			else if(b == 7)
				return (chessboard[a + 1][b - 1].getPlayer() == 1);
			else
				return false;
		}
	}
}

bool Board::rookCanMove(int p, int a, int b){
	//9 cases: 4 cases on corners, 4 cases on edges not including corners, 1 case anywhere else not mentioned
	//corner locations
	if(a == 0 && b == 0){ //top left 
		//check spot downwards and to the right
		if(chessboard[a + 1][b].getImage() == '_' || chessboard[a][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 1][b].getPlayer() != p || chessboard[a][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 0 && b == 7){ //top right
		//check spot downwards and to the left
		if(chessboard[a + 1][b].getImage() == '_' || chessboard[a][b - 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 1][b].getPlayer() != p || chessboard[a][b - 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 7 && b == 0){ //bottom left
		//check spot upwards and to the right
		if(chessboard[a - 1][b].getImage() == '_' || chessboard[a][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b].getPlayer() != p || chessboard[a][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 7 && b == 7){ //bottom right
		//check spot upwards and to the left
		if(chessboard[a - 1][b].getImage() == '_' || chessboard[a][b - 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b].getPlayer() != p || chessboard[a][b - 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	//on edge (not including corners)
	else if(a == 0){ //somewhere in top edge 
		//check to the left, to the right, and downwards
		if(chessboard[a][b - 1].getImage() == '_' || chessboard[a][b + 1].getImage() == '_' || chessboard[a + 1][b].getImage() == '_')
			return true;
		else{
			if(chessboard[a][b - 1].getPlayer() != p || chessboard[a][b + 1].getPlayer() != p || chessboard[a + 1][b].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 7){ //somewhere in bottom edge
		//check to the left, to the right, and upwards
		if(chessboard[a][b - 1].getImage() == '_' || chessboard[a][b + 1].getImage() == '_' || chessboard[a - 1][b].getImage() == '_')
			return true;
		else{
			if(chessboard[a][b - 1].getPlayer() != p || chessboard[a][b + 1].getPlayer() != p || chessboard[a - 1][b].getPlayer() != p)
				return true;
			return false;
		}
	} 
	else if(b == 0){ //somewhere in left edge
		//check upwards, downwards, and to the right
		if(chessboard[a - 1][b].getImage() == '_' || chessboard[a + 1][b].getImage() == '_' || chessboard[a][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b].getPlayer() != p || chessboard[a + 1][b].getPlayer() != p || chessboard[a][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(b == 7){ //somewhere in right edge
		//check upwards, downwards, and to the left
		if(chessboard[a - 1][b].getImage() == '_' || chessboard[a + 1][b].getImage() == '_' || chessboard[a][b - 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b].getPlayer() != p || chessboard[a + 1][b].getPlayer() != p || chessboard[a][b - 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	//everywhere else
	else{
		//all 4 directions combined
		if(chessboard[a - 1][b].getImage() == '_' || chessboard[a + 1][b].getImage() == '_' || chessboard[a][b - 1].getImage() == '_' || chessboard[a][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b].getPlayer() != p || chessboard[a + 1][b].getPlayer() != p || chessboard[a][b - 1].getPlayer() != p || chessboard[a][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
}

bool Board::knightCanMove(int p, int a, int b){
	//25 possibilities: 4 on corners, 8 on edge pieces adjacent to corners, 4 on edge areas not specified, 4 on piece diagonally adjacent to corners, 4 on inner edge adjacent to the previously checked edge, and 1 case anywhere else
	//corner locations
	if(a == 0 && b == 0){ //top left 
		//check 2 down 1 right and 1 down 2 right
		if(chessboard[a + 2][b + 1].getImage() == '_' || chessboard[a + 1][b + 2].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 2][b + 1].getPlayer() != p || chessboard[a + 1][b + 2].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 0 && b == 7){ //top right
		//check 2 down 1 left and 1 down 2 left
		if(chessboard[a + 2][b - 1].getImage() == '_' || chessboard[a + 1][b - 2].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 2][b - 1].getPlayer() != p || chessboard[a + 1][b - 2].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 7 && b == 0){ //bottom left
		//check 2 up 1 right and 1 up 2 right
		if(chessboard[a - 2][b + 1].getImage() == '_' || chessboard[a - 1][b + 2].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 2][b + 1].getPlayer() != p || chessboard[a - 1][b + 2].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 7 && b == 7){ //bottom right
		//check 2 up 1 left and 1 up 2 left
		if(chessboard[a - 2][b - 1].getImage() == '_' || chessboard[a - 1][b - 2].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 2][b - 1].getPlayer() != p || chessboard[a - 1][b - 2].getPlayer() != p)
				return true;
			return false;
		}
	}
	//adjacent to corner locations
	//top left corner adjacent pieces
	else if(a == 0 && b == 1){
		//check 2 down 1 left, 2 down 1 right, and 1 down 2 right
		if(chessboard[a + 2][b - 1].getImage() == '_' || chessboard[a + 2][b + 1].getImage() == '_' || chessboard[a + 1][b + 2].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 2][b - 1].getPlayer() != p || chessboard[a + 2][b + 1].getPlayer() != p || chessboard[a + 1][b + 2].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 1 && b == 0){
		//check 2 down 1 right, 1 down 2 right, and 1 up 2 right
		if(chessboard[a + 2][b + 1].getImage() == '_' || chessboard[a + 1][b + 2].getImage() == '_' || chessboard[a - 1][b + 2].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 2][b + 1].getPlayer() != p || chessboard[a + 1][b + 2].getPlayer() != p || chessboard[a - 1][b + 2].getPlayer() != p)
				return true;
			return false;
		}
	}
	//top right corner adjacent pieces
	else if(a == 0 && b == 6){
		//check 1 down 2 left, 2 down 1 left, and 2 down 1 right
		if(chessboard[a + 1][b - 2].getImage() == '_' || chessboard[a + 2][b - 1].getImage() == '_' || chessboard[a + 2][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 1][b - 2].getPlayer() != p || chessboard[a + 2][b - 1].getPlayer() != p || chessboard[a + 2][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 1 && b == 7){
		//check 1 up 2 left, 1 down 2 left, and 2 down 1 left
		if(chessboard[a - 1][b - 2].getImage() == '_' || chessboard[a + 1][b - 2].getImage() == '_' || chessboard[a + 2][b - 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b - 2].getPlayer() != p || chessboard[a + 1][b - 2].getPlayer() != p || chessboard[a + 2][b - 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	//bottom left corner adjacent pieces
	else if(a == 6 && b == 0){
		//check 1 down 2 right, 1 up 2 right, and 2 up 1 right
		if(chessboard[a + 1][b + 2].getImage() == '_' || chessboard[a - 1][b + 2].getImage() == '_' || chessboard[a - 2][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 1][b + 2].getPlayer() != p || chessboard[a - 1][b + 2].getPlayer() != p || chessboard[a - 2][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 7 && b == 1){
		//check 1 up 2 right, 2 up 1 right, and 2 up 1 left
		if(chessboard[a - 1][b + 2].getImage() == '_' || chessboard[a - 2][b + 1].getImage() == '_' || chessboard[a - 2][b - 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b + 2].getPlayer() != p || chessboard[a - 2][b + 1].getPlayer() != p || chessboard[a - 2][b - 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	//bottom right corner adjacent pieces
	else if(a == 6 && b == 7){
		//check 1 down 2 left, 1 up 2 left, and 2 up 1 left
		if(chessboard[a + 1][b - 2].getImage() == '_' || chessboard[a - 1][b - 2].getImage() == '_' || chessboard[a - 2][b - 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 1][b - 2].getPlayer() != p || chessboard[a - 1][b - 2].getPlayer() != p || chessboard[a - 2][b - 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 7 && b == 6){
		//check 1 up 2 left, 2 up 1 left, and 2 up 1 right
		if(chessboard[a - 1][b - 2].getImage() == '_' || chessboard[a - 2][b - 1].getImage() == '_' || chessboard[a - 2][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b - 2].getPlayer() != p || chessboard[a - 2][b - 1].getPlayer() != p || chessboard[a - 2][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	//rest of the edge areas 
	else if(a == 0){ //top edge
		//check 1 down 2 left, 1 down 2 right, 2 down 1 left, and 2 down 1 right
		if(chessboard[a + 1][b - 2].getImage() == '_' || chessboard[a + 1][b + 2].getImage() == '_' || chessboard[a + 2][b - 1].getImage() == '_' || chessboard[a + 2][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 1][b - 2].getPlayer() != p || chessboard[a + 1][b + 2].getPlayer() != p || chessboard[a + 2][b - 1].getPlayer() != p || chessboard[a + 2][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 7){ //bottom edge
		//check 1 up 2 left, 1 up 2 right, 2 up 1 left, and 2 up 1 right
		if(chessboard[a - 1][b - 2].getImage() == '_' || chessboard[a - 1][b + 2].getImage() == '_' || chessboard[a - 2][b - 1].getImage() == '_' || chessboard[a - 2][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b - 2].getPlayer() != p || chessboard[a - 1][b + 2].getPlayer() != p || chessboard[a - 2][b - 1].getPlayer() != p || chessboard[a - 2][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(b == 0){ //left edge
		//check 2 down 1 right, 1 down 2 right, 1 up 2 right, and 2 up 1 right
		if(chessboard[a + 2][b + 1].getImage() == '_' || chessboard[a + 1][b + 2].getImage() == '_' || chessboard[a - 1][b + 2].getImage() == '_' || chessboard[a - 2][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 2][b + 1].getPlayer() != p || chessboard[a + 1][b + 2].getPlayer() != p || chessboard[a - 1][b + 2].getPlayer() != p || chessboard[a - 2][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(b == 7){ //right edge
		//check 2 down 1 left, 1 down 2 left, 1 up 2 left, and 2 up 1 left
		if(chessboard[a - 2][b - 1].getImage() == '_' || chessboard[a - 1][b - 2].getImage() == '_' || chessboard[a - 1][b - 2].getImage() == '_' || chessboard[a - 2][b - 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 2][b - 1].getPlayer() != p || chessboard[a - 1][b - 2].getPlayer() != p || chessboard[a - 1][b - 2].getPlayer() != p || chessboard[a - 2][b - 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	//also have to check the square adjacent to the corner and edges and its adjacent edge
	//adjacent corner pieces
	else if(a == 1 && b == 1){ //adjacent top left corner
		//check 2 down 1 left, 2 down 1 right, 1 down 2 right, and 1 up 2 right
		if(chessboard[a + 2][b - 1].getImage() == '_' || chessboard[a + 2][b + 1].getImage() == '_' || chessboard[a + 1][b + 2].getImage() == '_' || chessboard[a - 1][b + 2].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 2][b - 1].getPlayer() != p || chessboard[a + 2][b + 1].getPlayer() != p || chessboard[a + 1][b + 2].getPlayer() != p || chessboard[a - 1][b + 2].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 1 && b == 6){ //adjacent top right corner
		//check 2 down 1 left, 2 down 1 right, 1 down 2 left, and 1 up 2 left
		if(chessboard[a + 2][b - 1].getImage() == '_' || chessboard[a + 2][b + 1].getImage() == '_' || chessboard[a + 1][b - 2].getImage() == '_' || chessboard[a - 1][b - 2].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 2][b - 1].getPlayer() != p || chessboard[a + 2][b + 1].getPlayer() != p || chessboard[a + 1][b - 2].getPlayer() != p || chessboard[a - 1][b - 2].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 6 && b == 1){ //adjacent bottom left corner
		//check 2 up 1 left, 2 up 1 right, 1 up 2 right, and 1 down 2 right
		if(chessboard[a - 2][b - 1].getImage() == '_' || chessboard[a - 2][b + 1].getImage() == '_' || chessboard[a - 1][b + 2].getImage() == '_' || chessboard[a + 1][b + 2].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 2][b - 1].getPlayer() != p || chessboard[a - 2][b + 1].getPlayer() != p || chessboard[a - 1][b + 2].getPlayer() != p || chessboard[a + 1][b + 2].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 6 && b == 6){ //adjacent bottom right corner
		//check 2 up 1 left, 2 up 1 right, 1 up 2 left, and 1 down 2 left
		if(chessboard[a - 2][b - 1].getImage() == '_' || chessboard[a - 2][b + 1].getImage() == '_' || chessboard[a + 1][b - 2].getImage() == '_' || chessboard[a + 1][b - 2].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 2][b - 1].getPlayer() != p || chessboard[a - 2][b + 1].getPlayer() != p || chessboard[a + 1][b - 2].getPlayer() != p || chessboard[a + 1][b - 2].getPlayer() != p)
				return true;
			return false;
		}
	}
	//the adjacent corner's corresponding edge
	else if(a == 1){ //adjacent top 
		//check 1 up 2 left, 1 up 2 right, 1 down 2 left, 1 down 2 right, 2 down 1 left, and 2 down 1 right
		if(chessboard[a - 1][b - 2].getImage() == '_' || chessboard[a - 1][b + 2].getImage() == '_' || chessboard[a + 1][b - 2].getImage() == '_' || chessboard[a + 1][b + 2].getImage() == '_' || chessboard[a + 2][b - 1].getImage() == '_' || chessboard[a + 2][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b - 2].getPlayer() != p || chessboard[a - 1][b + 2].getPlayer() != p || chessboard[a + 1][b - 2].getPlayer() != p || chessboard[a + 1][b + 2].getPlayer() != p || chessboard[a + 2][b - 1].getPlayer() != p || chessboard[a + 2][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 6){ //adjacent bottom
		//check 1 up 2 left, 1 up 2 right, 1 down 2 left, 1 down 2 right, 2 up 1 left, and 2 up 1 right
		if(chessboard[a - 1][b - 2].getImage() == '_' || chessboard[a - 1][b + 2].getImage() == '_' || chessboard[a + 1][b - 2].getImage() == '_' || chessboard[a + 1][b + 2].getImage() == '_' || chessboard[a - 2][b - 1].getImage() == '_' || chessboard[a - 2][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b - 2].getPlayer() != p || chessboard[a - 1][b + 2].getPlayer() != p || chessboard[a + 1][b - 2].getPlayer() != p || chessboard[a + 1][b + 2].getPlayer() != p || chessboard[a - 2][b - 1].getPlayer() != p || chessboard[a - 2][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(b == 1){ //adjacent left
		//check 2 up 1 left, 2 up 1 right, 2 down 1 left, 2 down 1 right, 1 up 2 right, and 1 down 2 right
		if(chessboard[a - 2][b - 1].getImage() == '_' || chessboard[a - 2][b + 1].getImage() == '_' || chessboard[a + 2][b - 1].getImage() == '_' || chessboard[a + 2][b + 1].getImage() == '_' || chessboard[a - 1][b + 2].getImage() == '_' || chessboard[a + 1][b + 2].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 2][b - 1].getPlayer() != p || chessboard[a - 2][b + 1].getPlayer() != p || chessboard[a + 2][b - 1].getPlayer() != p || chessboard[a + 2][b + 1].getPlayer() != p || chessboard[a - 1][b + 2].getPlayer() != p || chessboard[a + 1][b + 2].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(b == 6){ //adjacent right
		//check 2 up 1 left, 2 up 1 right, 2 down 1 left, 2 down 1 right, 1 up 2 left, and 1 down 2 left
		if(chessboard[a - 2][b - 1].getImage() == '_' || chessboard[a - 2][b + 1].getImage() == '_' || chessboard[a + 2][b - 1].getImage() == '_' || chessboard[a + 2][b + 1].getImage() == '_' || chessboard[a - 1][b - 2].getImage() == '_' || chessboard[a + 1][b - 2].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 2][b - 1].getPlayer() != p || chessboard[a - 2][b + 1].getPlayer() != p || chessboard[a + 2][b - 1].getPlayer() != p || chessboard[a + 2][b + 1].getPlayer() != p || chessboard[a - 1][b - 2].getPlayer() != p || chessboard[a + 1][b - 2].getPlayer() != p)
				return true;
			return false;
		}
	}
	//finally, anywhere else
	else{
		//1 up 2 left, 1 up 2 right, 1 down 2 left, 1 down 2 right, 2 down 1 left, 2 down 1 right, 2 up 1 left, and 2 up 1 right
		if(chessboard[a - 1][b - 2].getImage() == '_' || chessboard[a - 1][b + 2].getImage() == '_' || chessboard[a + 1][b - 2].getImage() == '_' || chessboard[a + 1][b + 2].getImage() == '_' || chessboard[a + 2][b - 1].getImage() == '_' || chessboard[a + 2][b + 1].getImage() == '_' || chessboard[a - 2][b - 1].getImage() == '_' || chessboard[a - 2][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b - 2].getPlayer() != p || chessboard[a - 1][b + 2].getPlayer() != p || chessboard[a + 1][b - 2].getPlayer() != p || chessboard[a + 1][b + 2].getPlayer() != p || chessboard[a + 2][b - 1].getPlayer() != p || chessboard[a + 2][b + 1].getPlayer() != p || chessboard[a - 2][b - 1].getPlayer() != p || chessboard[a - 2][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
}

bool Board::bishopCanMove(int p, int a, int b){
	//9 cases: 4 cases on corners, 4 cases on edges not including corners, 1 case anywhere else not mentioned
	//corner locations
	if(a == 0 && b == 0){ //top left 
		//check diagonally to bottom right
		if(chessboard[a + 1][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 1][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 0 && b == 7){ //top right
		//check diagonally to bottom left
		if(chessboard[a + 1][b - 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 1][b - 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 7 && b == 0){ //bottom left
		//check diagonally to top right
		if(chessboard[a - 1][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 7 && b == 7){ //bottom right
		//check diagonally to top left
		if(chessboard[a - 1][b - 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b - 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	//on edge (not including corners)
	else if(a == 0){ //somewhere in top edge 
		//check diagonally to bottom left and bottom right
		if(chessboard[a + 1][b - 1].getImage() == '_' || chessboard[a + 1][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a + 1][b - 1].getPlayer() != p || chessboard[a + 1][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(a == 7){ //somewhere in bottom edge
		//check diagonally to upper left and upper right
		if(chessboard[a - 1][b - 1].getImage() == '_' || chessboard[a - 1][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b - 1].getPlayer() != p || chessboard[a - 1][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	} 
	else if(b == 0){ //somewhere in left edge
		//check diagonally to upper right and lower right
		if(chessboard[a - 1][b + 1].getImage() == '_' || chessboard[a + 1][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b + 1].getPlayer() != p || chessboard[a + 1][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	else if(b == 7){ //somewhere in right edge
		//check diagonally to upper left and bottom left
		if(chessboard[a - 1][b - 1].getImage() == '_' || chessboard[a + 1][b - 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b - 1].getPlayer() != p || chessboard[a + 1][b - 1].getPlayer() != p)
				return true;
			return false;
		}
	}
	//everywhere else
	else{
		//all 4 directions combined
		if(chessboard[a - 1][b - 1].getImage() == '_' || chessboard[a - 1][b + 1].getImage() == '_' || chessboard[a + 1][b - 1].getImage() == '_' || chessboard[a + 1][b + 1].getImage() == '_')
			return true;
		else{
			if(chessboard[a - 1][b - 1].getPlayer() != p || chessboard[a - 1][b + 1].getPlayer() != p || chessboard[a + 1][b - 1].getPlayer() != p || chessboard[a + 1][b + 1].getPlayer() != p)
				return true;
			return false;
		}
	}
}

bool Board::queenCanMove(int p, int a, int b){
	//both rookCanMove and bishopCanMove combined here
	return (rookCanMove(p, a, b) || bishopCanMove(p, a, b));
}

bool Board::kingCanMove(int p, int a, int b){
	//checking 1 spot all around, same condition as queenCanMove
	return queenCanMove(p, a, b);
}

int Board::getPieceID(int a, int b){
	return chessboard[a][b].getID();
}

int Board::getPieceOfPlayer(int a, int b){
	return chessboard[a][b].getPlayer();
}

char Board::getChessPiece(int x, int y){
	return chessboard[x][y].getImage();
}

bool Board::moveRook(int p, int a, int b, int x, int y){
	//a = b, coordinates of rook, x = y, where we want to move
	if((a != x && b != y) || (a == x && b == y)) //no matter where we want to move, the rook MUST have one shared coordinate after moving
		return false;
	else if(a == x){
		int temp = b;
		if(temp > y){ //pickY > moveY
			while(temp > y && temp - 1 >= 0){
				if(chessboard[a][temp - 1].getImage() != '_' && temp - 1 != y){ //if a piece blocks your path from your desired destination, enemy or ally, return false
					cout << "You cannot move here" << endl;
					return false;
				}
				if(chessboard[a][temp - 1].getImage() == '_' && temp - 1 == y){ //if no piece is blocking you, and you arrive at your destination, then go to it
					movePiece(a, b, x, y);
					return true;
				}
				if(chessboard[a][temp - 1].getImage() != '_' && temp - 1 == y){ //you arrive that destination, but there's a piece in the way. if enemy, capture. else, return false
					if(chessboard[a][temp - 1].getPlayer() != p){
						capturePiece(x, y, a, b);
						return true;
					}
					else{
						cout << "You cannot move here" << endl;
						return false;
					}
				}
				temp--;
			}
		}
		else if(temp < y){ //pickY < moveY
			while(temp < y && temp + 1 <= 7){
				if(chessboard[a][temp + 1].getImage() != '_' && temp + 1 != y){ //if a piece blocks your path from your desired destination, enemy or ally, return false
					cout << "You cannot move here" << endl;
					return false;
				}
				if(chessboard[a][temp + 1].getImage() == '_' && temp + 1 == y){ //if no piece is blocking you, and you arrive at your destination, then go to it
					movePiece(a, b, x, y);
					return true;
				}
				if(chessboard[a][temp + 1].getImage() != '_' && temp + 1 == y){ //you arrive that destination, but there's a piece in the way. if enemy, capture. else, return false
					if(chessboard[a][temp - 1].getPlayer() != p){
						capturePiece(x, y, a, b);
						return true;
					}
					else{
						cout << "You cannot move here" << endl;
						return false;
					}
				}
				temp++;
			}
		}
	}
	else if(b == y){
		int temp = a;
		if(temp > x){
			while(temp > x && temp - 1 >= 0){
				if(chessboard[temp - 1][b].getImage() != '_' && temp - 1 != x){ //if a piece blocks your path from your desired destination, enemy or ally, return false
					cout << "You cannot move here" << endl;
					return false;
				}
				if(chessboard[temp - 1][b].getImage() == '_' && temp - 1 == x){ //if no piece is blocking you, and you arrive at your destination, then go to it
					movePiece(a, b, x, y);
					return true;
				}
				if(chessboard[temp - 1][b].getImage() != '_' && temp - 1 == x){ //you arrive that destination, but there's a piece in the way. if enemy, capture. else, return false
					if(chessboard[temp - 1][b].getPlayer() != p){
						capturePiece(x, y, a, b);
						return true;
					}
					else{
						cout << "You cannot move here" << endl;
						return false;
					}
				}
				temp--;
			}
		}
		else if(temp < x){
			while(temp < x && temp + 1 <= 7){
				if(chessboard[a][temp + 1].getImage() != '_' && temp + 1 != x){ //if a piece blocks your path from your desired destination, enemy or ally, return false
					cout << "You cannot move here" << endl;
					return false;
				}
				if(chessboard[a][temp + 1].getImage() == '_' && temp + 1 == x){ //if no piece is blocking you, and you arrive at your destination, then go to it
					movePiece(a, b, x, y);
					return true;
				}
				if(chessboard[a][temp + 1].getImage() != '_' && temp + 1 == x){ //you arrive that destination, but there's a piece in the way. if enemy, capture. else, return false
					if(chessboard[a][temp + 1].getPlayer() != p){
						capturePiece(x, y, a, b);
						return true;
					}
					else{
						cout << "You cannot move here" << endl;
						return false;
					}
				}
				temp++;
			}
		}
	}
}

bool Board::moveBishop(int p, int a, int b, int x, int y){
	if(a == x && b == y){ //cannot be the same coordinates lmao
		cout << "You gotta move your piece..." << endl;
		return false;
	}
	if(a < x && b > y){ //check diagonal SOUTHWEST
		int temp1 = a, temp2 = b; //change x and y w/o actually altering its values
		while(temp1 <= 7 || temp2 >= 0){
			temp1++;
			temp2--;
			if(temp1 > 7 || temp2 < 0){ //if out of bounds, return false
				cout << "You cannot move here" << endl;
				return false;
			}
			if(temp1 == x && temp2 == y){
				if(chessboard[temp1][temp2].getImage() == '_'){
					movePiece(a, b, x, y);
					return true;
				}
				else{
					if(chessboard[temp1][temp2].getPlayer() != p){
						capturePiece(x, y, a, b);
						return true;
					}
					else{
						cout << "You cannot move here" << endl;
						return false;
					}
				}
			}
			if(chessboard[temp1][temp2].getImage() != '_'){ //while recursively checking, there's a piece blocking the path, so we can't move to where we wanna move
				cout << "You cannot move here" << endl;
				return false;
			}
		}
	}
	else if(a < x && b < y){ //check diagonal SOUTHEAST
		int temp1 = a, temp2 = b; //change x and y w/o actually altering its values
		while(temp1 <= 7 || temp2 <= 7){
			temp1++;
			temp2++;
			if(temp1 > 7 || temp2 > 7){ //if out of bounds, return false
				cout << "You cannot move here" << endl;
				return false;
			}
			if(temp1 == x && temp2 == y){
				if(chessboard[temp1][temp2].getImage() == '_'){
					movePiece(a, b, x, y);
					return true;
				}
				else{
					if(chessboard[temp1][temp2].getPlayer() != p){
						capturePiece(x, y, a, b);
						return true;
					}
					else{
						cout << "You cannot move here" << endl;
						return false;
					}
				}
			}
			if(chessboard[temp1][temp2].getImage() != '_'){ //while recursively checking, there's a piece blocking the path, so we can't move to where we wanna move
				cout << "You cannot move here" << endl;
				return false;
			}
		}
	}
	else if(a > x && b < y){ //check diagonal NORTHEAST
		int temp1 = a, temp2 = b; //change x and y w/o actually altering its values
		while(temp1 >= 0 || temp2 <= 7){
			temp1--;
			temp2++;
			if(temp1 < 0 || temp2 > 7){ //if out of bounds, return false
				cout << "You cannot move here" << endl;
				return false;
			}
			if(temp1 == x && temp2 == y){
				if(chessboard[temp1][temp2].getImage() == '_'){
					movePiece(a, b, x, y);
					return true;
				}
				else{
					if(chessboard[temp1][temp2].getPlayer() != p){
						capturePiece(x, y, a, b);
						return true;
					}
					else{
						cout << "You cannot move here" << endl;
						return false;
					}
				}
			}
			if(chessboard[temp1][temp2].getImage() != '_'){ //while recursively checking, there's a piece blocking the path, so we can't move to where we wanna move
				cout << "You cannot move here" << endl;
				return false;
			}
		}
	}
	else if(a > x && b > y){ //check diagonal NORTHWEST
		int temp1 = a, temp2 = b; //change x and y w/o actually altering its values
		while(temp1 >= 0 || temp2 >= 0){
			temp1--;
			temp2--;
			if(temp1 < 0 || temp2 < 0){ //if out of bounds, return false
				cout << "You cannot move here" << endl;
				return false;
			}
			if(temp1 == x && temp2 == y){
				if(chessboard[temp1][temp2].getImage() == '_'){
					movePiece(a, b, x, y);
					return true;
				}
				else{
					if(chessboard[temp1][temp2].getPlayer() != p){
						capturePiece(x, y, a, b);
						return true;
					}
					else{
						cout << "You cannot move here" << endl;
						return false;
					}
				}
			}
			if(chessboard[temp1][temp2].getImage() != '_'){ //while recursively checking, there's a piece blocking the path, so we can't move to where we wanna move
				cout << "You cannot move here" << endl;
				return false;
			}
		}
	}
	//none of the conditions above are true
	cout << "You cannot move here" << endl;
	return false;
}

bool Board::moveKnight(int p, int a, int b, int x, int y){
	//corner locations
	//a and b are coordinates of the piece you chose to move, x and y are the desired coordinates to move to
	if((x == a + 2 && y == b + 1) || (x == a + 2 && y == b - 1) || (x == a + 1 && y == b + 2) || (x == a + 1 && y == b - 2) || (x == a - 2 && y == b + 1) || (x == a - 2 && y == b - 1) || (x == a - 1 && y == b + 2) || (x == a - 1 && y == b - 2)){
		if(chessboard[x][y].getImage() == '_'){
			movePiece(a, b, x, y);
			return true;
		}
		else if(chessboard[x][y].getPlayer() != p){
			capturePiece(x, y, a, b);
			return true;
		}
	}
	cout << "Please move your piece to a valid spot" << endl;
	return false;
}

bool Board::moveQueen(int p, int a, int b, int x, int y){
	return (moveRook(p, a, b, x, y) || moveBishop(p, a, b, x, y));
}

void Board::movePiece(int a, int b, int x, int y){
	//x and y are the locations to move to, and a and b are the original coordinates of the piece to move
	Piece move = chessboard[a][b];
	chessboard[a][b] = chessboard[x][y];
	chessboard[x][y] = move;
}

void Board::capturePiece(int a, int b, int x, int y){
	//a and b are the locations to capture, x and y is the location of original piece
	chessboard[a][b] = chessboard[x][y];
	chessboard[x][y].setPlayer(0);
	chessboard[x][y].setImage('_');
	chessboard[x][y].setHorizontal(x);
	chessboard[x][y].setVertical(y);
	chessboard[x][y].setID(0);
}
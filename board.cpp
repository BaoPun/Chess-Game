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
	cout << "\n\t\t\tDisplaying the Chess Board" << endl;
	for(int i = 0; i < 8; i++){
		cout << "\t\t\t";
		for(int j = 0; j < 8; j++){
			if(chessboard[i][j].getImage() == 'P'){
				if(chessboard[i][j].getPlayer() == 1) //player 1
					cout << "[1]";
				else
					cout << "[2]";
			}
			else
				cout << "[" << chessboard[i][j].getImage() << "]";
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
				//if the selected pawn hasn't moved yet
				//pawnID = chessboard[a][b].getID(); //this can be dealt with in another function, just keeping it here for now
				/*if(player[p - 1].pawnFirstMove(pawnID))
					return true;*/
				//determine which player is moving the pawn
				return pawnCanMove(p, a, b);
			case 'R':
				return rookCanMove(p, a, b);
			case 'B':
				return bishopCanMove(p, a, b);
			case 'L':
			
				return true;
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
	//8 possibilities
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
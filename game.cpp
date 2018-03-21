#include "./game.h"

Game::Game(){
	//initialize the chess board here
	
	//player 1 first
	//pawns
	for(int i = 0; i < 8; i++)
		chess.setBoardArea(player[0].initializePawn(i, 1, 6, i, 'P'), 6, i);
	//rooks
	chess.setBoardArea(player[0].initializeRook(0, 1, 7, 0, 'R'), 7, 0);
	chess.setBoardArea(player[0].initializeRook(1, 1, 7, 7, 'R'), 7, 7);
	//knights
	chess.setBoardArea(player[0].initializeKnight(0, 1, 7, 1, 'L'), 7, 1);
	chess.setBoardArea(player[0].initializeKnight(1, 1, 7, 6, 'L'), 7, 6);
	//bishops
	chess.setBoardArea(player[0].initializeBishop(0, 1, 7, 2, 'B'), 7, 2);
	chess.setBoardArea(player[0].initializeBishop(1, 1, 7, 5, 'B'), 7, 5);
	//queen
	chess.setBoardArea(player[0].initializeQueen(1, 7, 3, 'Q'), 7, 3);
	//king
	chess.setBoardArea(player[0].initializeKing(1, 7, 4, 'K'), 7, 4);
	
	//player 2 now
	//pawns
	for(int i = 0; i < 8; i++)
		chess.setBoardArea(player[1].initializePawn(i, 2, 1, i, 'P'), 1, i);
	//rooks
	chess.setBoardArea(player[1].initializeRook(0, 2, 0, 0, 'R'), 0, 0);
	chess.setBoardArea(player[1].initializeRook(1, 2, 0, 7, 'R'), 0, 7);
	//knights
	chess.setBoardArea(player[1].initializeKnight(0, 2, 0, 1, 'L'), 0, 1);
	chess.setBoardArea(player[1].initializeKnight(1, 2, 0, 6, 'L'), 0, 6);
	//bishops
	chess.setBoardArea(player[1].initializeBishop(0, 2, 0, 2, 'B'), 0, 2);
	chess.setBoardArea(player[1].initializeBishop(1, 2, 0, 5, 'B'), 0, 5);
	//queen
	chess.setBoardArea(player[1].initializeQueen(2, 0, 4, 'Q'), 0, 4);
	//king
	chess.setBoardArea(player[1].initializeKing(2, 0, 3, 'K'), 0, 3);
}

void Game::displayBoard(){
	chess.displayBoard();
}

int Game::firstTurn(){
	int first = rand()%2 + 1; //1 - 2
	cout << "First move goes to player " << first << endl;
	return first;
}

bool Game::movePawn(int turnPlayer, int pickX, int pickY, int moveX, int moveY){
	if(pickX == moveX && pickY == moveY){
		cout << "Please move your piece" << endl;
		return false;
	}
	if(turnPlayer == 1){ //player 1
		if(player[0].pawnFirstMove(chess.getPieceID(pickX, pickY))){ //a selected pawn's first move
			if(moveX == pickX - 2 && moveY == pickY){  
				if(chess.getChessPiece(pickX - 1, pickY) != '_'){ //check the space right in front of the pawn first
					cout << "Your pawn cannot move to that coordinate, please try again" << endl;
					return false;
				}				
				else{ //if the space in front is not blocked by anyone, then check the desired move space itself
					if(chess.getChessPiece(moveX, moveY) == '_'){
						chess.movePiece(pickX, pickY, moveX, moveY);
						player[0].changeFirstStatus(chess.getPieceID(moveX, moveY));
						return true;
					}
					else{
						cout << "Your pawn cannot move to that coordinate, please try again" << endl;
						return false;
					}
				}
			}
			else if(moveX == pickX - 1 && moveY == pickY){ //just check the space in front of the pawn
				if(chess.getChessPiece(moveX, moveY) == '_'){
					chess.movePiece(pickX, pickY, moveX, moveY);
					player[0].changeFirstStatus(chess.getPieceID(moveX, moveY));
					return true;
				}
				else{
					cout << "Your pawn cannot move to that coordinate, please try again" << endl;
					return false;
				}
			}
			else if(moveX == pickX - 1 && moveY == pickY - 1){ //capture enemy piece diagonally to the left
				if(chess.getChessPiece(moveX, moveY) == '_' || chess.getPieceOfPlayer(moveX, moveY) == turnPlayer){
					cout << "Your pawn cannot move to that coordinate, please try again" << endl;
					return false;
				}
				else{
					chess.capturePiece(moveX, moveY, pickX, pickY);
					player[0].changeFirstStatus(chess.getPieceID(moveX, moveY));
					return true;
				}
			}
			else if(moveX == pickX - 1 && moveY == pickY + 1){ //capture enemy piece diagonally to the right
				if(chess.getChessPiece(moveX, moveY) == '_' || chess.getPieceOfPlayer(moveX, moveY) == turnPlayer){
					cout << "Your pawn cannot move to that coordinate, please try again" << endl;
					return false;
				}
				else{
					chess.capturePiece(moveX, moveY, pickX, pickY);
					player[0].changeFirstStatus(chess.getPieceID(moveX, moveY));
					return true;
				}
			}
			else{
				cout << "Your pawn cannot move to that coordinate, please try again" << endl;
				return false;
			}
		}
		else{
			if(moveX == pickX - 1 && moveY == pickY){
				if(chess.getChessPiece(moveX, moveY) == '_'){
					chess.movePiece(pickX, pickY, moveX, moveY);
					player[0].changeFirstStatus(chess.getPieceID(moveX, moveY));
					return true;
				}
				else{
					cout << "Your pawn cannot move to that coordinate, please try again" << endl;
					return false;
				}
			}
			else if(moveX == pickX - 1 && moveY == pickY - 1){ //capture enemy piece diagonally to the left
				if(chess.getChessPiece(moveX, moveY) == '_' || chess.getPieceOfPlayer(moveX, moveY) == turnPlayer){
					cout << "Your pawn cannot move to that coordinate, please try again" << endl;
					return false;
				}
				else{
					chess.capturePiece(moveX, moveY, pickX, pickY);
					player[0].changeFirstStatus(chess.getPieceID(moveX, moveY));
					return true;
				}
			}
			else if(moveX == pickX - 1 && moveY == pickY + 1){ //capture enemy piece diagonally to the right
				if(chess.getChessPiece(moveX, moveY) == '_' || chess.getPieceOfPlayer(moveX, moveY) == turnPlayer){
					cout << "Your pawn cannot move to that coordinate, please try again" << endl;
					return false;
				}
				else{
					chess.capturePiece(moveX, moveY, pickX, pickY);
					player[0].changeFirstStatus(chess.getPieceID(moveX, moveY));
					return true;
				}
			}
			else{
				cout << "Your pawn cannot move to that coordinate, please try again" << endl;
				return false;
			}
		}
	}
	else{
		if(player[1].pawnFirstMove(chess.getPieceID(pickX, pickY))){
			if(moveX == pickX + 2 && moveY == pickY){  //check the space right in front of the pawn first
				if(chess.getChessPiece(pickX + 1, pickY) != '_'){
					cout << "Your pawn cannot move to that coordinate, please try again" << endl;
					return false;
				}				
				else{
					if(chess.getChessPiece(moveX, moveY) == '_'){
						chess.movePiece(pickX, pickY, moveX, moveY);
						player[1].changeFirstStatus(chess.getPieceID(moveX, moveY));
						return true;
					}
					else{
						cout << "Your pawn cannot move to that coordinate, please try again" << endl;
						return false;
					}
				}
			}
			else if(moveX == pickX + 1 && moveY == pickY){
				if(chess.getChessPiece(moveX, moveY) == '_'){
					chess.movePiece(pickX, pickY, moveX, moveY);
					player[1].changeFirstStatus(chess.getPieceID(moveX, moveY));
					return true;
				}
				else{
					cout << "Your pawn cannot move to that coordinate, please try again" << endl;
					return false;
				}
			}
			else if(moveX == pickX + 1 && moveY == pickY - 1){ //capture enemy piece diagonally to the left
				if(chess.getChessPiece(moveX, moveY) == '_' || chess.getPieceOfPlayer(moveX, moveY) == turnPlayer){
					cout << "Your pawn cannot move to that coordinate, please try again" << endl;
					return false;
				}
				else{
					chess.capturePiece(moveX, moveY, pickX, pickY);
					player[1].changeFirstStatus(chess.getPieceID(moveX, moveY));
					return true;
				}
			}
			else if(moveX == pickX + 1 && moveY == pickY + 1){ //capture enemy piece diagonally to the right
				if(chess.getChessPiece(moveX, moveY) == '_' || chess.getPieceOfPlayer(moveX, moveY) == turnPlayer){
					cout << "Your pawn cannot move to that coordinate, please try again" << endl;
					return false;
				}
				else{
					chess.capturePiece(moveX, moveY, pickX, pickY);
					player[1].changeFirstStatus(chess.getPieceID(moveX, moveY));
					return true;
				}
			}
			else{
				cout << "Your pawn cannot move to that coordinate, please try again" << endl;
				return false;
			}
		}
		else{
			if(moveX == pickX + 1 && moveY == pickY){
				if(chess.getChessPiece(moveX, moveY) == '_'){
					chess.movePiece(pickX, pickY, moveX, moveY);
					player[1].changeFirstStatus(chess.getPieceID(moveX, moveY));
					return true;
				}
				else{
					cout << "Your pawn cannot move to that coordinate, please try again" << endl;
					return false;
				}
			}
			else if(moveX == pickX + 1 && moveY == pickY - 1){ //capture enemy piece diagonally to the left
				if(chess.getChessPiece(moveX, moveY) == '_' || chess.getPieceOfPlayer(moveX, moveY) == turnPlayer){
					cout << "Your pawn cannot move to that coordinate, please try again" << endl;
					return false;
				}
				else{
					chess.capturePiece(moveX, moveY, pickX, pickY);
					player[1].changeFirstStatus(chess.getPieceID(moveX, moveY));
					return true;
				}
			}
			else if(moveX == pickX + 1 && moveY == pickY + 1){ //capture enemy piece diagonally to the right
				if(chess.getChessPiece(moveX, moveY) == '_' || chess.getPieceOfPlayer(moveX, moveY) == turnPlayer){
					cout << "Your pawn cannot move to that coordinate, please try again" << endl;
					return false;
				}
				else{
					chess.capturePiece(moveX, moveY, pickX, pickY);
					player[1].changeFirstStatus(chess.getPieceID(moveX, moveY));
					return true;
				}
			}
			else{
				cout << "Your pawn cannot move to that coordinate, please try again" << endl;
				return false;
			}
		}
	}
}

bool Game::moveKing(int turnPlayer, int pickX, int pickY, int moveX, int moveY){
	//9 locations to check, the boundaries are already accounted for in another function
	if((moveX == pickX - 1 && moveY == pickY - 1) || (moveX == pickX - 1 && moveY == pickY + 1) || (moveX == pickX + 1 && moveY == pickY + 1) || (moveX == pickX + 1 && moveY == pickY - 1) || (moveX == pickX + 1 && moveY == pickY) || (moveX == pickX - 1 && moveY == pickY) || (moveX == pickX && moveY == pickY - 1) || (moveX == pickX && moveY == pickY + 1)){
		if(chess.getChessPiece(moveX, moveY) == '_'){
			chess.movePiece(pickX, pickY, moveX, moveY);
			return true;
		}
		else{
			if(chess.getPieceOfPlayer(moveX, moveY) != turnPlayer){
				chess.capturePiece(moveX, moveY, pickX, pickY);
				return true;
			}
		}
	}
	else{ //attempting to castle
		if(moveX == pickX){
			if(moveY == pickY - 2){ //move to left
				if(chess.getChessPiece(moveX, pickY - 1) == '_'){ //check if area directly to left of king is uninhabited
					if(chess.getChessPiece(moveX, moveY) == '_'){ //check if your desired area is also uninhabited
						if(chess.getChessPiece(moveX, moveY - 1) == 'R' && chess.getPieceOfPlayer(moveX, moveY - 1) == turnPlayer){ //check if YOUR rook is on the left side
							if(player[turnPlayer - 1].getCastleStatus() == 0){
								chess.movePiece(pickX, pickY, moveX, moveY);
								chess.movePiece(moveX, pickY - 1, moveX, moveY - 1);
								player[turnPlayer - 1].changeCastleStatus();
								return true;
							}
						}
					}
				}
			}
			else if(moveY == pickY + 2){ //move to right
				if(chess.getChessPiece(moveX, pickY + 1) == '_'){ //check if area directly to right of king is uninhabited
					if(chess.getChessPiece(moveX, moveY) == '_'){ //check if your desired area is also uninhabited
						if(chess.getChessPiece(moveX, moveY + 1) == 'R' && chess.getPieceOfPlayer(moveX, moveY + 1) == turnPlayer){
							if(player[turnPlayer - 1].getCastleStatus() == 0){
								chess.movePiece(pickX, pickY, moveX, moveY);
								chess.movePiece(moveX, pickY + 1, moveX, moveY + 1);
								player[turnPlayer - 1].changeCastleStatus();
								return true;
							}
						}
					}
				}
			}
		}
	}
	cout << "Your king cannot move here" << endl;
	return false;
}

void Game::play(){
	int turnPlayer = firstTurn();
	int pickX, pickY, moveX, moveY, continuing;
	bool valid;
	while(1){
		cout << "Chess codings: " << endl;
		cout << " - Pawns either represent 1 or 2 (player #)" << endl;
		cout << " - Rooks represent R" << endl;
		cout << " - Bishops represent B" << endl;
		cout << " - Knights represent L" << endl;
		cout << " - Queen represents Q" << endl;
		cout << " - King represents K" << endl;
		cout << "\nIt is player " << turnPlayer << "'s turn to make a move!" << endl;
		displayBoard();
		valid = false;
		while(valid == false){
			cout << "Choose a piece to move, by inputting its coordinates (x (0-7), y (0-7))" << endl << ": ";
			cin >> pickX >> pickY;
			while(pickX > 7 || pickX < 0 || pickY > 7 || pickY < 0){
				cout << "Please do not go out of bounds, choose your coordinates again (x (0-7), y (0-7))" << endl << ": ";
				cin >> pickX >> pickY;
			}
			if(chess.checkValidMovement(turnPlayer, pickX, pickY))
				valid = true;
			else
				cout << "This piece either does not belong to you, or it cannot move anywhere based on its location.  Please pick another piece" << endl;
		}
		valid = false;
		while(valid == false){
			cout << "Where would you like to move your piece?" << endl << ": ";
			cin >> moveX >> moveY;
			while(moveX < 0 || moveY < 0 || moveX > 7 || moveY > 7){
				cout << "Please type coordinates between 0-7: ";
				cin >> moveX >> moveY;
			}
			switch(chess.getChessPiece(pickX, pickY)){
				case 'P':
					valid = movePawn(turnPlayer, pickX, pickY, moveX, moveY);
					break;					
				case 'R':
					valid = chess.moveRook(turnPlayer, pickX, pickY, moveX, moveY);
					break;
				case 'B':
					valid = chess.moveBishop(turnPlayer, pickX, pickY, moveX, moveY);
					break;
				case 'L':
					valid = chess.moveKnight(turnPlayer, pickX, pickY, moveX, moveY);
					break;
				case 'Q':
					valid = chess.moveQueen(turnPlayer, pickX, pickY, moveX, moveY);
					break;
				case 'K':
					valid = moveKing(turnPlayer, pickX, pickY, moveX, moveY);
					break;
			}
		}
		
		cout << "Would you like to continue (1 yes)?" << endl << ": ";
		cin >> continuing;
		if(continuing != 1)
			break;
		if(turnPlayer == 1)
			turnPlayer++;
		else
			turnPlayer = 1;
		system("clear");
	}
	cout << "Thanks for playing!" << endl;
}
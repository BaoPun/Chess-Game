#include "./board.h"

Board::Board(){
	//initialize entire chessboard
	cout << "Chess codings: " << endl;
	cout << " - Pawns either represent 1 or 2 (player #)" << endl;
	cout << " - Rooks represent R" << endl;
	cout << " - Bishops represent B" << endl;
	cout << " - Knights represent L" << endl;
	cout << " - Queen represents Q" << endl;
	cout << " - King represents K" << endl;
	
	//player 1 first
	//pawns
	for(int i = 0; i < 8; i++)
		chessboard[6][i] = player[0].initializePawn(1, 6, i, 'P');
	//rooks
	chessboard[7][0] = player[0].initializeRook(1, 7, 0, 'R');
	chessboard[7][7] = player[0].initializeRook(1, 7, 7, 'R');
	//bishops
	chessboard[7][1] = player[0].initializeBishop(1, 7, 1, 'B');
	chessboard[7][6] = player[0].initializeBishop(1, 7, 6, 'B');
	//knight
	chessboard[7][2] = player[0].initializeKnight(1, 7, 2, 'L');
	chessboard[7][5] = player[0].initializeKnight(1, 7, 5, 'L');
	//queen
	chessboard[7][3] = player[0].initializeQueen(1, 7, 3, 'Q');
	//king
	chessboard[7][4] = player[0].initializeKing(1, 7, 4, 'K');
	
	//player 2 now
	//pawns
	for(int i = 0; i < 8; i++)
		chessboard[1][i] = player[1].initializePawn(2, 1, i, 'P');
	//rooks
	chessboard[0][0] = player[0].initializeRook(2, 0, 0, 'R');
	chessboard[0][7] = player[0].initializeRook(2, 0, 7, 'R');
	//bishops
	chessboard[0][1] = player[0].initializeBishop(2, 0, 1, 'B');
	chessboard[0][6] = player[0].initializeBishop(2, 0, 6, 'B');
	//knight
	chessboard[0][2] = player[0].initializeKnight(2, 0, 2, 'L');
	chessboard[0][5] = player[0].initializeKnight(2, 0, 5, 'L');
	//queen
	chessboard[0][4] = player[0].initializeQueen(2, 0, 3, 'Q');
	//king
	chessboard[0][3] = player[0].initializeKing(2, 0, 4, 'K');
	
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
}
#include <iostream>
using namespace std;

enum Chess {
	Rook = 0,
	Knight = 1,
	Bishop = 2,
	Queen = 3,
	King = 4,
	Pawn = 5,
	Empty = 6
};


void setupBoard(Chess Board[8][8]);

int main()
{
	Chess Board[8][8] = {};
	


	//Chess Board[8][8] = {};
	setupBoard(Board);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << Board[i][j] << "\t";
		}
		cout << endl;
	}

	return 0;

}

void setupBoard(Chess Board[8][8])
{
	**Board = Rook;
	**(Board + 1) = Knight;
	**(Board + 2) = Bishop;
	*(*Board +1) = Pawn;
	*(*Board+9) = Pawn;
			/*
			Board = { 
			{ Rook, Knight, Bishop, King, Queen, Bishop, Knight, Rook },
			{ Pawn,Pawn,Pawn,Pawn,Pawn,Pawn,Pawn,Pawn },
			{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
			{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
			{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
			{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
			{ Pawn,Pawn,Pawn,Pawn,Pawn,Pawn,Pawn,Pawn },
			{ Rook, Knight, Bishop, Queen, King, Bishop, Knight, Rook } 
			};

			*/

}
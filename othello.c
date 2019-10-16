//***************************************************
// Filename: othello.c
//
// Author: Nandigam
//***************************************************

#include "othello.h"
bool withinBoard(int colNum, int rowNum, int size);

// Displays the board (as SIZE x SIZE grid) on console
void displayBoard(char board[][SIZE])
{
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf((i == 0 ? "%5d" : "%3d"), i+1);
	}
	printf("\n");

	for (int i = 0; i < SIZE; i++) {
		printf("%2d", i+1);
		for (int j = 0; j < SIZE; j++) {
			printf("%3c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// Initializes the board with start configuration of discs (see project specs)
void initializeBoard(char board[][SIZE])
{
	// COMPLETE THIS FUNCTION // Done
	int halfSize = SIZE/2;
	printf("halfSize = %d", halfSize);
	for(int r = 0; r < SIZE; r++)
	{
		for(int c = 0; c < SIZE; c++)
		{
			if((r == halfSize && c == halfSize )||
				(r == (halfSize - 1) && c == (halfSize - 1)))
			{
				board[r][c] = 'B';
			}else if((r == (halfSize - 1) && c == halfSize)||
				(r == halfSize && c == (halfSize - 1)))
			{
				board[r][c] = 'W';
				
			}else{
				board[r][c] = '-';
			}
		}
	}
}

// Returns true if moving the disc to location row,col is valid; else returns false
bool isValidMove(char board[][SIZE], int row, int col, char disc)
{
	printf("Row and col passed in %d, %d\n", (row + 1), (col+1));
	// REPLACE THIS WITH YOUR IMPLEMENTATION
	if(board[row][col] == '-')
	{
		//find surrounding cells by adding and subtracting 1 to the col and row
		 for(int colNum = col - 1; colNum <= (col + 1); colNum++)
		 {
			 for(int rowNum = row - 1; rowNum <= (row + 1); rowNum++)
			 {
				 printf("WOrking on %d, %d\n", rowNum + 1, colNum + 1);
				 // if board[rowNum][colNum] is not the center cell chosen
				 if(!((colNum == col) && (rowNum == row)))
				 {
					 //if board[rowNum][colNum] is  inside board
					 if(withinBoard(rowNum, colNum, SIZE))
					 {
						 //if board[rowNum][colNum] occupied 
						 if(board[rowNum][colNum] != '-')
						 {
							 //if the disc in board[rowNum][colNum]
							 //is not current player's
							 if(board[rowNum][colNum] != disc)
							 {
								 int neighborR = rowNum;
								 int neighborC = colNum;
								 int deltaR = neighborR - row;
								 int deltaC = neighborC - col;
								 //search in that direction until 
								 //current player's piece is found
								 //or until blank cell found
								 while(withinBoard(neighborR, neighborC, SIZE) 
										&& ((board[neighborR][neighborC] != '-')
										&& (board[neighborR][neighborC] != disc)))
								 {
									 if(board[neighborR][neighborC] == disc)
									 {
										 return true;
									 }else{
										 neighborR += deltaR;
										 neighborC += deltaC;
										 printf("Going to %d, %d\n", neighborR, neighborC);
									 }
								 }
							 }
						 }
					 }
			 	}	
			 }
		 }
	}
	return false;
}

// Places the disc at location row,col and flips the opponent discs as needed
void placeDiscAt(char board[][SIZE], int row, int col, char disc)
{
	// COMPLETE THIS FUNCTION // Done
	board[row][col] = disc;
}

// Returns true if a valid move for disc is available; else returns false
bool isValidMoveAvailable(char board[][SIZE], char disc)
{
	return true;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}

// Returns true if the board is fully occupied with discs; else returns false
bool isBoardFull(char board[][SIZE])
{
	for(int r = 0; r < SIZE; r++)
	{
		for(int c = 0; c < SIZE; c++)
		{
			if(board[r][c] == '-')
			{
				return false;	// REPLACE THIS WITH YOUR IMPLEMENTATION// Done
			}
		}
	}
	return true;	
}

// Returns true if either the board is full or a valid move is not available for either disc
bool isGameOver(char board[][SIZE])
{
	return false;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}

// If there is a winner, it returns the disc (BLACK or WHITE) associated with the winner.
// In case of a tie, it returns EMPTY
char checkWinner(char board[][SIZE])
{
	//for(board[r]
	return EMPTY;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}


//helper functions


//Returns false if cell board[colNum][rowNum] not is inside board; else return true
bool withinBoard(int colNum, int rowNum, int size)
{
	if((colNum < 0) || (rowNum < 0))
	{
		return false;
	}
	if((colNum >= size) || (rowNum >= size))
	{
		return false;
	}
	return true;
}

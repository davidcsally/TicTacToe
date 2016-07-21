/**
 * Tic Tac Toe
 * -------------
 * David Sally
 * 
 * 
 */

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

// Globals
const int SIZE = 3;
const int ROW = SIZE;
const int COLUMN = SIZE;
char board[ROW][COLUMN];
bool gameOver = 0;

string namePlayer1;
string namePlayer2;

// Function Prototypes
void initBoard();
void greetPlayer();
void printBoard();
void clearScreen();
void playerX();
void playerO();
bool winCheckX();
bool winCheckO();

// Function Main
int main()
{
	//Initialize game board to char '*'
	initBoard();

	// Greet player & print board
	greetPlayer();
	clearScreen();
	printBoard();
	
	// play game...
	int turnCounter = 0;
	
	while (gameOver == false)
	{
		// prompt for X's move;

		playerX();
		clearScreen();
		printBoard();
		gameOver = winCheckX();
		
		if (gameOver == 1)
		{
			cout << endl << namePlayer1 << " wins!" << endl;
			break;
		}

		// add 1 to the turn count
		turnCounter += 1;
		
		// check if any moves are left
		if (turnCounter == 9)
		{
			cout << "It's a tie!" << endl;
			break;
		}

		
		// prompt for player O's move;
		playerO();
		clearScreen();
		printBoard();
		gameOver = winCheckO();
		
		if (gameOver == 1)
		{
			cout << endl << namePlayer2 << " wins!" << endl;
			break;
		}
		
		// add 1 to the turn count
		turnCounter += 1;
		
	}
	
	return 0;
}

//******************************************************************************

// Initialize the Board
void initBoard()
{
	for (int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			board[i][j] = '*';
		}
	}
}

// Greet the player
void greetPlayer()
{
	cout << "Welcome to Tic Tac Toe!" << endl;
	cout << "Enter Player X's name: ";
	cin >> namePlayer1;
	cout << "Enter Player O's name: ";
	cin >> namePlayer2;
}

// Print current board state
void printBoard()
{
	
	cout << "    1    2    3   <- Column" << endl << endl;
	
	for(int i = 0; i < SIZE; i++)
	{
		cout << i + 1 << "  ";
		for(int j = 0; j < SIZE; j++)
		{
			if ( j == 1)
			{
				cout << " | " << board[i][j] << " | ";
			}
			else
			{
				cout << " " << board[i][j] << " ";
			}
		}
		cout << endl;
	}
	
	printf("\n^\nRow\n");
}

// Player X's turn
void playerX()
{
	int playerRow;
	int playerColumn;
	
	// first loop: check if space is already taken
	do
	{
		// second loop: check if space 1-3 is entered
		do
		{
			cout << endl;
			cout << namePlayer1 << ": choose a row (1-3): ";
			cin >> playerRow;
		}
		while (playerRow < 1 || playerRow > 3);
		
		do
		{
			cout << namePlayer1 << ": choose a column (1-3): ";
			cin >> playerColumn;
		}
		while (playerColumn < 1 || playerColumn > 3);
		
		if (board[playerRow - 1][playerColumn - 1] == 'X' || board[playerRow - 1][playerColumn - 1] == 'O')
		{
			cout << "Error! Space already taken!" << endl;
		}
		
	}
	
	while (board[playerRow - 1][playerColumn - 1] == 'X' || board[playerRow - 1][playerColumn - 1] == 'O');

	board[playerRow - 1][playerColumn - 1] = 'X';
		
		
}

void playerO()
{
	int playerRow;
	int playerColumn;
	
	do
	{
		do
		{
			cout << endl;
			cout << namePlayer2 << ": choose a row (1-3): ";
			cin >> playerRow;
		}
		while (playerRow < 1 || playerRow > 3);
		
		do
		{
			cout << namePlayer2 << ": choose a column (1-3): ";
			cin >> playerColumn;
		}
		while (playerColumn < 1 || playerColumn > 3);
		
		if (board[playerRow - 1][playerColumn - 1] == 'X' || board[playerRow - 1][playerColumn - 1] == 'O')
		{
			cout << "Error! Space already taken!" << endl;
		}
		
	}
	
	while (board[playerRow - 1][playerColumn - 1] == 'X' || board[playerRow - 1][playerColumn - 1] == 'O');

	
	board[playerRow - 1][playerColumn - 1] = 'O';
}

// Clear the screen (by printing blank lines...)
void clearScreen()
{
	printf("\n\n\n\n\n\n\n\n\n\n");
}

// check to see if player has won
bool winCheckX()
{
	int counter = 0;
	
	/**
	 * check columns for three in a row
	 * 
	 * 	X | X | X
	 * 	_ | _ | _
	 * 	_ | _ | _
	 * 
	*/
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			// reset counter for each row
			if (j == 0)
			{
				counter = 0;
			}
			
			// check if spot contains an 'X'
			if (board[i][j] == 'X')
			{
				counter +=1;
			}

			// if three 'X's in a row are found, make win = true
			if (counter == 3)
			{
				return 1;
			}
		}
	}
	
	/**
	 * check columns for three in a row
	 * 
	 * 	_ | X | _
	 * 	_ | X | _
	 * 	_ | X | _
	 * 
	*/
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			// reset counter for each row
			if (j == 0)
			{
				counter = 0;
			}
			
			// check if spot contains an 'X'
			if (board[j][i] == 'X')
			{
				counter +=1;
			}

			// if three 'X's in a row are found, make win = true
			if (counter == 3)
			{
				return 1;
			}
		}
	}
	
		/**
	 * check diagnol for three in a row
	 * 
	 * 	X | _ | _
	 * 	_ | X | _
	 * 	_ | _ | X
	 * 
	*/
	
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
	{
		return 1;
	}
	
	if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
	{
		return 1;
	}
	
	// was not in a win state, return false
	return 0;
}

bool winCheckO()
{
	int counter = 0;
	
	/**
	 * check columns for three in a row
	 * 
	 * 	O | O | O
	 * 	_ | _ | _
	 * 	_ | _ | _
	 * 
	*/
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			// reset counter for each row
			if (j == 0)
			{
				counter = 0;
			}
			
			// check if spot contains an 'X'
			if (board[i][j] == 'O')
			{
				counter +=1;
			}

			// if three 'X's in a row are found, make win = true
			if (counter == 3)
			{
				return 1;
			}
		}
	}
	
	/**
	 * check columns for three in a row
	 * 
	 * 	_ | O | _
	 * 	_ | O | _
	 * 	_ | O | _
	 * 
	*/
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			// reset counter for each row
			if (j == 0)
			{
				counter = 0;
			}
			
			// check if spot contains an 'X'
			if (board[j][i] == 'O')
			{
				counter +=1;
			}

			// if three 'X's in a row are found, make win = true
			if (counter == 3)
			{
				return 1;
			}
		}
	}
	
		/**
	 * check diagnol for three in a row
	 * 
	 * 	O | _ | _
	 * 	_ | O | _
	 * 	_ | _ | O
	 * 
	*/
	
	if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
	{
		return 1;
	}
	
	if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
	{
		return 1;
	}
	
	// was not in a win state, return false
	return 0;
}
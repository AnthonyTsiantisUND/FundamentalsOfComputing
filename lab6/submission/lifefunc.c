/*
	Anthony Tsiantis
	lifefunc.c
	Fundamentals of Computing
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BOARDSIZE 40

// Function Prints the board and its boundaries to the screen
void printBoard(char board[BOARDSIZE][BOARDSIZE]) {
	for (int i = 0; i < BOARDSIZE+2; i++) {
		for (int j = 0; j < BOARDSIZE+2; j++) {
			if (i == 0 || i == BOARDSIZE+1) {
				if (j == 0 || j == BOARDSIZE + 1) {
					printf(" ");
				} else {
					printf("-");
				}
			} else if (j == 0 || j == BOARDSIZE+1) {
				printf("|");
			} else {
				printf("%c", board[i-1][j-1]);
			}
		}
		printf("\n");

	}
}

// Function replaces every index of the board array with a space
void clearBoard(char board[BOARDSIZE][BOARDSIZE]) {
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			board[i][j] = ' ';
		}
	}

}

// Displays a help menu for the user
void helpMenu() {
			printf("Enter \'a\' followed by two integers where 1 <= x <= 40 to add a new live cell.\n");
			printf("Enter \'c\' to clear the board.\n");
			printf("Enter \'r\' followed by two integers where 1 <= x <= 40 to remove a cell.\n");
			printf("Enter \'n\' to advance the simulation by one step.\n");
			printf("Enter \'q\' to quit the program.\n");
			printf("Enter \'p\' to play the game continuously.\n");

}

// Check cell counts neighbors and determine if cell survives
int checkCell(char board[BOARDSIZE][BOARDSIZE], int x, int y, bool live) {
	// Count neighbors
	int neighbors = 0;

	// Top row
	if (x == 0) {
		// Top left
		if (y == 0) {
			if (board[x+1][y] == 'x') { neighbors++; }
			if (board[x+1][y+1] == 'x') { neighbors++; }
			if (board[x][y+1] == 'x') { neighbors++; }
		} else if (y == BOARDSIZE - 1) { // Top right	
			if (board[x][y-1] == 'x') { neighbors++; }
			if (board[x+1][y-1] == 'x') { neighbors++; }
			if (board[x+1][y] == 'x') { neighbors++; }
		} else { // Top row	
			if (board[x][y-1] == 'x') { neighbors++; }
			if (board[x][y+1] == 'x') { neighbors++; }
			if (board[x+1][y-1] == 'x') { neighbors++; }
			if (board[x+1][y] == 'x') { neighbors++; }
			if (board[x+1][y+1] == 'x') { neighbors++; }
		}
	} else if (x == BOARDSIZE - 1) { // BOTTOM ROW
		// bottom left
		if (y == 0) {
			if (board[x-1][y] == 'x') { neighbors++; }
			if (board[x-1][y+1] == 'x') { neighbors++; }
			if (board[x][y+1] == 'x') { neighbors++; }
		} else if (y == BOARDSIZE - 1) { // Bottom right	
			if (board[x-1][y] == 'x') { neighbors++; }
			if (board[x-1][y-1] == 'x') { neighbors++; }
			if (board[x][y-1] == 'x') { neighbors++; }
		} else { // Bottom row	
			if (board[x-1][y-1] == 'x') { neighbors++; }
			if (board[x-1][y] == 'x') { neighbors++; }
			if (board[x-1][y+1] == 'x') { neighbors++; }
			if (board[x][y-1] == 'x') { neighbors++; }
			if (board[x][y+1] == 'x') { neighbors++; }
		}
	} else if (y == 0) { // LEFT COLUMN
		if (board[x-1][y] == 'x') { neighbors++; }
		if (board[x+1][y] == 'x') { neighbors++; }
		if (board[x-1][y+1] == 'x') { neighbors++; }
		if (board[x][y+1] == 'x') { neighbors++; }
		if (board[x+1][y+1] == 'x') { neighbors++; }
	} else if (y == BOARDSIZE - 1) { // RIGHT COLUMN	
		if (board[x-1][y] == 'x') { neighbors++; }
		if (board[x+1][y] == 'x') { neighbors++; }
		if (board[x-1][y-1] == 'x') { neighbors++; }
		if (board[x][y-1] == 'x') { neighbors++; }
		if (board[x+1][y-1] == 'x') { neighbors++; }
	} else { // EVETHING ELSE	
		if (board[x-1][y-1] == 'x') { neighbors++; }
		if (board[x-1][y] == 'x') { neighbors++; }
		if (board[x-1][y+1] == 'x') { neighbors++; }
		if (board[x][y-1] == 'x') { neighbors++; }
		if (board[x][y+1] == 'x') { neighbors++; }
		if (board[x+1][y-1] == 'x') { neighbors++; }
		if (board[x+1][y] == 'x') { neighbors++; }
		if (board[x+1][y+1] == 'x') { neighbors++; }
	}

	// Determine if cell is dead or alive
	if (live) { // Cell is previously alive
		if (neighbors == 2 || neighbors == 3) {
			return 1; // Cell remains alive
		} else {
			return 0; // Cell dies
		}
	} else { // Cell if previously dead
		if (neighbors == 3) { // Becomes alive
			return 1;
		} else {
			return 0; // Remains dead
		}
	}



}

// Returns 0 if cell dead and 1 if alive
void updateBoard(char board[BOARDSIZE][BOARDSIZE]) {
	// Create temp board
	char tempBoard[BOARDSIZE][BOARDSIZE] = {{' '}};
	clearBoard(tempBoard);

	// Update temp board
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			int result;
			bool live;
			
			// Check if cell is previously alive
			if (board[i][j] == 'x') {
				live = true;
			} else {
				live = false;
			}
			
			// Check if cell survies and update temp baord
			result = checkCell(board, i, j, live);
			if (result) {
				tempBoard[i][j] = 'x';
			} else {
				tempBoard[i][j] = ' ';
			}
		}
	}

	// Copy temp board to the real board
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			board[i][j] = tempBoard[i][j];
		}
	}



}

// Interactive mode function
void interactive(char board[BOARDSIZE][BOARDSIZE]) {
	bool showErr = false;
	while(true) {
		// If there is an error, dont print board and dont clear
		if (!showErr) {
			system("clear");
			printBoard(board);
		} else {
			showErr = false;
		}
		
		// Get user's command
		char choice;
		printf("Enter Command: ");
		scanf("%c", &choice);
		
		// If the user enters a get the two following digits, verify and add
		if (choice == 'a') {
			int x, y;
			scanf("%d %d", &x, &y);
			getchar();
			if (x < 1 || x > 40 || y < 1 || y > 40) {
				printf("Invalid coords. Please see help menu \'h\'.\n");
				showErr = true;
			} else {
				board[x - 1][y - 1] = 'x';
			}

		} else if (choice == 'c') { // If the user enters C, clear buffer and clear board
			getchar();
			clearBoard(board);

		} else if (choice == 'r') { // If the user enters r get two digits, validate and remove
			int x, y;
			scanf("%d %d", &x, &y);
			getchar();
			if (x < 1 || x > 40 || y < 1 || y > 40) {
				printf("Invalid coords. Please see help menu \'h\'.\n");
				showErr = true;
			} else {
				board[x - 1][y - 1] = ' ';
			}

		} else if (choice == 'n') { // If the user enters n update the board
			getchar();
			updateBoard(board);

		} else if (choice == 'q') { // Quit game
			printf("Quitting game...\n");
			return;

		} else if (choice == 'p') { // Play forever
			getchar();
			int counter = 1;
			system("clear");
			while(true) {
				updateBoard(board);
				printBoard(board);
				printf("Step: %d\n", counter);
				counter++;
				usleep(500000);
				system("clear");
			}

		} else if (choice == 'h') { // Display help menu
			getchar();
			helpMenu();
			showErr = true;

		} else { // Invalid input
			printf("Invalid input! Enter \'h\' for help.\n");
			showErr = true;
		}
	}

}

// Function for batch mode
void batch(char board[BOARDSIZE][BOARDSIZE], FILE *file) {
	int x, y;
	char line[10];
	char command;
	
	// Parse file for all commands
	while (!feof(file)) {
		fgets(line, 10, file);
		command = line[0];
		
		// If p, play forever
		if (command == 'p') {
			int counter = 1;
			system("clear");
			while(true) {
				updateBoard(board);
				printBoard(board);
				printf("Step: %d\n", counter);
				counter++;
				usleep(500000);
				system("clear");
			}
		
		// If a, add corrdinates
		} else if (command == 'a') {
			sscanf(line, "%c %d %d", &command, &x, &y);
			
			// Add one becuase I used 1-40 instead of 0-39
			x++;
			y++;

			if (x < 1 || x > 40 || y < 1 || y > 40) {
				printf("Invalid coords. Please see help menu \'h\'.\n");
			} else {
				board[x - 1][y - 1] = 'x';
			}
		}
	}

}

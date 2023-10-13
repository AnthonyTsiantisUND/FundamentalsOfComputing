/*
	Anthony Tsiantis
	playlife.c
	Fundamentals of Computing
*/

#include <stdio.h>
#include "lifefunc.h"

int main(int argc, char *argv[]) {
	// Intalize blank board
	char board[BOARDSIZE][BOARDSIZE] = {{' '}};
	clearBoard(board); // Clear the board

	
	// Validate command line arguments
	if (argc == 1) {
		printf("Entering Interactive mode...\n");
		interactive(board); // Call interactive

	} else if (argc == 2) {
		printf("Entering Batch mode...\n");
		// Get file pointer
		FILE *filePointer;
		filePointer = fopen(argv[1], "r");

		if (filePointer == NULL) {
			printf("Error opening file...");
			return 1;
		} else {
			batch(board, filePointer); // Call batch
		}

	} else {
		printf("Error: too many arguments!");

	}

	return 0;
}

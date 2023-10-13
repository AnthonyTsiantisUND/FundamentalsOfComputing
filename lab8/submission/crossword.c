/*
	Anthony Tsiantis
	Fundamentals of Computing
	crossword.c
*/
#include "crossfunc.h"


int main(int argc, char *argv[]) {
	// Word array to keep track of all words
	Word words[WORD_MAX];
	int size;
	char outFileName[MAX_FILENAME] = "";

	// Create empty board
	char board[LETTER_MAX][LETTER_MAX];
	clearBoard(board, '.');


	// Determine if file is passed through command line argument
	if (argc == 1) {
		// Get user data
		size = getData(words);

	} else if (argc == 2) { 
		// Get data from file
		char fileName[MAX_FILENAME];
		strcpy(fileName, argv[1]);
		size = getDataFile(fileName, words);

		if (size == -1) {
			return -1;
		}
		
	
	} else if (argc == 3) {
		// Get data from file
		char inFileName[MAX_FILENAME];
		strcpy(inFileName, argv[1]);
		strcpy(outFileName, argv[2]);

		size = getDataFile(inFileName, words);

		if (size == -1) {
			return -1;
		}
	
	} else {
		printf("Invalid command line usage.\n");
		return 0;
	}

	// Print to file
	if (strlen(outFileName) != 0) {
		printf("Exporting Data to file...\n");
		FILE *file;
		file = fopen(outFileName, "w");
		if (file == NULL) {
			printf("Failed to open file.\n");
			return 1;
		}
		fprintf(file, "Crossword Game: \n");	
		// Print Solution board
		fprintf(file, "\nSolution board:\n");
		findSolution(board, words, size, true);
		printBoardFile(board, file);
		
		// Print puzzle board
		fprintf(file, "\n\nCrossword board:\n");
		clearBoard(board, '#');
		printBoardFile(board, file);
		
		// Print Clues
		printCluesFile(words, size, file);
	} else { // Print to terminal
		printf("Crossword Game: \n");	
		// Print Solution board
		printf("\nSolution board:\n");
		findSolution(board, words, size, true);
		printBoard(board);
		
		// Print puzzle board
		printf("\n\nCrossword board:\n");
		clearBoard(board, '#');
		printBoard(board);
		
		// Print Clues
		printClues(words, size);
	}
	
	return 0;
}

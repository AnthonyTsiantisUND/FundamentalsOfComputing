/*
	Anthony Tsiantis
	Fundamentals of Computing
	crossfunc.c
*/
#define _GNU_SOURCE
#include "crossfunc.h"

// Clear board function
void clearBoard(char board[LETTER_MAX][LETTER_MAX], char placeholder) {
	// Populate array from start
	if (placeholder == '.') {
		for (int i = 0; i < LETTER_MAX; i++) {
			for (int j = 0; j < LETTER_MAX; j++) {
				board[i][j] = placeholder;
			}
		}
	// Create puzzle board
	} else if (placeholder == '#') {
		for (int i = 0; i < LETTER_MAX; i++) {
			for (int j = 0; j < LETTER_MAX; j++) {
				if (isalpha(board[i][j])) {
					board[i][j] = ' ';
				} else {
					board[i][j] = placeholder;
				}
			}
		}
	}
}


// Print board function
void printBoard(char board[LETTER_MAX][LETTER_MAX]) {
	// Print to console
	for (int i = 0; i <= LETTER_MAX + 1; i++) {
		for (int j = 0; j <= LETTER_MAX + 1; j++) {
			if (i == 0 || i == (LETTER_MAX + 1)) {
				printf("-");
			} else if (j == 0 || j == (LETTER_MAX + 1)) {
				printf("|");
			} else {
				printf("%c", board[i-1][j-1]);
			}
		}
		printf("\n");
	}
}

// Function prints board to specified function
void printBoardFile(char board[LETTER_MAX][LETTER_MAX], FILE *file) {
	for (int i = 0; i <= LETTER_MAX + 1; i++) {
		for (int j = 0; j <= LETTER_MAX + 1; j++) {
			if (i == 0 || i == (LETTER_MAX + 1)) {
				fprintf(file, "-");
			} else if (j == 0 || j == (LETTER_MAX + 1)) {
				fprintf(file, "|");
			} else {
				fprintf(file, "%c", board[i-1][j-1]);
			}
		}
		fprintf(file, "\n");
	}

}

// Convert a string to uppercase
void convertStrUpper(char *p) {
	while (*p != '\0') {
		if (!isupper(*p)) {
			*p = toupper(*p);
		}
		p++;
	}
}


// Function to determine if word entered is all caps and only letters
bool isStrAlpha(char *p) {
	while (*p != '\0') {
		if (!isalpha(*p)) {
			return false;
		}
		p++;
	}
	return true;
}


// Get words from user input
int getData(Word words[WORD_MAX]) {
	// Declare variables
	int size = 0;
	bool isDone = false;
	char temp[MAX_INPUT];
	int length = 0;
	
	// Notify User
	printf("Enter words one by one, max 15 characters.\n");
	
	// Get words from user
	while(!isDone) {
		// Get user input
		printf("Enter word #%d: ", size+1); 
		fgets(temp, MAX_INPUT, stdin);
		// If word add to words
		temp[strlen(temp)-1] = '\0';

		// Check if peroid is entered
		if (strcmp(temp, ".") == 0) {
			isDone = true;
			break;
		}

		// Validate string
		length = strlen(temp);
		if (length < 2 || length > 15 || !isStrAlpha(temp)) {
			printf("The word \'%s\' has been ignored because it does not follow the proper conventions.\n", temp);

		} else {
			convertStrUpper(temp);
			strcpy(words[size].word, temp);
			words[size].length = length;
			size++;
		}
		
		// If max words, quit
		if (size == 20) {
			isDone = true;
		}
	}

	return size;
}


// Get data from file
int getDataFile(char fileName[MAX_FILENAME], Word words[WORD_MAX]) {
	// Open and validate file
	FILE *filePointer = fopen(fileName, "r");
	if (filePointer == NULL) {
		printf("Error opening file.\n");
		return -1;
	}
	
	char temp[MAX_INPUT];
	int size = 0;
	int length = 0;
	
	// Get every word from file
	while(fgets(temp, MAX_INPUT, filePointer) != NULL) {
		// If word add to words
		temp[strlen(temp)-1] = '\0';

		// Check if peroid is entered
		if (strcmp(temp, ".") == 0) {
			break;
		}

		// Validate string
		length = strlen(temp);
		if (length < 2 || length > 15 || !isStrAlpha(temp)) {
			printf("The word \'%s\' has been ignored because it does not follow the proper conventions.\n", temp);

		} else {
			convertStrUpper(temp);
			strcpy(words[size].word, temp);
			words[size].length = length;
			size++;
		}
	}
	return size;

}

// Sorts the word array by size, decreasing
void sortWordsArray(Word words[WORD_MAX], int size) {
	Word temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if(words[i].length < words[j].length) {
				strcpy(temp.word, words[i].word);
				temp.length = words[i].length;
				strcpy(words[i].word, words[j].word);
				words[i].length = words[j].length;
				strcpy(words[j].word, temp.word);
				words[j].length = temp.length;
			}
		}
	}
}

// Replace place holder with word where x is constant
void updateBoard(char board[LETTER_MAX][LETTER_MAX], Word word, bool solution) {
	// Place word on board horizontally
	if (word.horizontal) {
		for (int i = 0; i < word.length; i++) {
			if (solution) {
				board[word.start.x][word.start.y+i] = word.word[i];
			} else {
				board[word.start.x][word.start.y+i] = ' ';
			}
		}
	} else { // Place word on board vertically
		for (int i = 0; i < word.length; i++) {
			if (solution) {
				board[word.start.x+i][word.start.y] = word.word[i];
			} else {
				board[word.start.x+i][word.start.y] = ' ';
			}
		}
	}
	word.placed = true;
}

// Check if letter occurs on board
Coords checkBoard(char board[LETTER_MAX][LETTER_MAX], char letter, Word word) {
	Coords temp;
	temp.x = -1;
	temp.y = -1;
	
	// Iterate through board
	for (int i = word.start.x; i < LETTER_MAX; i++) {
		for (int j = word.start.y; j < LETTER_MAX; j++) {
			if (board[i][j] == letter) {
				temp.x = i;
				temp.y = j;
				return temp;
			}
		}
	}
	
	return temp;
}


// Check if it is valid to place word vertically, 0 means no, 1 means yes
int placeVertically(char board[LETTER_MAX][LETTER_MAX], Word words[WORD_MAX], int currentWord, int charPos) {
	// Check if there is a word to the left
	if (board[words[currentWord].start.x - 1][words[currentWord].start.y] != '.') {
		return 0;
	}
	// Check if vertical placement is valid
	int startVert = words[currentWord].start.x - charPos;		
	if (startVert < 0) {
		return 0;
	} else if (startVert != 0) {
		startVert -= 1; // 1 above
	}
	
	int endVert = startVert + words[currentWord].length;
	if (endVert > 14) {
		return 0;
	} else if (endVert != 14) {
		endVert += 1; // 1 below
	}

	int leftVert = words[currentWord].start.y;
	if (leftVert !=  0) {
		leftVert -= 1; // One to the left
	}

	int rightVert = words[currentWord].start.y;
	if (rightVert != 14) {
		rightVert += 1; // One to the right
	}

	// Check
	Coords location;
	int index;
	for (int i = startVert; i <= endVert; i++) {
		for (int j = leftVert; j <= rightVert; j++) {
			if (board[i][j] != '.' && words[currentWord].start.x != i) {
				return 0;
			}
		}
	}
	return 1;
}

// Check if it is valid to place word horizontaly, 0 means no
int placeHorizontally(char board[LETTER_MAX][LETTER_MAX], Word words[WORD_MAX], int currentWord, int charPos) {
	// Check if there is a word to the left
	if (board[words[currentWord].start.x][words[currentWord].start.y - 1] != '.') {
		return 0;
	}
	
	// Check if horizontal placement is valid
	int startHori = words[currentWord].start.y - charPos;
	if (startHori < 0) {
		return 0;
	} else if (startHori != 0) {
		startHori -= 1; // 1 to the left
	}

	int endHori = startHori + words[currentWord].length;
	if (endHori > 14) {
		return 0;
	} else if (endHori != 14) {
		endHori += 1; // 1 to the right
	}

	int aboveHori = words[currentWord].start.x;
	if (aboveHori !=  0) {
		aboveHori -= 1; // One above
	}

	int belowHori = words[currentWord].start.x;
	if (belowHori != 14) {
		belowHori += 1; // One below
	}

	// Check
	Coords location;
	int index;
	for (int i = aboveHori; i <= belowHori; i++) {
		for (int j = startHori; j <= endHori; j++) {
			if (board[i][j] != '.' && words[currentWord].start.y != j) {
				return 0;
			}
		}
	}
	return 1;
}


// Returns 0 if can't place, 1 if can place vertically, 2 if can place horizontally
int validPlace(char board[LETTER_MAX][LETTER_MAX], Word words[WORD_MAX], int currentWord, int charPos) {
	if (placeVertically(board, words, currentWord, charPos)) {
		words[currentWord].horizontal = false;
		return 1;
	}

	if (placeHorizontally(board, words, currentWord, charPos)) {
		words[currentWord].horizontal = true;
		return 2;
	}

	return 0;

}

// Utilizes above function and other logic to place words on board
void findSolution(char board[LETTER_MAX][LETTER_MAX], Word words[WORD_MAX], int size, bool solution) {
	// Sort Array
	sortWordsArray(words, size);
	
	// Place longest word in center of board
	words[0].start.x = 7;
	words[0].start.y = (15 - words[0].length) / 2;
	words[0].horizontal = true;
	
	// Place first word in the center of the board
	updateBoard(board, words[0], solution);
	words[0].placed = true;
	
	
	// Place the remaining words
	bool isDone;
	int valid;
	// Iterate over every word in word list
	for (int i = 1; i < size; i++) {
		// For every character in current word, check if that character is already on the board in another word
		// Set default position
		words[i].start.x = 0;
		words[i].start.y = 0;
		for (int j = 0; j < words[i].length; j++) {
			words[i].placed = false;
			isDone = false;
			while (!isDone) {
				// Check if letter appears on board
				words[i].start = checkBoard(board, words[i].word[j], words[i]);
				
				// -1 indicates that word cannot be placed on board
				if (words[i].start.x == -1 || words[i].start.y == -1) {
					isDone = true;
				
				} else {

					// Validate placement 
					valid = validPlace(board, words, i, j);
					
					switch (valid) {
						// Can't place word
						case 0:
							if (words[i].start.x ==  14 && words[i].start.y == 14) {
								isDone = true;
							} else {
								words[i].start.y += 1; // Go to next cell
							}
							break;

						// Place word vertically
						case 1:
							words[i].start.x -= j;
							updateBoard(board, words[i], solution);
							words[i].placed = true;
							// Escape both loops
							j = words[i].length;
							isDone = true;	
							break;
						
						// Place word horizontally
						case 2:
							words[i].start.y -= j;
							updateBoard(board, words[i], solution);
							words[i].placed = true;
							// Escape both loops
							j = words[i].length;
							isDone = true;	
							break;
					}
				}
			}
		}
	}
	
	// Try to place remaining words
	int countPlaced = 0;
	isDone = false;
	while(true) {
		for (int i = 2; i < size; i++) {
			if (!words[i].placed) {
				for (int j = 0; j < words[i].length; j++) {
					while (!isDone) {
						// Check if letter appears on board
						words[i].start = checkBoard(board, words[i].word[j], words[i]);
						
						// -1 indicates word cannot be placed on boad
						if (words[i].start.x == -1 || words[i].start.y == -1) {
							isDone = true;
				
						} else {
							// Validate placement 
							valid = validPlace(board, words, i, j);
						
							switch (valid) {
								// Can't place word
								case 0:
									if (words[i].start.x ==  14 && words[i].start.y == 14) {
										isDone = true;
									} else {
										words[i].start.y += 1; // Go to next cell
									}
									break;
	
								// Place word vertically
								case 1:
									words[i].start.x -= j;
									updateBoard(board, words[i], solution);
									words[i].placed = true;
									// Escape both loops
									j = words[i].length;
									isDone = true;
									countPlaced++;
									break;
						
								// Place word horizontally
								case 2:
									words[i].start.y -= j;
									updateBoard(board, words[i], solution);
									words[i].placed = true;
									// Escape both loops
									j = words[i].length;
									isDone = true;	
									countPlaced++;
									break;
							}
						}
					}
				}
			}
		}
		// No words have been placed, exit
		if (countPlaced == 0) {
			return;
		}
	}
}

// Print Clues to terminal
void printClues(Word words[WORD_MAX], int size) {
	printf("\nClues:\n");
	printf("*Board range 0-14\n");
	printf("Coordinate (x, y) | Direction | Scambled String\n\n");
	char across[LETTER_MAX];
	char temp[LETTER_MAX];
	
	// Print all data to terminal
	for (int i = 0; i < size; i++) {
		if (words[i].placed) {
			if (words[i].horizontal) {
				strcpy(across, "Across");
			} else {
				strcpy(across, "Down");
			}
			strcpy(temp, words[i].word);
			strfry(temp);

			printf("%d, %d | %s | %s\n", words[i].start.x, words[i].start.y, across, temp);
		}
	}
	
	// Print all the words that were not able to be placed
	for (int i = 0; i < size; i++) {
		if (!words[i].placed) {
			printf("Skipped the word %s\n", words[i].word);
		}
	}

}

// Print all clues to file
void printCluesFile(Word words[WORD_MAX], int size, FILE *file) {
	fprintf(file, "\nClues:\n");
	fprintf(file, "*Board range 0-14\n");
	fprintf(file, "Coordinate (x, y) | Direction | Scambled String\n\n");
	char across[LETTER_MAX];
	char temp[LETTER_MAX];
	
	// Print all data to terminal
	for (int i = 0; i < size; i++) {
		if (words[i].placed) {
			if (words[i].horizontal) {
				strcpy(across, "Across");
			} else {
				strcpy(across, "Down");
			}
			strcpy(temp, words[i].word);
			strfry(temp);

			fprintf(file, "%d, %d | %s | %s\n", words[i].start.x, words[i].start.y, across, temp);
		}
	}
	
	// Print all words that were not able to be placed
	for (int i = 0; i < size; i++) {
		if (!words[i].placed) {
			fprintf(file, "Skipped the word %s\n", words[i].word);
		}
	}
	
}

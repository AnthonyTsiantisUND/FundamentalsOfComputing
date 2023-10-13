/*
	Anthony Tsiantis
	Fundamentals of Computing
	letterfreq.c
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define MAX_LETTERS 26

// Function Prototype
void outputData(char[], int[], int, int);

// Main function
int main() {
	// Prompt user for file name
	char fileName[30] = "";

	printf("Enter filename: ");
	fgets(fileName, 30, stdin);

	// Remove trailing newline character
	fileName[strcspn(fileName, "\n")] = 0;

	// Check if file exists (because fopen with "r" seg faults if file doesn't exist)
	if (access(fileName, F_OK) != 0) {
		printf("File does not exist in working directory!\n");
		return -1;
	}
	
	// Open file
	FILE *filePointer = fopen(fileName, "r");
	
	// Validate file is not null
	if (filePointer == NULL) {
		printf("Error opening file \'%s\'.\n");
		return -1;
	}

	// Tally character count
	int charCounts[MAX_LETTERS] = {0};
	char currentCharacter = 0;
	int charCount = -1; // Account for EOF
	
	// Parse file and count characters
	while (currentCharacter != EOF) {
		charCount++;
		currentCharacter = fgetc(filePointer);
		if (isalpha(currentCharacter)) {
			charCounts[tolower(currentCharacter) - 'a'] += 1;
		}
	}
	
	// Count letters
	int letterCount = 0;
	for (int i = 0; i < MAX_LETTERS; i++) {
		letterCount += charCounts[i];
	}


	// Output data to console
	outputData(fileName, charCounts, charCount, letterCount);

	// Format
	printf("\n\n");	

	return 0;
}

// Output function
void outputData(char fileName[], int charCounts[], int charCount, int letterCount) {
	// Print general summary
	printf("\nGeneral Summary for \'%s\':\n", fileName);
	printf("\tThere are %d total characters!\n", charCount); 
	printf("\tThere are %d total letters!\n\n", letterCount);

	// Print number of characters
	printf("Individual character count:\n");

	int spaceCounter = 0;
	for (int i = 0; i < MAX_LETTERS; i++) {
		if (spaceCounter == 5) {
			spaceCounter = 0;
			printf("\n");
		}
		printf("%c: %6d\t ", i + 'a', charCounts[i]);
		spaceCounter++;
	}
	
	// Calculate and print character percentages
	printf("\n\nCharacter Percentages: \n");

	spaceCounter = 0;
	double charPercent = 0.0;
	for (int i = 0; i < MAX_LETTERS; i++) {
		if (spaceCounter == 5) {
			spaceCounter = 0;
			printf("\n");
		}
		charPercent = ((double) charCounts[i] / letterCount) * 100;
		printf("%c: %%%3.2lf\t", i + 'a', charPercent);
		spaceCounter++;
	}
}

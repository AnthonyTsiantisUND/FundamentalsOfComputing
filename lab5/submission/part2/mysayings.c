/*
	Anthony Tsiantis
	Fundementals of Computing
	mysayings.c
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STR_LEN 256
#define MAX_ARRAY_SIZE 50
#define MAX_FILE_NAME 30

// Function Prototypes
void getFileName(char[]);
void loadData(FILE *, char[MAX_ARRAY_SIZE][MAX_STR_LEN], int);
void display(int, char[MAX_ARRAY_SIZE][MAX_STR_LEN]);
void addSaying(int, int, char[MAX_ARRAY_SIZE][MAX_STR_LEN]);
int countArraySize(int, char[MAX_ARRAY_SIZE][MAX_STR_LEN]);
void updateFile(char[MAX_ARRAY_SIZE][MAX_STR_LEN], int, char fileName[MAX_FILE_NAME]);
void displaySub(char [MAX_ARRAY_SIZE][MAX_STR_LEN], int);
void printMenu();

// Main function
int main() {
	// Get file name from user
	char fileName[MAX_FILE_NAME] = "";
	getFileName(fileName);

	// Open file 
	FILE *filePointer = fopen(fileName, "r");
	
	// Check if it exists
	if (filePointer == NULL) {
		printf("File \'%s\' does not exist!\n", fileName);
		return -1;
	}
	
	// Load data into memory
	char sayings[MAX_ARRAY_SIZE][MAX_STR_LEN] = {{}};
	int size = sizeof(sayings) / sizeof(sayings[0]);
	loadData(filePointer, sayings, size);
	int numEntries = countArraySize(size, sayings);
	
	// Main Menu loop
	int userIn;
	while(true) {
		// Print menu and get user selection
		printMenu();
		scanf("%d", &userIn);
		
		// Switch statement to handle user selection
		switch (userIn) {
			case 1:
				display(size, sayings);
				break;
			case 2:
				addSaying(size, numEntries, sayings);
				updateFile(sayings, size, fileName); // Overwrite existing file
				numEntries++;
				size = sizeof(sayings) / sizeof(sayings[0]);
				break;
			case 3:
				displaySub(sayings, size);
				break;
			case 4:
				getFileName(fileName);
				updateFile(sayings, size, fileName);
				printf("Data saved to new file: %s\n", fileName);
				break;
			case 5:
				return 0;
			default:
				printf("Invalid Input!\n");
		}

	}

	return 0;
}

// Get file name from user and update fileName array
void getFileName(char fileName[MAX_FILE_NAME]) {	
	printf("Enter filename: ");
	int remove;
	scanf("%d", &remove);
	fgets(fileName, MAX_FILE_NAME, stdin);
	fileName[strlen(fileName) - 1] = '\0';
}


// Load data from file into memory
void loadData(FILE *filePointer, char sayings[MAX_ARRAY_SIZE][MAX_STR_LEN], int size) {
	// Initalize variables
	char temp[MAX_STR_LEN];
	int counter = 0;
	
	// Infinite loop
	while(true) {
		// If end of file break
		if (fgets(temp, MAX_STR_LEN, filePointer) == NULL) {;
			break;
		}
		// remove trailing '\n'
		temp[strlen(temp)-1] = '\0';
		// Copy the string into the array
		strcpy(sayings[counter], temp);
		// Increase counter
		counter++;
	}
}

// Display sayings to screen
void display(int size, char sayings[MAX_ARRAY_SIZE][MAX_STR_LEN]) {
	// Format
	printf("\n");

	// Iterate through array and print
	for (int i = 0; i < size; i++) {
		if (strlen(sayings[i]) != 0) {
			printf("%d: %s\n", i+1, sayings[i]);
		}
	}
	// Format
	printf("\n");
}


// Save array to file
void updateFile(char sayings[MAX_ARRAY_SIZE][MAX_STR_LEN], int size, char fileName[MAX_FILE_NAME]) {
	// create(overwrite) new file
	FILE* filePointer = fopen(fileName, "w"); 
	
	// Iterate over array and print line to file
	for (int i = 0; i < size; i++) {
		if (strlen(sayings[i]) != 0) {
			fprintf(filePointer, "%s\n", sayings[i]);
		}
	}

	fclose(filePointer); // Save the file
}

// Add new saying to file
void addSaying(int size, int numEntries, char sayings[MAX_ARRAY_SIZE][MAX_STR_LEN]) {
	// create a temp string
	char temp[MAX_STR_LEN];
	// Temp variable to remove \n from buffer
	int remove;
	printf("Enter the saying you would like to add: ");
	scanf("%d", &remove); // Get rid of '\n' remaining in buffer
	// Get user saying
	fgets(temp, MAX_STR_LEN, stdin);
	temp[strlen(temp)-1] = '\0';
	
	// Add saying to array and print all sayings
	strcpy(sayings[numEntries], temp);
	display(size, sayings);
}

// Get number of sayings in array
int countArraySize(int size, char sayings[MAX_ARRAY_SIZE][MAX_STR_LEN]) {
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (strlen(sayings[i]) != 0) {
			counter++;
		}
	}
	return counter;
}

// Display all substrings within a string
void displaySub(char sayings[MAX_ARRAY_SIZE][MAX_STR_LEN], int size) {
	// Get substring from user
	char substring[MAX_STR_LEN] = "";
	printf("Enter substring: ");

	// Remove \n in buffer
	int remove;
	scanf("%d", &remove); 

	fgets(substring, MAX_STR_LEN, stdin);

	// remove newline character
	substring[strlen(substring) - 1] = '\0';
	
	// Print all the strings that contain the substring
	for (int i = 0; i < size; i++) {
		if (strstr(sayings[i], substring) != NULL) {
			printf("The string \'%s\' contains the substring \'%s\'\n", sayings[i], substring);
		}
	}
	printf("\n");

}


// Print menu function
void printMenu() {
	printf("1. Display all sayings currently in the database.\n");
	printf("2. Enter a new saying into the database.\n");
	printf("3. List sayings that contain a given string entered by the user\n");
	printf("4. Save all sayings in a new text file\n");
	printf("5. Quit\n");
	printf("Enter your selection: ");
}

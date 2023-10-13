/*
	Anthony Tsiantis
	Fundementals of Computing
	ndfootball.c
*/

// Include libraries
#include <stdio.h>
#include <stdbool.h>

// Include "wins[]" and "losses[]"
#include "nd_data.h"

// Function Prototypes
void printMenu();
void bestWorstRecord(bool, int);
void moreWins(int);
void printYear(int);
void leastWinsLosses(bool, int);
void bestWorstRecord2(bool, int);


// Main function
int main() {
	// Variable declaration
	int userInput;
	bool isDone = false;

	// Find size of array
	int size = sizeof(wins) / sizeof(wins[0]);
	
	// Main Loop 
	while (!isDone) {
		// Print menu and get user input
		printMenu();
		scanf("%d", &userInput);
		
		// Switch statement to handle user input
		switch(userInput) {
			case 1:
				bestWorstRecord(true, size);
				break;

			case 2:
				bestWorstRecord(false, size);
				break;

			case 3:
				moreWins(size);
				break;

			case 4:
				printYear(size);
				break;
			case 5:
				leastWinsLosses(true, size);
				break;
			case 6:
				leastWinsLosses(false, size);
				break;
			case 7:
				bestWorstRecord2(true, size);
				break;

			case 8:
				bestWorstRecord2(false, size);
				break;
			
			case 9:
				isDone = true;
				break;

			default:
				printf("Invalid input!");
		}

	}

	return 0;
}

// Prints the menu
void printMenu() {
	printf("\n");
	printf("1. Print the year(s) with the best record.\n");
	printf("2. Print the year(s) with the worst record.\n");
	printf("3. Print the years with more wins than loses.\n");
	printf("4. Print the record for a given year.\n");
	printf("5: Print the year(s) with at least \'x\' wins.\n");
	printf("6: Print the year(s) with at least \'x\' losses.\n");
	printf("7: Print the year(s) with the best record (factoring in games played).\n");
	printf("8: Print the year(s) with the worst record (Factoring in games played).\n");
	printf("9: Exit.\n");
	printf("Enter your choice: ");
}

void bestWorstRecord(bool best, int size) {
	printf("\n");
	// Initalize Variables
	int currentRecord;
	int extremeRecord; // Keep track of most extreme record (Max or Min)

	// If best record
	if (best) {
		// Calculate record
		for (int i = 0; i < size; i++) {
			currentRecord = wins[i] - losses[i];

			// Initalize extreme record to first record
			if (i == 0) {
				extremeRecord = currentRecord; 
			}

			// Update extreme record
			if (currentRecord > extremeRecord) {
				extremeRecord  = currentRecord;
			}
		}

		// Print years with that record
		for (int i = 0; i < size; i++) {
			currentRecord = wins[i] - losses[i];
			if (currentRecord == extremeRecord) {
				printf("The year %d had the best record of +%d (W/L)\n", i + 1900, extremeRecord);
			}
		}
		
	} else { // If worst record

		// Calculate record
		for (int i = 0; i < size; i++) {
			currentRecord = wins[i] - losses[i];

			// Initalize extreme record to first record
			if (i == 0) {
				extremeRecord = currentRecord; 
			}

			// Update extreme record
			if (currentRecord < extremeRecord) {
				extremeRecord  = currentRecord;
			}
		}

		// Print years with that record
		for (int i = 0; i < size; i++) {
			currentRecord = wins[i] - losses[i];
			if (currentRecord == extremeRecord) {
				printf("The year %d had the worst record of %d (W/L)\n", i + 1900, extremeRecord);
			}
		}

	}

}


void moreWins(int size) {
	int currentRecord;
	printf("\n");
	for (int i = 0; i < size; i++) {
		currentRecord = wins[i] - losses[i];
		if (currentRecord > 0) {
			printf("%d had a record of +%d\n", i+1900, currentRecord);
		}
	}
}


void printYear(int size) {
	// Initalize Variables
	int userYear;
	int index;

	// Infinite loop
	while (true) {
		// Get year from user
		printf("\nEnter the year: ");
		scanf("%d", &userYear);
		
		// Validate input
		if ((userYear > 2022) || (userYear < 1900)) {
			printf("Invalid input!");
		} else {
			break;
		}
	}
	
	// Get index
	index = userYear - 1900;
	
	// Output record
	printf("The record for %d was W%d-L%d.\n", userYear, wins[index], losses[index]);
}

void leastWinsLosses(bool win, int size) {
	// Initalize Variables
	int cutoff;
	int current;
	int counter;

	// If user selected least wins
	if (win) {
		// Get cutoff
		printf("Enter the win cutoff (inclusive): ");
		scanf("%d", &cutoff);
		
		printf("\n");
		
		// Find all the years with that cutoff and print
		counter = 0;
		for (int i = 0; i < size; i++) {
			current = wins[i];

			if (current >= cutoff) {
				printf("The year %d had %d wins.\n", i+1900, wins[i]);
				counter++;
			}
		}
		
		// If there are no years with that cutoff print
		if (counter == 0) {
			printf("There are no years with at least %d wins.\n", cutoff);
		}

	} else { // If user selected least losses
		// Get user cutoff
		printf("Enter the loss cutoff (inclusive): ");
		scanf("%d", &cutoff);
		
		printf("\n");
		
		// Find all the years with that cutoff and print
		counter = 0;
		for (int i = 0; i < size; i++) {
			current = losses[i];

			if (current >= cutoff) {
				printf("The year %d had %d losses.\n", i+1900, losses[i]);
				counter++;
			}
		}
		
		// If no years were printed 
		if (counter == 0) {
			printf("There are no years with at least %d losses.\n", cutoff);
		}

	}
}


void bestWorstRecord2(bool best, int size) {
	printf("\nRecord is calculated as such: (Wins - Losses) / games played\n\n");
	
	// If best record
	if (best) {
		// Initalize Variables
		double records[size];
		double bestRecord;
		double currentRecord;
		
		// Calculate every record and find best record
		for (int i = 0; i < size; i++) {
			currentRecord = (double) (wins[i] - losses [i]) / (double) (wins[i] + losses[i]);
			records[i] = currentRecord;

			if (i == 0) { 
				bestRecord = currentRecord;
			}


			if (currentRecord > bestRecord) {
				bestRecord = currentRecord;
			}
		}
		
		// Print years with the best record
		for (int i = 0; i < size; i++) {
			if (records[i] == bestRecord) {
				printf("%d had a win percentage of of %.2lf%\n", i+1900, bestRecord*100);
			}
		}
	
	} else { // If worst record
		// Initalize variables
		double records[size];
		double worstRecord;
		double currentRecord;
		
		// Update records and find worst record
		for (int i = 0; i < size; i++) {
			currentRecord = (double) (wins[i] - losses [i]) / (double) (wins[i] + losses[i]);
			records[i] = currentRecord;

			if (i == 0) { 
				worstRecord = currentRecord;
			}


			if (currentRecord < worstRecord) {
				worstRecord = currentRecord;
			}
		}
		
		// Print all the years with the worst record
		for (int i = 0; i < size; i++) {
			if (records[i] == worstRecord) {
				printf("%d had a loss percentage of %.2lf%\n", i+1900, worstRecord*-100);
			}
		}
	}
}



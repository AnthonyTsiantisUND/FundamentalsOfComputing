/*
	Anthony Tsiantis
	Fundementals of Computing
	menucalc.c
*/

// Import libraries
#include <stdio.h>
#include <stdbool.h>

// Declare functions
void printMenu();
void calculateOutput();
int getOperation();

// Main loop
int main() {
	// Declare function
	int operation;
	double number1, number2;
	bool isDone = false;

	// Infinite loop
	while (!isDone) {
		// Call print menu function and get operation
		printMenu();
		operation = getOperation();
		
		// If user wants to quit, quit
		if (operation == 5) {
			isDone = true;
			printf("Good bye!\n");
			continue;
		}
		
		// Get the two numbers
		printf("\nEnter two numbers: ");
		scanf("%lf %lf", &number1, &number2);
		
		// Calculate output and print to console
		calculateOutput(operation, number1, number2);
	}

	return 0;
}

// Get and validate operation from user
int getOperation() {
	// Initalize variable
	int operation;	
	
	// Infinite loop
	while (true) {
		// Get user input
		printf("Enter your operation: ");
		scanf("%d", &operation);
		
		// If user input is invalid, reprompt the user, else return
		if (operation < 1 || operation > 5) {
			printf("\nInvalid input!\n");
		} else {
			return operation;
		}
	}
}

// Calculate and output function
void calculateOutput(int operation, double number1, double number2) {
	// For each operation, calculate and output line
	if (operation == 1) {
		printf("\n%.2lf + %.2lf = %.2lf\n", number1, number2, number1 + number2);
	} else if (operation == 2) {
		printf("\n%.2lf - %.2lf = %.2lf\n", number1, number2, number1 - number2);
	} else if (operation == 3) {
		printf("\n%.2lf * %.2lf = %.2lf\n", number1, number2, number1 * number2);
	} else {
		// If statement to catch division by zero
		if (number2 != 0) {
			printf("\n%.2lf / %.2lf = %.2lf\n", number1, number2, number1 / number2);
		} else {
			printf("\nError: Division by zero! \n");
		}
	}

}

// Print menu function
void printMenu() {
	printf("\nWhat would you like to do?\n");
	printf("1 - addition\n");
	printf("2 - subraction\n");
	printf("3 - multiplication\n");
	printf("4 - Division\n");
	printf("5 - Exit\n" );
}



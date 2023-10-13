// Author: Anthony Tsiantis

// import libs
#include <stdio.h>
#include <math.h>

// Main function
int main() {
	// Initalize variables
	int x, y;
	
	// Get user input and populate variables
	printf("\nEnter two integer values (row column): ");
	scanf("%d %d", &x, &y);

	// Format table
	printf("\n\n *  ");
	
	// Output top header
	for (int i = 1; i <= y; i++) {
		printf("%4d", i);
	}

	// Format
	printf("\n    ");
	for (int i = 1; i <= y; i++) {
		printf("----");
	}
	printf("\n");
	

	// Calculate and print out rows
	for (int i = 1; i <= x; i++) {
		printf("%2d |", i);

		for (int j = 1; j <= y; j++) {
			printf("%4d", (i*j));
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}

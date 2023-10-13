/*
	Anthony Tsiantis
	Fundementals of Computing
	usastates.c
*/

#include "statesfunc.h"

int main() {
	// Create data array
	State states[MAX_STATE];
	
	// get filename
	char filename[MAX_FILENAME];
	getFilename(filename);

	// Get data from file
	int size = getData(states, filename);
	if (size == -1) {
		return size;
	}
	
	// Display menu and handle user input
	int userInput;
	while(true) {
		printMenu();
		scanf("%d", &userInput);

		switch (userInput) {
			case 1:
				listAllData(states, size);
				break;
			case 2:
				listName(states, size);
				break;
			case 3:
				listCapital(states, size);
				break;
			case 4:
				joinedYear(states, size);
				break;
			case 5:
				joinedBeforeYear(states, size);
				break;
			case 6:
				printf("Exiting...\n");
				return 0;
			default:
				printf("Invalid Input!\n");
		}


	}

	return 0;
}

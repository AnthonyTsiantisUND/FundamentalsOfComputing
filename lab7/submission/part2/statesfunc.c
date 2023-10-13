/*
	Anthony Tsiantis
	Fundementals of Computing
	statesfunc.c
*/

#include "statesfunc.h"

// Get filename from user
void getFilename(char filename[MAX_FILENAME]) {
	printf("Enter filename: ");
	fgets(filename, MAX_FILENAME, stdin);
	filename[strlen(filename)-1] = '\0';
}



// Get data function populates states array with data from csv
int getData(State states[MAX_STATE], char filename[MAX_FILENAME]) {
	// Count number of states
	int counter = 0;
	
	// Open file and validate existence
	FILE *filePointer = fopen(filename, "r");
	if (filePointer == NULL) {
		printf("Unable to open file \'%s\'.\n", filename);
		return -1;
	}
	
	// Parse file and populate states array
	char line[MAX_LINE];
	char *field;
	int year;
	State temp;
	while (fgets(line, MAX_LINE, filePointer) != NULL) {
		field = strtok(line, DELIM);
		strcpy(temp.state_abbr, field);
		field = strtok(NULL, DELIM);

		strcpy(temp.state_name, field);
		field = strtok(NULL, DELIM);

		strcpy(temp.capital, field);
		field = strtok(NULL, DELIM);

		temp.year = atoi(field);
		field = strtok(NULL, DELIM);

		states[counter] = temp;
		counter++;
	}
	
	return counter; // return size
}

// Function to iterate over states array and list all the data
void listAllData(State states[MAX_STATE], int size) {
	printf("\nAbbreviation, State, Capital, Year Joined\n");
	for(int i = 0; i < size; i++) {
		printf("%s, ", states[i].state_abbr);
		printf("%s, ", states[i].state_name);
		printf("%s, ", states[i].capital);
		printf("%d\n", states[i].year);
	}
	printf("\n");
}

// Function to get the state abbreviation (case insensitive)
void getState(char stateAbbr[MAX_ABBR]) {
	// Get and clean user input
	printf("\nEnter state abbreviation: ");
	fgets(stateAbbr, MAX_ABBR, stdin);
	int length = strlen(stateAbbr);
	stateAbbr[length-1] = '\0';
	length--;
	
	// Make case insensitive
	for (int i = 0; i < length; i++) {
		if (islower(stateAbbr[i])) {
			stateAbbr[i] = stateAbbr[i] - 32;
		}
	}
}

// Function to list the full name of the state given the abbreviation
void listName(State states[MAX_STATE], int size) {
	// Get abbreviation from user
	char stateAbbr[MAX_ABBR];
	getchar();
	getState(stateAbbr);
	
	int counter = 0;

	// Find the state that is abberviated as such
	for(int i = 0; i < size; i++) {
		if (strcmp(states[i].state_abbr, stateAbbr) == 0) {
			printf("%s is abbreviated as %s\n", states[i].state_name, stateAbbr);
			counter++;
		}
	}
	
	// If no states with abbreviation
	if (counter == 0) {
		printf("No state with abbreviation %s.\n", stateAbbr);
	}

	printf("\n");
}

// Function to list the capital of a state given the abbreviation
void listCapital(State states[MAX_STATE], int size) {
	// Get state abbreviation from user
	char stateAbbr[MAX_ABBR];
	getchar();
	getState(stateAbbr);
	
	int counter = 0;
	
	// Find the capital of that state
	for(int i = 0; i < size; i++) {
		if (strcmp(states[i].state_abbr, stateAbbr) == 0) {
			printf("The capital of %s is %s.\n", states[i].state_name, states[i].capital);
			counter++;
		}
	}
	
	// If no states with abbreviation
	if (counter == 0) {
		printf("No state with abbreviation %s.\n", stateAbbr);
	}
	
	printf("\n");
}

// Get the year from the user
int getYear() {
	int year;
	printf("Enter the year: ");
	scanf("%d", &year);
	return year;
}

// Print all the states that joined on user entered year
void joinedYear(State states[MAX_STATE], int size) {
	int year = getYear();
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (year == states[i].year) {
			printf("- %s joined the union in %d\n", states[i].state_name, states[i].year);
			counter++;
		}
	}
	
	// Print if no states joined the union on that year
	if (counter == 0) {
		printf("No states joined the union during %d.\n", year);
	}

	printf("\n");

}

// Print all the states that joined before user entered year
void joinedBeforeYear(State states[MAX_STATE], int size) {
	int year = getYear();
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (year > states[i].year) {
			printf("- %s joined the union in %d\n", states[i].state_name, states[i].year);
			counter++;
		}
	}
	
	// Print if no states joined before that year
	if (counter == 0) {
		printf("No states joined the union before %d.\n", year);
	}

	printf("\n");
}

// Print the menu to the screen
void printMenu() {
	printf("1: List all data\n");
	printf("2: List full state name based on abbreviation\n");
	printf("3: List state capital based on abbreviation\n");
	printf("4: List state that joined on year x\n");
	printf("5: List states that joined before year x\n");
	printf("6: Exit\n");
	printf("Enter your selection: ");
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	int n;

	srand(time(0)); // random number seed
	for (int i = 0; i <= 10; i++) { 
		n = rand(); // Returns an int from 0 - max int
		printf("%d\n", n);
		n = rand() % 6 + 1; // Simulates a dice roll, but returns the same random numbers
		printf("%d\n", n);
	}


	
	return 0;
}

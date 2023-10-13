/*
	Anthony Tsiantis
	Fundementals of Computing
	primes.c
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int main() {
	
	// Create and populate array (1-1000 exclusive)
	int primes[998];
	int size = sizeof(primes) / sizeof(primes[0]);
	for (int i = 0; i < size; i++) { 
		primes[i] = true;
	}

	// Determine primes (0th index indicates 2)
	int currentNumi, currentNumj;
	for (int i = 0; i < size; i++) {
		currentNumi = i + 2;
		for (int j = i + 1; j < size; j++) {
			currentNumj = j + 2;
			if (currentNumj % currentNumi == 0) {
				primes[j] = false;
			}
		}
	}

	
	// Output to console
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (!(counter < 10)) {
			printf("\n");
			counter = 0;
		}

		if (primes[i]) {
			printf("%3d ", i+2);
			counter++;
		}
	}

	printf("\n");
	return 0;
}

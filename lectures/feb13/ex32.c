#include <stdio.h>


int main() {
	// size is determined when array is instantiated at declaration
	// Only use '10' size when not initalizing
	int c[10] = {33, 24, 53, 76, 48, 9, 33, 25, 41, 21};

	/* You cannot asign a value to an array outside of declaration
	int c;
	c = {33, 24, 53, 76, 48, 9...}]

	^This wont work
	*/
	
	// Calculate the size of the array
	int n;

	for (int i = 0; i < 10; i++) {
		printf("%d\n", c[i]);
	}

	n = 345;
	printf("n is: %d\n", n);
	
	c[10] = 17; // Out of bounds, changes the value of n
	printf("n is: %d\n", n);

	return 0;
}

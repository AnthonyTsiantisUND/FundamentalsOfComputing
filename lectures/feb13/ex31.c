#include <stdio.h>


int main() {
	// size is determined when array is instantiated at declaration
	int b[] = {33, 24, 53, 76, 48, 9, 33, 25, 41, 21};
	
	// Calculate the size of the array
	int size = sizeof(b) / sizeof(b[0]);;

	for (int i = 0; i < size; i++) {
		printf("%d\n", b[i]);
	}

	return 0;
}

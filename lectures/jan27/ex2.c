#include <stdio.h>

int main() {
	// The result of an operation will always return the more percise data type

	int a, b, c;
	a = 12;
	b = 5;

	float x = a/b; // Integer division assigned to a float (doesn't work)
	
	printf("x: %f\n", x);	

	float y;

	return 0;
}


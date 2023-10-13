#include <stdio.h>

int main() {
	int a, b;

	a = 12;
	b = 5;

	// Sytatic sugar
	a++; // Increment by one
	printf("a: %d\n", a);
	b--; // decrement by one
	printf("b: %b\n", b);

	int c = 45;
	c += 12;
	printf("c: %d\n", c);
	// also  -=, *=, /=, %=
	

	float z = (1/2) * (5+7); // The integer division (1/2) will be 0!

	float z = (1./2) * (5+7); // Not integer division (1/2) will be 0.5!

	return 0;
}


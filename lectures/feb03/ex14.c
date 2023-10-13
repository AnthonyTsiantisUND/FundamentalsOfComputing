#include <stdio.h>

int main() {
	int n;

	int a, b;

	printf("Enter a number: ");
	scanf("%d", &n);

	// Switch Statement allows for continuity
	switch(n) {
		case 1:
			a = 3;	
			b = 4;
			break;
		case 2:
			a = 5;	
			b = 2;
			break;
		case 3:
			a = 15;	
			b = 21;
			break;
		default:
			a = 0;	
			b = 10;
			break;
	}

	printf("a: %d	b: %d\n", a, b);
	return 0;
}

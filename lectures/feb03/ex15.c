#include <stdio.h>

int main() {
	int n, a;

	printf("Enter a number: ");
	scanf("%d", &n);

	if (n > 0) {
		a = 3;
	} else {
		a = 7;
	}

	// Ternary operator ?: operator

	a = (n > 0) ? 3 : 7;

	int x, y, z, max;
	
	printf("Enter three numbers: ");
	scanf("%d %d %d", &x, &y, &z);
	
	max = (x > y) ? ( (x > z) ? x : z ) : (y > z) ? y : z;

	printf("%d", max);
	printf("\n");

	return 0;
}

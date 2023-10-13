#include <stdio.h>

int main() {
	int a, b, c;
	a = 34;
	b = 12456;
	c = 567;

	printf("%6d\n", a); // formats numbers to 6 spaces
	printf("%6d\n", b);
	printf("%6d\n", c);

	float x = 5.638;
	printf("x: %f\n", x);	
	printf("x: %8.2f\n", x); // 8 refers to the total width	

	return 0;
}


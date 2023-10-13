#include <stdio.h>

int main() {
	int n = 1;
	
	// Condition controlled loop
	while (n <= 10) {
		printf("%d", n);
		n++;
	}
	printf("\n");

	printf("n is now: %d\n");
	
	// Counter Controlled Loop
	for (int i = 1; i <= 10; i++) {	
		printf("%d", i);
	}
	printf("\n");

	return 0;
}

// 1. Initalization
// 2. Repitition condition
// 3. Update 

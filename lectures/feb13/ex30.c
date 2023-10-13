#include <stdio.h>


int main() {
	int b[10];

	for (int i = 0; i < 10; i++) {
		printf("%d\n", b[i]); // Prints out random unassigned locations in memory
	}

	return 0;
}

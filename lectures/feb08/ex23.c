#include <stdio.h>
#include <stdbool.h>

int main() {
	int n;
	
	n = 1;
	while (n <= 5) {
		printf("%d ", n);
		n++;

	}
	printf("\n");

	n = 1;
	while (true) {
		printf("%d ", n);
		if (n == 5) {
			break;
		}
		n++;
	}
	printf("\n");

	n = 1;
	bool isDone = false;

	while (!isDone) {
		printf("%d ", n);
		if (n == 5) {
			isDone = true;
		}
		n++;
	}

	printf("\n");

	return 0;
}

#include <stdio.h>

int main() {
	int n = 1;

	while(n <= 10) {
		printf("n: %2d\n", n);
		if (n == 5) {
			break;
		}
		n++;
	}

	return 0;
}


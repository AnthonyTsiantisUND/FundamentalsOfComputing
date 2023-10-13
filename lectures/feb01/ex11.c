#include <stdio.h>

int main() {

	int sum = 0;
	
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 2; j++) {
			sum += i*j;
		}
	}

	printf("sum is: %d\n", sum);

	return 0;
}

#include <stdio.h>

int main() {
	int n;

	int a, b;

	printf("Enter a number: ");
	scanf("%d", &n);

	if (n == 1) {
		a = 3;
		b = 4;
	} else if (n == 2) {
		a = 5;
		b = 2;
	} else if (n == 3) {
		a = 15;
		b = 21;
	} else {
		a = 0;
		b = 10;
	}
	
	return 0;
}

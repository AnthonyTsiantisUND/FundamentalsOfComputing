#include <stdio.h>

void func1(int);
void func2(int*);

int main() {
	int n = 15;
	printf("n: %d\n", n);

	func1(n);
	printf("n: %d\n", n);
	
	// Pass a regular variable by reference in c
	func2(&n);
	printf("n: %d\n", n);

	return 0;
}

void func1(int n) {
	n = 33;
}

void func2(int *p) {
	*p = 33;
}

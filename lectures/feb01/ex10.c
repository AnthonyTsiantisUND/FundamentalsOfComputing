#include <stdio.h>
#define NUM 55
#define VAL 4+3

int main() {
	printf("%d\n", VAL);

	int n = 2*VAL; // Be cautious of this

	printf("%d\n", n);
	return 0;
}

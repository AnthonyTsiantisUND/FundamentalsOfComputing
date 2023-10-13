#include <stdio.h>


int main() {
	int a[5]; // Declare integer array of size 5

	printf("%d\n", sizeof(a));

	a[0] = 34;
	a[1] = 13;
	a[2] = 8;
	a[3] = 63;
	a[4] = 71;
	
	for(int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");


	return 0;
}

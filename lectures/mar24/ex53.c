#include <stdio.h>


int main() {
	int arr[5] = {34, 52, 64, 23, 71};

	int *p;
	p = &arr[0];
	p = arr; // The name of the array is the address of the first element of the array

	printf("%d\n", *p);
	
	// Get the second elemnt of the array
	p++; // goes to the next int (adds 4 instead of 1)
	printf("%d\n", *p);

	p = arr; // reset pointer
	
	for (int i = 0; i < 5; i++) {
		printf("%d\n", *p);
		p++;
	}

	return 0;
}

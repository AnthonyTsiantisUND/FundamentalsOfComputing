#include <stdio.h>


int main() {
	int num;
	num = 27;

	printf("%d\n", num); // display the value of num

	int *p; // p is a pointer to integer
	p = &num;

	*p = 35;
	printf("%d\n", num);

	(p*)++;
	printf("%d\n", num);
	 

	return 0;
}

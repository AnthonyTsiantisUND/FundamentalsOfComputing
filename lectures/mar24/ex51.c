#include <stdio.h>


int main() {
	int num;
	num = 27;

	printf("%d\n", num); // display the value of num
	printf("%x\n", &num); // Display the address of num (hexadecimal)
	printf("%p\n", &num); // Display the address of num (memory section + hexadecimal)
	
	// Once a variable has been declared its address cannot be changed
	num++;
	printf("%d\n", num); // display the value of num
	printf("%x\n", &num); // Display the address of num (hexadecimal)

	int *p; // p is a pointer to integer
	p = &num;

	// Dereferencing a pointer
	printf("value: %d\n", *p); // *p is the content of what the pointer points too, in read mode

	printf("address: %x\n", p); // p is the address of what the pointer points too

	*p = 35; // write mode, overwrites the value of num
	printf("%d\n", num);


/*
	Three different ways to setup a pointer
	int *p;
	int * p;
	int* p;
*/



	return 0;
}

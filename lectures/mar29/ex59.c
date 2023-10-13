#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char str[20];
	/*
		Cannot do:
		str = "notre dame";
	*/
	strcpy(str, "notre dame");
	
	char *p;
	/*
		Cannot do:
		strcpy(p, "notre dame");
		memory was not allocated for p
	*/
	p = "champions next year";


	char *a;
	char buff[30]; // Static memory allocation
	a = buff;
	strcpy(a, "whatever thing");
	printf("%s\n", a);

	// Malloc allocates memory on the heap
	// Everything else allocates memory on the stack
	char *b;
	b = malloc(30*sizeof(char)); // Returns a pointer to memory location
	strcpy(b, "whatever thing");
	printf("%s\n", b);

	free(b);

	return 0;
}

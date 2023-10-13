#include <stdio.h>

void greetings(void);
// or --> void greetings();
// The defualt return data type is int for a function

void display(int);

int main() {
	greetings ();

	int num = 34;
	display(num);

	return 0;
}

void greetings(void) {
	printf("Hi everyone!\n");
}

// You can have a return in a void function as long at it is just the return statement
void display(int a) {
	printf("The value is: %d\n", a);
	return; // This will work but it is not nessecary, function returns by default
}

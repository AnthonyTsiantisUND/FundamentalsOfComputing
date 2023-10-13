#include <stdio.h>
#define AGE 10 // Global macro, constant value and non mutable

int num = 23; // Also, global varibale

// In general, global variables are bad practice

int main() {
	printf("%d\n", AGE);

	{
		int c;
		// Even though there is no while/for/if... here c is local to the curly braces
	
	}
	return 0;
}

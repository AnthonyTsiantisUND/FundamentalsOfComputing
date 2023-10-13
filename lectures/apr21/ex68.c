#include <stdio.h>

void func(int);

int main() {
	func(0);
	
	return 0;
}

void func(int n) {
	printf("Hello %d\n", n);
	if (n == 50) { return; } // goes back to where the function was call
	func(n+1);
	printf("Is this going to print? %d\n", n); // becuase of line 13 there is a backtrack and thus the memory is called back from the stack.

}

#include <stdio.h>

void func(void);

int main() {

	for (int i = 1; i <= 5; i++) {
		func();
	}	


	return 0;
}

void func(void) {
	static int n = 11; // n is only intalizized once and perminent within function scope.
	printf("n is: %d\n", n);
	n++;

}

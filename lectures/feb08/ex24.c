#include <stdio.h>
#include <stdbool.h>

int main() {
	int a, b;
	bool exit = false;


	for (a = 101; a <= 105; a++) {
		printf("%d: ", a);
		for (b = 1; b <= 10; b++) {
			printf("%d ", b);
			if (a == 103 && b == 7) {
				exit = true;
				break;
			}
		}
		printf("\n");
		if(exit) {
			break;
		}
	}
	return 0;
}

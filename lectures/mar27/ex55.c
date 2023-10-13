#include <stdio.h>

void swap(int*, int*);

int main() {
	int n1 = 7, n2 = 5;

	printf("n1: %d; n2: %d\n", n1, n2);
	int temp;

	swap(&n1, &n2);

	printf("n1: %d; n2: %d\n", n1, n2);


}

void swap(int *p1, int *p2) {
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;

}

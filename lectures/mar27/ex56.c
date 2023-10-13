#include <stdio.h>

void compute(int, int, int*, int*);
void display(int, int, int, int);

int main() {
	int a, b, sum, diff;
	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);

	compute(a, b, &sum, &diff);
	display(a, b, sum, diff);

}

void compute(int a, int b, int *ps, int *pd) {
	*ps = a + b;
	*pd = a - b;

}

void display(int a, int b, int sum, int diff) {
	printf("%d + %d = %d\n", a, b, sum);
	printf("%d - %d = %d\n", a, b, diff);
}


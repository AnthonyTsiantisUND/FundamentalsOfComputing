#include <stdio.h>
#include <math.h>

int main() {
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);
	
		
	printf("n is %d\n", n);

	float x, y;

	printf("Enter two numbers: ");
	scanf("%f %f", &x, &y);

	printf("Their sum is %g\n", x+y);
	printf("The square root of x %f is %f\n", x, sqrt(x));	
	return 0;
}

#include <stdio.h>


int main() {
	int n = 5;
	float x = 3.75;
	double y = 36.13;

	int *p1;
	float *p2;
	double *p3;

	p1 = &n;
	p2 = &x;
	p3 = &y;

	printf("%d\n", *p1);
	printf("%.3f\n", *p2);
	printf("%.3lf\n", *p3);

	// Void pointer is like a universal datatype pointer
	void *p;

	p = &n;
	printf("\n\n%d\n", *(int *)p); // Must typecast

	p = &x;
	printf("%.3f\n", *(float *)p);

	p = &y;
	printf("%.3lf\n", *(double *)p);

	return 0;
}

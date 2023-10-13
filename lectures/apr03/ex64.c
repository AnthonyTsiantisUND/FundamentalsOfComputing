#include <stdio.h>


int main() {
	int n = 5;
	float x = 3.75;
	double y = 36.13;
	char str[] = "notre dame";

	// Void pointer is like a universal datatype pointer
	void *p;

	p = &n;
	printf("%d\n", *(int *)p); // Must typecast

	p = &x;
	printf("%.3f\n", *(float *)p);

	p = &y;
	printf("%.3lf\n", *(double *)p);

	p = str;
	printf("%s\n", (char *)p);

	return 0;
}

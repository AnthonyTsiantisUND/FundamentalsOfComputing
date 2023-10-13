#include <stdio.h>

float sum(float a, float b) {
	return (a+b);
}

float difference(float a, float b) {
	return (a-b);
}

float product(float a, float b) {
	return (a*b);
}

float quotient(float a, float b) {
	return (a/b);
}

void showinfo(float x, float y) {
	printf("Their sum is %g\n", sum(x, y));
	printf("Their difference is %g\n", difference(x, y));
	printf("Their product is %g\n", product(x, y));
	printf("Their quotient is %g\n", quotient(x, y));
}


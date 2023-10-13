#include <stdio.h>
#include <math.h>

double taylor(double);
double taylorrec(double, int);

int main() {
	double x = 0.1;
	printf("Using loop: %lf\n", taylor(x));
	printf("Using recusion: %lf\n", taylorrec(x, 0));

	return 0;
}

double taylor(double x) {
	int counter = 0;
	double next, sum = 0;

	while(1) {
		next = pow(x, counter);
		if (next < 0.001) { return sum; }

		sum += next;
		counter++;
	}
}

double taylorrec(double x, int n) {
	double next = pow(x, n);
	if (next < 0.001) {
		return next;
	} else {
		n++;
		return taylorrec(x, n) + next;
	}
}

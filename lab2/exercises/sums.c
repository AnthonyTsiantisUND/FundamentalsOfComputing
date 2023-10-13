#include <stdio.h>
#include <math.h>

int main() {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	int sum1 = 0;
	double sum2 = 0.0;

	for (int i = 1; i <= num; i++) {
		sum1 += pow(i, 2);
		sum2 += sqrt(i);
	}
	printf("The first sum is %d\n", sum1);
	printf("The second sum is %lf\n", sum2);

	return 0;
}

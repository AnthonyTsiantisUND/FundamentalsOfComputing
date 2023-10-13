#include <stdio.h>

int get_gcd(int, int);





int main() {
	int a, b;
	printf("Enter two integers: ");
	scanf("%d %d", &a, &b);
	
	int gcd = get_gcd(a, b);

	if (gcd == 0) {
		printf("There is no GCD\n");
	} else {
		printf("The GCD is %d\n", gcd);
	}

	return 0;
}

int get_gcd(int a, int b) {

	for(int i = 2; i <= a && i <= b; i++) {
		if (a % i == 0 && b % i == 0) {
			return i;
		}
		return 0;

	}

}

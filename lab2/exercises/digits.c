#include <stdio.h>

int main() {
	int num;
	printf("Enter a positive integer: ");
	scanf("%d", &num);

	int reverseNum = 0;
	while (num > 0) {
		reverseNum = (reverseNum * 10) + (num % 10);
		num = num / 10;
	}

	printf("The reverse is %d\n", reverseNum);
	
	return 0;
}

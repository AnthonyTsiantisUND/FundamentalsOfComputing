#include <stdio.h>


int main() {
	int nums[5];

	for (int i = 1; i < 6; i++) {
		printf("Enter integer #%d: ", i);
		scanf("%d", &nums[i-1]);
	}

	printf("\n");

	for (int i = 4; i >= 0; i--) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	
	return 0;
}

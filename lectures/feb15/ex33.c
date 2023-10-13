#include <stdio.h>


int main() {
	int num;
	int arr[20];
	int count = 0;

	printf("Enter positive integers followed by a -1: ");
	
	while(1) {
		scanf("%d", &num);

		if (num == -1) {
			break;
		}

		arr[count] = num;
		count++;

	}

	for (int i = count - 1; i >= 0; i--) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

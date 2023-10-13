#include <stdio.h>
#include <stdbool.h>

int main() {
	int nums[20];

	bool isDone = false;
	int counter = 0;
	int temp;
	
	while (!isDone) {
		printf("Enter integer #%d: ", counter + 1);
		scanf("%d", &temp);
		if (temp == -1) {
			isDone = true;
		} else {
			nums[counter] = temp;
			counter++;
		}
	}


	printf("\n");

	for (int i = counter - 1; i >= 0; i--) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	
	return 0;
}

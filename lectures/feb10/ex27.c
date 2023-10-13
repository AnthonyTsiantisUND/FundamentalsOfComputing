#include <stdio.h>
#include <stdbool.h>

int menu();

int main() {
	int n;
	bool isDone = false;
	
	while (!isDone) {
		int n = menu();
		switch(n) {
			case 1:
				printf("You entered option 1\n");
				break;

			case 2:
				printf("You entered option 2\n");
				break;

			case 3:
				printf("You entered option 3\n");
				break;
			case 4:
				isDone = true;
				printf("You choose to quit.\n");
				break;
			default:
				printf("Incorrect choice\n");
		}

	}
	
	return 0;
}

int menu() {
		int n;
		printf("1: option 1\n");
		printf("2: option 2\n");
		printf("3: option 3\n");
		printf("4: quit\n");
		printf("Enter 1 or 2 or 3: ");
		scanf("%d", &n);
		return n;

}

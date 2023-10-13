#include <stdio.h>


int main() {
	int numbers[3][4] = {2, 4, 5, 8, 9, 7, 5, 3, 7, 5, 1, 8};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", numbers[i][j]);
		}
		printf("\n");
	}

		// Cannot [][]
	int numbers2[][4] = { { 2, 4, 5, 8 }, 
						   { 9, 7, 5, 3 }, 
						   { 7, 5, 1, 8 }
						 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", numbers2[i][j]);
		}
		printf("\n");
	}

	return 0;
}

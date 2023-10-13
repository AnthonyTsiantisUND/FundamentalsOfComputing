#include <stdio.h>

int findsum(int a[], int sz) {
	int sum = 0;
	for (int i = 0; i < sz; i++) {
		sum += a[i];
	}
	return sum;
}

int findsumrec(int a[], int sz) {
	if (sz <= 0) { return 0; }

	return (findsumrec(a, sz - 1) + a[sz - 1]);

}


int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int size = 5;

	printf("For loop: %d\n", findsum(arr, size));
	printf("Recursion: %d\n", findsumrec(arr, size));

	return 0;
}

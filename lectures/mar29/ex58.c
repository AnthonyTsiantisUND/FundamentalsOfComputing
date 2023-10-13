#include <stdio.h>

int main() {
	int arr[] = {23, 55, 72, 19, 65};
	int size = sizeof(arr)/sizeof(arr[0]);

	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}

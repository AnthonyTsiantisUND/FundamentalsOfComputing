#include <stdio.h>



int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("You need to enter a name\n");
		return 1;
	} else if (argc > 2) {
		printf("Too many names\n");
	} else {
		printf("hello %s, how are you?\n", argv[1]);
	}

	return 0;
}

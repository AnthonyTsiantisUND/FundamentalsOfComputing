#include <stdio.h>


int main() {
	// Each char requires one byte
	char ch;
	
	printf("%d\n", sizeof(ch));

	ch = 'w'; // Must be single quotes

	printf("%c\n", ch); // Prints character
	printf("%d\n", ch); // Prints ASCII code


	int n = 77;
	printf("%d\n", n); // Prints integer
	printf("%c\n", n); // Prints character

	ch++;
	printf("%c\n", ch); // Prints character

	int num = 7;
	printf("%c\n", n); // Prints character

	return 0;
}

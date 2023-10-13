#include <stdio.h>


int main() {
	char x;
	x = 'a';

	for (int i = 0; i < 26; i++) {
		printf("%c", x);
		x++;
	}
	printf("\n");

	for (int i = 97; i <= 122; i++) {
		printf("%c", i);
	}

	printf("\n");
	
	// Character can be treated as int
	for (char ch = 'a'; ch <= 'z'; ch++) {
		printf("%c", ch);
	}
	printf("\n");
	

	return 0;
}

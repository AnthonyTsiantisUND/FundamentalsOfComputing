#include <stdio.h>

int main() {
	char str[] = "Notre Dame";
	char *p;
	p = str;


	printf("%s\n", str); // Array of char
	printf("%s\n", p); // Array (pointer) of char
	printf("%c\n", *p); // Singular char

	p = p + 7;
	printf("%c\n", *p);
	printf("%s\n", str);
	printf("%s\n", p);


	return 0;
}


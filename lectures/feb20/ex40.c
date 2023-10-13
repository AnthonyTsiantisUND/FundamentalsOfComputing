#include <stdio.h>
#include <string.h>


int main() {
	char str[20] = "notre dame"; // Only enough for 19 characters
	printf("%d\n", sizeof(str));

	// String length function in string.h (doesn't count terminating value)
	printf("%d\n", strlen(str));

	// Every string has an automatic null terminating character at the end of the string and has size of 1 '\0'
	printf("%d\n", sizeof("notre dame")); // Prints 11

	char x;
	x = 'A';
	
	// Character;
	printf("%d\n", sizeof(x));

	// Integer
	printf("%d\n", sizeof('A'));

	// String
	printf("%d\n", sizeof("A"));
	

	printf("%s\n", str);
	
	// NEVER USE GETS
	gets(str);
	printf("%s\n", str);

	// DO USE FGETS
	fgets(str, 18, stdin); // 18 because enter is read in as part of the stirng
	printf("%s\n", str);

	return 0;
}

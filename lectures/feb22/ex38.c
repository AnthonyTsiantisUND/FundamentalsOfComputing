#include <stdio.h>


int main() {
	char str[] = "notre dame";
	// str = "Notre Dame"; // Cannot change an address

	puts(str); // Adds newline (only for displaying to monitor)
	fputs(str, stdout); // Displays as is (More versitile)

	printf("\n");

	printf("String is: %s\n", str);
	fprintf(stdout, "String is %s\n", str);


	return 0;
}

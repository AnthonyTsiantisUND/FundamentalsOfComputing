#include <stdio.h>


int main() {
	/*
	char str[20];

	printf("Enter a string: ");
	scanf("%s", &str);
	printf("%s\n", str);*/


	char line[30];
	printf("Enter a line: ");
	fgets(line, 29, stdin);
	printf("%s", line);

	return 0;
}

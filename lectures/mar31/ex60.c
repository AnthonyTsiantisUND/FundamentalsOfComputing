#include <stdio.h>
#include <string.h>

void display1(char []);
void display2(char []);
void display3(char []);
void display4(char *);

int main() {
	char str[] = "notre dame";

	display1(str);
	display2(str);
	display3(str);
	display4(str);

	return 0;
}


void display1(char s[]) {
	printf("%s\n", s);

}

void display2(char s[]) {
	for (int i = 0; i < strlen(s); i++) {
		printf("%c", s[i]);
	}
	printf("\n");
}

void display3(char s[]) {
	char *p = s;
	while (*p != '\0') {
		printf("%c", *p);
		p++;
	}
	printf("\n");
}

void display4(char *p) {
	while (*p != '\0') {
		printf("%c", *p);
		p++;
	}
	printf("\n");
}

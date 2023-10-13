#include <stdio.h>
#include <string.h>
#define MAXLENGTH 20
#define STATESMAX 15

int main() {
	char states[STATESMAX][MAXLENGTH];

	int size = sizeof(states) / (MAXLENGTH * sizeof(states[0][0]));

	FILE *fp = fopen("data.txt", "r");

	char astate[MAXLENGTH];
	
	int counter = 0;
	while (1) {
		fgets(astate, MAXLENGTH, fp);
		 
		if (feof(fp)) {
			break;
		}
		astate[strlen(astate)-1] = '\0';
		strcpy(states[counter], astate);

		counter++;
	}


	printf("%c\n", states[1][5]);
	printf("%s\n", states[3]);
	printf("%d\n", size);

	for (int i = 0; i < counter; i++) {
		printf("%s\n", states[i]);
	}

	for (int i = 0; i < counter; i++) {
		for (int j = 0; j < strlen(states[i]); j++) {
			printf("%c ", states[i][j]);
		}
		printf("\n");
	}

	return 0;
}


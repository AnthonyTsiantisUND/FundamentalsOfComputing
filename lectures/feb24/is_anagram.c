#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


#define NLETTERS 26


void count_letters(char word[], int counts[]) {
	for (size_t i = 0; i < strlen(word); i++) {
		counts[tolower(word[i]) - 'a']++;
	}

}

bool is_anagram(char word1[], char word2[]) {
	int counts1[NLETTERS] = {0};
	int counts2[NLETTERS] = {0};

	count_letters(word1, counts1);
	count_letters(word2, counts2);

	for (size_t i = 0; i < NLETTERS; i++) {
		if (counts1[i] != counts2[i]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	char buffer[BUFSIZ];

	while (fgets(buffer, BUFSIZ, stdin)) {
		char word1[BUFSIZ];
		char word2[BUFSIZ];

		sscanf(buffer, "%s %s", word1, word2);
		
		printf("%s\n", is_anagram(word1, word2) ? "ANAGRAM" : "NOT ANAGRAM");
	}

	return 0;
}

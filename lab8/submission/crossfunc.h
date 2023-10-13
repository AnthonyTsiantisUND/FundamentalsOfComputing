/*
	Anthony Tsiantis
	Fundamentals of Computing
	crossfunc.h
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define _GNU_SOURCE
#define WORD_MAX 20
#define LETTER_MAX 15
#define MAX_FILENAME 50
#define MAX_INPUT 100

typedef struct {
	int x;
	int y;
} Coords;

typedef struct {
	char word[LETTER_MAX];
	int length;
	Coords start;
	bool horizontal;
	bool placed;
} Word;

int getData(Word [WORD_MAX]);
int getDataFile(char [], Word [WORD_MAX]);
void clearBoard(char [LETTER_MAX][LETTER_MAX], char);
void printBoard(char [LETTER_MAX][LETTER_MAX]);
void printBoardFile(char [LETTER_MAX][LETTER_MAX], FILE *);
void findSolution(char [LETTER_MAX][LETTER_MAX], Word [WORD_MAX], int, bool);
void printClues(Word [WORD_MAX], int);
void printCluesFile(Word [WORD_MAX], int, FILE *);

/*
	Anthony Tsiantis
	Fundamentals of Computing
	statesfunc.h
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_STATE 100
#define MAX_FILENAME 30
#define MAX_LINE 100
#define DELIM ","
#define MAX_ABBR 5

typedef struct State {
	char state_abbr[5];
	char state_name[20];
	char capital[20];
	int year;
} State;

void getFilename(char[MAX_FILENAME]);
int getData(State[MAX_STATE], char[MAX_FILENAME]);
void listAllData(State[MAX_STATE], int);
void listName(State[MAX_STATE], int size);
void listCapital(State[MAX_STATE], int size);
void joinedYear(State[MAX_STATE], int size);
void joinedBeforeYear(State[MAX_STATE], int size);
void printMenu();


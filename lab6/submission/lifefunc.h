/*
	Anthony Tsiantis
	lifefunc.h
	Fundamentals of Computing
*/
#define BOARDSIZE 40

// Function prototypes
void printBoard(char[BOARDSIZE][BOARDSIZE]);
void clearBoard(char[BOARDSIZE][BOARDSIZE]);
void interactive(char[BOARDSIZE][BOARDSIZE]);
void batch(char[BOARDSIZE][BOARDSIZE], FILE*);

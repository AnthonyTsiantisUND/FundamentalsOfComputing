/*
	Anthony Tsiantis
	Fundamentals of Computing
	flappyBlocFunc.h
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "gfx.h"

#define WIDTH 1200
#define HEIGHT 800

typedef struct {
	int x;
	int y;
} Coord;

void mainMenu();
void playGame();
char gameOver();



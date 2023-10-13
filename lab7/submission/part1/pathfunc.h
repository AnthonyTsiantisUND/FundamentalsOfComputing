/*
	Anthony Tsiantis
	Fundementals of Computing
	pathfunc.h
*/

#include <stdio.h>

typedef struct {
	float x;
	float y;
} Point;

int getData(char fileName[], Point points[]);
float findTotalDistance(Point points[], int size);
void printPoints(Point points[], int size, float totalDistance);


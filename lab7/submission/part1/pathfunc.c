/*
	Anthony Tsiantis
	Fundementals of Computing
	pathfunc.c
*/


#include "pathfunc.h"
#include <stdio.h>
#include <math.h>

// Parse data from file 
int getData(char fileName[], Point points[]) {
	// Create and validate file pointer
	FILE *file = fopen(fileName, "r");
	if (file == NULL) {
		printf("Error Opening File.\n");
		return -1;
	}
	
	// Parse file and populate array with data
	int counter = 0;
	Point temp;
	while(fscanf(file, "%f %f", &temp.x, &temp.y) == 2) {
		points[counter] = temp;
		counter++;
	}

	return counter;
}

// Print data points and distance to screen
void printPoints(Point points[], int size, float totalDistance) {
	printf("\nThere are %d points: \n\n", size);
	printf("    x   |    y  \n");
	printf("--------+-------\n");

	for (int i = 0; i < size; i++) {
		printf("%7.2f |%7.2f\n", points[i].x, points[i].y);
		
	}

	printf("\nThe total distance through these points is %.2f.\n", totalDistance);
}

// Calculate and return distance between two points
float calculateDistance(float x1, float y1, float x2, float y2) {
	float distance;
	float deltaX = x2 - x1;
	float deltaY = y2 - y1;
	distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
	return distance;
}

// Calculate the total distance between all points
float findTotalDistance(Point points[], int size) {
	float totalDistance = 0;

	for (int i = 1; i < size; i++) {
		float x1 = points[i-1].x;
		float y1 = points[i-1].y;
		float x2 = points[i].x;
		float y2 = points[i].y;
		totalDistance += calculateDistance(x1, y1, x2, y2);
	}

	return totalDistance;
}

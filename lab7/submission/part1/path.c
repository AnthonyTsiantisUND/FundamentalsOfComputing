/*
	Anthony Tsiantis
	Fundamentals of Computing
	path.c
*/

#include "pathfunc.h"
#include <string.h>

int main() {
	// Create points
	Point points[30];

	// Get filename from user (assume it is not more than 99 characters)
	char fileName[100];
	printf("Enter the filename: ");
	fgets(fileName, 100, stdin);
	fileName[strlen(fileName) - 1] = '\0';

	// Get size, terminate if file doesn't exist
	int size = getData(fileName, points);
	if (size == -1) {
		return 0;
	}
	
	// Find distance between all points
	float totalDistance = findTotalDistance(points, size);
	
	// Print all points
	printPoints(points, size, totalDistance);

	return 0;
}

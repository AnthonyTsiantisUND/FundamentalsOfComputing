/*
	Anthony Tsiantis
	Fundementals of Computing
	polar.c
*/

// Import libraries
#include <stdio.h>
#include <math.h>

// Declare Functions
int getQuadrant(double, double);
double getRadius(double, double);
double getAngle(double, double);
void showInfo(double, double, int, double, double);

// Main function
int main() {
	// Declare variabes
	double x, y, radius, angle;
	int quadrant;

	// Get user input
	printf("Enter the x and y coordinates: ");
	scanf("%lf %lf", &x, &y);
	
	// Use functions to calculate nessecary data
	quadrant = getQuadrant(x, y);
	radius = getRadius(x, y);
	angle = getAngle(x, y);
	
	// Print to terminal
	showInfo(x, y, quadrant, radius, angle);

	return 0;
}

int getQuadrant(double x, double y) {
	// Determine which quadrant point is in
	if (x > 0 && y > 0) {
		return 1;
	} else if (x > 0 && y < 0) {
		return 4;
	} else if (x < 0 && y > 0) {
		return 2;
	} else {
		return 3;
	}
}

// Calculate and return radius length
double getRadius(double x, double y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}


// Get angle function
double getAngle(double x, double y) {
	return atan(y/x) * (180/M_PI);
}

// Print information function
void showInfo(double x, double y, int quadrant, double radius, double angle) {
	printf("The cartesian point %.2lf, %.2lf (x, y) is in the %d quadrant.\n", x, y, quadrant);
	printf("This cartesian point in polar form (radius, angle (degrees)) is %.2lf, %.2lf\n", radius, angle);

}


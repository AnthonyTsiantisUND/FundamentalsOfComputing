// Author: Anthony Tsiantis

// Import libs
#include <stdio.h>
#include <math.h>

// Main function
int main() {
	// Instantiate Variables
	double rangeMin = 0.0;
	double rangeMax = 30.0;
	double y = 0.0;
	double minX, minY;
	double maxX, maxY;
	
	// Print function and range
	printf("\nPlot for y = 15 * (1 + cos(x)) for x from %.2lf to %.2lf\n", rangeMin, rangeMax);
	
	// Print column headers
	printf("\n     X      Y\n");
	
	// Iterate over range in 0.2 increments
	for (double i = rangeMin; i <= rangeMax; i += 0.2) {
		// Calculate function height
		y = 15*(1+cos(i));
		
		// If first iteration, set max and min to starting values
		if (i == rangeMin) {
			maxX = i;
			maxY = y;
			minX = i;
			maxY = y;
		}
		
		// If new min found update
		if (y < minY) {
			minX = i;
			minY = y;
		}
		
		// If new max found update
		if (y > maxY) {
			maxX = i;
			maxY = y;
		} 
		
		// Print coordinates
		printf("%6.2lf %6.2lf  ", i, y);
		
		// Print function
		for (double j = rangeMin; j <= y; j++) {
			printf("#");
		}
		printf("\n"); // Go to next line
	}
	
	// Print max and min coordinates
	printf("\n\nThe maximum of %.2lf was at %.2lf\n", maxY, maxX);
	printf("The minimum of %.2lf was at %.2lf\n\n", minY, minX);

	return 0;
}

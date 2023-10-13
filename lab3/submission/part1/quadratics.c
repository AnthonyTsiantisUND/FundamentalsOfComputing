/*
	Anthony Tsiantis
	Fundementals of Computing
	Lab 3 - Part 1 - quadratics.c
	Display the roots to a quadratic equation. 
*/

#include <stdio.h>
#include <math.h>

// Call function
double findDisc(double, double, double);

// Main function
int main() {
	// Instantiate Variables
	double a, b, c, disc;
	double x1, x2;
	double solution1, solution2;
	
	// Infinite while loop, break out with sentinel condition
	while (1) {
		// Get user input
  		printf("Enter the coefficients (a,b,c) of a quadratic equation: ");
  		scanf("%lf %lf %lf", &a, &b, &c);
	
		// Check if sentinel value is entered
		if (a == 0) {
			printf("Sentinel value (a = 0) was entered, program terminating...\n\n");
			break;
		}

		// Call Function to get discriminant
  		disc = findDisc(a, b, c);
	
		// Output number of solutions and the solution(s) if they exist.
  		if (disc < 0) {
  			printf("There are no real solutions.\n\n");
  		} else if (disc == 0) {
  			solution1 = -b/(2*a);
  			printf("The one solution: %lf\n\n", solution1);
  		} else {
			solution1 = ((-b + sqrt(disc))/(2.f*a));
			solution2 = ((-b - sqrt(disc))/(2.f*a));
			printf("The two solutions are %f, %f\n\n", solution1, solution2);
  		}

  	}

  	return 0;
}

// Function finds discriminant using a, b, c values and returns value
double findDisc(double a, double b, double c) {
	return (pow(b, 2) - (4*a*c)); 
}

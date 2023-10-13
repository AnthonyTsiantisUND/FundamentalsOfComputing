/* 
	Anthony Tsiantis
	Fundementals of Computing
	grades.c
*/

// Import libraries
#include <stdio.h>
#include <math.h>

// Function Prototypes
int sumGrades(int[], int);
float determineAverage(int, int);
float stdDev (int[], float, int);

// Main function
int main() { 
	// Grades initalization
	
  	int grades[] = { 
		96,73,62,87,80,63,93,79,71,99,
      	82,83,80,97,89,82,93,92,95,89,
      	71,97,91,95,63,81,76,98,64,86,
		74,79,98,82,77,68,87,70,75,97,
      	71,94,68,87,79 
	};

	// Get size of array and print
	int size = sizeof(grades)/sizeof(int);
	printf("\nSize of Array: %d\n", size);
	
	// Get sum of grades
	int sum = sumGrades(grades, size);
	
	// Calculate Average and print
	float average = determineAverage(sum, size);
	printf("\nAverage: %.2f\n", average);
	
	// Calculate standard deviation and print
	float standardDeviation = stdDev(grades, average, size);
	printf("\nStandard Deviation: %.2f\n\n", standardDeviation);

  return 0;
}

// Sum grades function returns the sum of grades
int sumGrades(int grades[], int size) {
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += grades[i];
	}

	return sum;
}

// Returns the average of grades
float determineAverage(int sum, int size) {
	return (float) sum / (float) size;
}

// Calculates and returns the standard deviation of grades
float stdDev(int grades[], float average, int size) {
	float standardDeviation = 0.0;
	
	for (int i = 0; i < size; i++) {
		standardDeviation += pow(grades[i] - average, 2);
	}

	return sqrt(standardDeviation / size);
}


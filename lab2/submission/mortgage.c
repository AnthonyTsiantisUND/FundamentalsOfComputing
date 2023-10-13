// Author: Anthony Tsiantis

// import libs
#include <stdio.h>
#include <math.h>

// Main function
int main() {
	// Initalize variables
	double principle, rate, monthlyPayment;
	double totalPayed = 0;

	// Get user input
	printf("Enter three values ((principle) (annual rate) (monthly payment)): ");
	scanf("%lf %lf %lf", &principle, &rate, &monthlyPayment);

	// Validate user input
	while (1) {
		if (principle < 10000 || rate < 0.001 || monthlyPayment < 25) {
			printf("\nERROR: Invalid input\n");
			printf("Enter three values ((principle) (annual rate) (monthly payment)): ");
			scanf("%lf %lf %lf", &principle, &rate, &monthlyPayment);
		} else {
			break;
		}
	}

	// Calculate how long to pay off mortgage
	int months = 0;
	rate /= 12.0;
	double monthlyInterest = principle * rate;
	
	// Determine if monthly payment is sufficient
	if (monthlyInterest > monthlyPayment) {
		printf("Monthly Payment not sufficient!\n");
	} else {
		// Output headers
		printf("\n\nMonth    Payment    Interest       Balance\n");
		
		// Calculate values
		monthlyInterest = principle * rate;
		principle -= (monthlyPayment - monthlyInterest);
		months += 1;
		totalPayed += monthlyPayment;

		// Calculate and output every month's data
		while (1)  {
			// Print row
			printf("%5d   ", months);
			printf("$%7.2lf   ", monthlyPayment);
			printf("$%8.2lf   ", monthlyInterest);
			printf("$%10.2lf  ", principle);
			printf("\n");
			
			// If not last row
			if (principle + (principle * rate) > monthlyPayment) {
				// Caclulate next row
				monthlyInterest = principle * rate;
				principle -= (monthlyPayment - monthlyInterest);
				months += 1;
				totalPayed += monthlyPayment;
			} else {
				// If last row break out of loop
				break;
			}
		} 
		
		// Calculate last row
		monthlyInterest = principle * rate;
		monthlyPayment = principle + monthlyInterest;
		principle = 0; 
		months += 1;
		totalPayed += monthlyPayment;

		// Print out last row
		printf("%5d   ", months);
		printf("$%7.2lf   ", monthlyPayment);
		printf("$%8.2lf   ", monthlyInterest);
		printf("$%10.2lf  ", principle);

		printf("\n\n"); // Format

		// Calculate number of years and months
		int numYears = months / 12;
		int numMonths = months % 12;;
		
		// If no months just print years else print years and months
		if (numMonths == 0) {
			printf("You payed a total of $%.2lf over %d years.\n\n", totalPayed, numYears, numMonths);
		} else {
			printf("You payed a total of $%.2lf over %d years and %d months.\n\n", totalPayed, numYears, numMonths);
		}
	}

	return 0;
}

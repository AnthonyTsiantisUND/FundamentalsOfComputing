// quad.c
// computes the roots of a quadratic equation
#include <stdio.h>
#include <math.h>

int main()
{
  double a, b, c, disc;
  double x1, x2;

  printf("Enter the coefficients (a,b,c) of a quadratic equation: ");
  scanf("%lf %lf %lf", &a, &b, &c);

  disc = (pow(b, 2) - (4*a*c)); 

  double solution1, solution2;

  if (disc < 0) {
  	printf("There are no real solutions.\n");
  } else if (disc == 0) {
  	solution1 = -b/(2*a);
  	printf("The one solution: %lf\n", solution1);
  } else {
	solution1 = ((-b + sqrt(disc))/(2.f*a));
	solution2 = ((-b - sqrt(disc))/(2.f*a));
	printf("The two solutions are %f, %f\n", solution1, solution2);
  }
  return 0;
}


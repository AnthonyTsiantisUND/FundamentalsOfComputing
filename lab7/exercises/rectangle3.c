// rectangle3.c
#include <stdio.h>

typedef struct {
  float length;
  float width;
  float area;
  float perimeter;
} Rectangle; 

int readvalues(FILE *, Rectangle []);

float find_area(Rectangle);
float find_perim(Rectangle);
void display(Rectangle);

int main()
{
  FILE *fp = fopen("values.txt", "r");
  Rectangle rect_arr[10]; 
  int count = 0;
   
  // read the length and width values, and
  while (!feof(fp)) {
  	Rectangle r;
	float x, y;
	fscanf(fp, "%f %f", &x, &y);
	r.length = x;
	r.width = y;
	r.area = find_area(r);
	r.perimeter = find_perim(r);
	rect_arr[count] = r;
	count++;
  }

  for (int i = 0; i < count; i++) {
  	display(rect_arr[i]);
  }

  return 0; 
}


float find_area(Rectangle r)
{
  return r.length*r.width;
}

float find_perim(Rectangle r)
{
  return 2*(r.length + r.width);
}

void display(Rectangle r)
{
  printf("rectangle is %g x %g\n", r.length, r.width);
  printf("  its area is %g\n", r.area);
  printf("  its perimeter is %g\n", r.perimeter);
}


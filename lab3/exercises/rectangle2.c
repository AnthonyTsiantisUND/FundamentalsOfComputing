// rectangle2.c
#include <stdio.h>

// function prototypes go here ...
int find_perim(int, int);
int find_area(int, int);
void display(int, int);


int main()
{
  float len, wid;
  float perim, area;

  printf("enter the rectangle's length and width: ");
  scanf("%f %f", &len, &wid);

  perim = find_perim(len, wid);  // call the find_perim function
  area = find_area(len, wid);    // call the find_area function

  display(perim, area);          // call the display function

  return 0;
}

// function definitions go here ...
int find_perim(int len, int wid) {
	return 2*(len+wid);
}

int find_area(int len, int wid) {
	return len*wid;
}

void display(int perim, int area) {
	printf("The perimiter is: %d\n", perim);
	printf("The area is: %d\n", area);
}



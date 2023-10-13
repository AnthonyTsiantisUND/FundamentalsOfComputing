#include <stdio.h>

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



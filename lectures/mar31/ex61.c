#include <stdio.h>

typedef enum {
	blue, 
	red,
	white = 15,
	black,
	green,
	purple, 
	orange
} color;


int main() {
	color val;
	val = red;
	printf("%d\n", val);
	val = green;
	printf("%d\n", val);

	return 0;
}

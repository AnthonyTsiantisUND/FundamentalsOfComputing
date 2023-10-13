#include <stdio.h>
#include "gfx.h"


int main() {
	gfx_open(500, 400, "Test Window");

	gfx_color(150, 50, 200);
	gfx_circle(100, 200, 40);
	gfx_color(50, 150, 100);
	gfx_circle(300, 100, 70);
	gfx_flush();
	
	char c;
	while(1) {
		c = gfx_wait();
		if (c == 'q') {
			break;
		}

	}



	return 0;
}

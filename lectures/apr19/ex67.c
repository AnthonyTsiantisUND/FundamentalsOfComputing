#include <stdio.h>
#include "gfx.h"


int main() {
	char c;
	gfx_open(500, 400, "Test Window");
	int xc = 100;

	
	while(1) {
		gfx_clear();
		gfx_circle(xc, 200, 30);
		xc += 10;

		c = gfx_wait();
		if (c == 'q') {
			break;
		}

	}



	return 0;
}

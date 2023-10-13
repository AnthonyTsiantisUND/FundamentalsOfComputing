#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "gfx.h"

#define WIDTH 800
#define HEIGHT 500

typedef struct {
	int x;
	int y;
} Pos;

void drawPerson(Pos, int);
void drawSun(int);

int main() {
	// Open window
	gfx_open(WIDTH, HEIGHT, "Fun Animation!");
	gfx_clear_color(173, 216, 230);

	// Initalize variables
	Pos loc;
	loc.x = 100;
	loc.y = 350;

	float x1 = M_PI/2.; 
	int legPos = round(sin(x1) * 20);;
	int counter = 0;
	char input;

	int sunPos = 0;
	float x2 = 0;

	while(1) {
		// Clear the screen
		gfx_clear();
		
		// Check for keybaord input and update person
		if (gfx_event_waiting()) {
			input = gfx_wait();
			if (input == 'a') {
				if (!(loc.x < 25)) {
					loc.x -= 5;
					legPos = round(sin(x1) * 20);
					x1 += M_PI/10.;
				}
			} else if (input == 'd') {
				if (!(loc.x > WIDTH - 25)) {
					loc.x += 5;
					legPos = round(sin(x1) * 20);
					x1 += M_PI/10.;
				}
			}

		}

		// Moderate the growing and shrinking animation for the sun
		if (counter > 10) {
			sunPos = round(sin(x2) * 20);
			x2 += M_PI/100.;
			counter = 0;
		}


		// Draw
		drawSun(sunPos);
		drawPerson(loc, legPos);


		gfx_flush();
		usleep(10000);
		counter++;
	}


	return 0;
}


void drawSun(int sunPos) {
	gfx_color(255,255,0);
	gfx_circle(WIDTH, 0, 100 + sunPos);
}

void drawPerson(Pos loc, int legPos) {
	int radius = 15;
	gfx_color(0, 0, 0);
	gfx_circle(loc.x, loc.y, radius);
	gfx_line(loc.x, loc.y+radius, loc.x, loc.y  + radius + 50);
	gfx_line(loc.x-20, loc.y+radius + 25, loc.x+20, loc.y  + radius + 25);
	gfx_line(loc.x, loc.y + radius + 50, loc.x - legPos, loc.y  + radius + 100);
	gfx_line(loc.x, loc.y + radius + 50, loc.x + legPos, loc.y  + radius + 100);

}

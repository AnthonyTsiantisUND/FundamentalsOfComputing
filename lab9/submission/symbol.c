#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "gfx.h"

#define WIDTH 800
#define HEIGHT 500
#define SIZE 50

typedef struct {
	int x;
	int y;
} Coord;


void drawPolygon(int, int, Coord);


int main() {
	// Open window
	gfx_open(WIDTH, HEIGHT, "Draw");

	// Initalize variables
	char c;
	Coord location;
	
	// Event loop
	while(true) {
		// Determine if input is pressed
		if (c = gfx_wait()) {
			// Get mouse location
			location.x = gfx_xpos();
			location.y = gfx_ypos();
			
			// If character has been entered
			if (c >= 97 && c <= 122) {
				if (c == 'q') {
					return 0; // Quit
				} else if (c == 'c') {
					// Draw Circle
					gfx_color(255, 255, 255); // White
					gfx_circle(location.x, location.y, SIZE);
				} else if (c == 't') {
					// Draw triangle
					gfx_color(170, 255, 0); // Green
					drawPolygon(SIZE, 3, location);
				} 
			} else if (c == 1) {
				// Print Square
				gfx_color(135,206,250); // Blue
				drawPolygon(SIZE, 4, location);

			} else if (c >= '3' && c <= '9') {
				// Draw polygon
				c = (int) (c - '0');
				gfx_color(93, 63, 211); // Purple
				drawPolygon(SIZE, c, location);

			
			} else if (c == 27) {
				gfx_clear(); // Clear screen if escape is pressed

			}

			gfx_flush(); // Flush the screen
		}


	}
	return 0;
}


void drawPolygon(int size, int numSides, Coord location) {
	// Keep track of last vertex and current vertex
	Coord last;
	Coord vertex;

	// Draw the polygon
	for (int i = 0; i < numSides+1; i++) {
		// Calculate the coordinates of the current vertex
		vertex.x = (size * cos(2 * M_PI * i / numSides)) + location.x;
		vertex.y = (size * sin(2 * M_PI * i / numSides)) + location.y;
		
		// Update last vertex for first iteration
		if (i == 0) {
			last = vertex;
		}

		// Draw to screen
		gfx_line(last.x, last.y, vertex.x, vertex.y);
		
		// Update last vertex
		last = vertex;
	}

}




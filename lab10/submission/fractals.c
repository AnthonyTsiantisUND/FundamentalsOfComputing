/*
	Anthony Tsiantis
	Fudamentals of Computing
	fractals.c
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#include "gfx.h"

#define WIDTH 1000
#define HEIGHT 750
#define BASE 5


typedef struct {
	int x;
	int y;
} Coord;


void drawSierpinski(Coord, Coord, Coord);
void drawTriangle(Coord, Coord, Coord);
void drawShrinkSquares(Coord, int);
void drawSquare(Coord, int);
void drawSquareSpiral(double, double, Coord, int, double);
void drawCircleLace(Coord, int);
void drawSnowflake(Coord, int);
void drawTree(Coord, int, double);
void drawFern(Coord, int, double);
void drawSpiralOfSpirals(Coord, int, double);

int main() {
	// Open Window
	gfx_open(WIDTH, HEIGHT, "Fractals");
	
	// Declare Variables
	char event;
	int margin, length;
	Coord first;
	Coord second;
	Coord third;
	Coord offset;
	double theta;
	
	// Window loop
	while (1) {
		// Wait for event
		event = gfx_wait();

		// Clear the screen
		gfx_clear();
		
		// Switch Statement to handle user input
		switch (event) {
			// Quit
			case 'q':
				return 0;

			// Triangle
			case '1':
				// Set starting points
				margin = 20;
				first.x = margin;
				first.y = margin;;
				second.x = WIDTH - first.x;
				second.y = margin;
				third.x = WIDTH / 2;
				third.y = HEIGHT - margin;
				drawSierpinski(first, second, third);
				break;

			// Shrinking Squares
			case '2':
				// Set starting points
				length = 300;
				first.x = (WIDTH / 2) - (length / 2);
				first.y = (HEIGHT / 2) - (length / 2);
				drawShrinkSquares(first, length);
				break;
			
			// Square Spiral
			case '3':
				length = 1; // Starting length
				offset.x = WIDTH/2;
				offset.y = HEIGHT/2;
				theta = 0.0;
				drawSquareSpiral(0.5, 25, offset,  length, theta);
				break;

			// Circular Lace
			case '4':
				length = 200; // Starting radius
				// Center of main circle
				offset.x = WIDTH/2;
				offset.y = HEIGHT/2;
				drawCircleLace(offset, length);
				break;
			
			// Snowflake
			case '5':
				length = 250;
				offset.x = WIDTH/2;
				offset.y = HEIGHT/2;
				drawSnowflake(offset, length);
				break;
			
			// Draw Tree
			case '6':
				theta = M_PI / 2.0;
				length = 190;
				offset.x = WIDTH/2;
				offset.y = HEIGHT - 50;
				drawTree(offset, length, theta);
				break;
			
			// Draw Fern
			case '7':
				theta = M_PI / 2.0;
				length = 450;
				offset.x = WIDTH/2;
				offset.y = HEIGHT - 50;
				drawFern(offset, length, theta);
				break;

			// Draw Spiral of Spirals
			case '8':
				length = 500; // Starting length
				offset.x = WIDTH/2;
				offset.y = HEIGHT/2;
				theta = 0;
				drawSpiralOfSpirals(offset,  length, theta);
				break;

			// Handle invalid input
			default:
				printf("Invalid Input!\n");
				break;
		}
		// Flush the screen
		gfx_flush();
	}

	return 0;
}

void drawSierpinski(Coord first, Coord second, Coord third) {
	// Base case.
	if(abs(second.x - first.x) < BASE) {
		return;
	}

	Coord firstCpy = first;
	Coord secondCpy = second;
	Coord thirdCpy = third;

	// Draw a triangle
	drawTriangle(first, second, third);

	// Recursive calls
	second.x = (first.x + second.x)/2;
	second.y = (first.y + second.y)/2;
	third.x = (first.x + third.x)/2;
	third.y = (first.y + third.y)/2;
	drawSierpinski(first, second, third);

	// Reset points
	first = firstCpy;
	second = secondCpy;
	third = thirdCpy;
	
	// Recursion
	first.x = (first.x + second.x)/2;
	first.y = (first.y + second.y)/2;
	third.x = (second.x + third.x)/2;
	third.y = (second.y + third.y)/2;
	drawSierpinski(first, second, third);

	// Reset points
	first = firstCpy;
	second = secondCpy;
	third = thirdCpy;
	
	// Recursion
	first.x = (first.x + third.x)/2;
	first.y = (first.y + third.y)/2;
	second.x = (second.x + third.x)/2;
	second.y = (second.y + third.y)/2;
	drawSierpinski(first, second, third);

}

void drawShrinkSquares(Coord first, int length) {
	Coord second;
	Coord third;
	Coord fourth;

	// Base Case
	if (length < BASE) {
		return;
	}

	// Draw first Square
	drawSquare(first, length);

	// Recursive Calls
	length = length / 2;
	first.x = first.x - (length/2);
	first.y = first.y - (length/2);
	second.x = first.x + (2*length);
	second.y = first.y;
	third.x = second.x;
	third.y = first.y + (2*length);
	fourth.x = first.x;
	fourth.y = third.y;
	drawShrinkSquares(first, length);
	drawShrinkSquares(second, length);
	drawShrinkSquares(third, length);
	drawShrinkSquares(fourth, length);
}

void drawSquareSpiral(double a, double b, Coord offset, int length, double theta) {
	Coord first;
	
	// Base case
	if (length > 75) { return; }
	
	// Square points
	first.x = offset.x + (a + b * theta) * cos(theta);
	first.y = offset.y + (a + b * theta) * sin(theta);
	drawSquareSpiral(a, b, offset, length + 2, theta += 0.5);
	drawSquare(first, length);
}

void drawCircleLace(Coord offset, int radius) {
	// Delcare variables
	Coord first;
	Coord second; 
	Coord third;
	Coord fourth;
	Coord fifth;
	Coord sixth;
	double theta = 0.175*M_PI;
	
	// Base case
	if (radius < (BASE-3)) { 
		return; 
	}
	
	// Draw circle
	gfx_circle(offset.x, offset.y, radius);
	
	// Populate points
	first.x = offset.x;
	first.y = offset.y - radius;
	second.x = offset.x + radius*cos(theta);
	second.y = offset.y - radius*sin(theta);
	third.x = offset.x + radius*cos(theta);
	third.y = offset.y + radius*sin(theta);
	fourth.x = offset.x;
	fourth.y = offset.y + radius;
	fifth.x = offset.x - radius*cos(theta);
	fifth.y = offset.y + radius*sin(theta);
	sixth.x = offset.x - radius*cos(theta);
	sixth.y = offset.y - radius*sin(theta);

	
	// Update radius and make recursive calls
	radius = radius / 3;
	drawCircleLace(first, radius);
	drawCircleLace(second, radius);
	drawCircleLace(third, radius);
	drawCircleLace(fourth, radius);
	drawCircleLace(fifth, radius);
	drawCircleLace(sixth, radius);
}

void drawSnowflake(Coord offset, int length) {
	// Base case 
	if (length < 3) {
		return;
	}
	
	// Create points
	double theta = 0.4*M_PI;
	Coord first = { offset.x+length, offset.y };
	Coord second = { offset.x + (length*cos(theta)), offset.y + (length*sin(theta)) };
	Coord third = { offset.x+(length*cos(theta*2)), offset.y+(length*sin(theta*2)) };
	Coord fourth = { offset.x+(length*cos(theta*3)), offset.y+(length*sin(theta*3)) };
	Coord fifth = { offset.x+(length*cos(theta*4)), offset.y+(length*sin(theta*4)) };
	
	// Draw five lines
	gfx_line(offset.x, offset.y, first.x, first.y);
	gfx_line(offset.x, offset.y, second.x, second.y);	
	gfx_line(offset.x, offset.y, third.x, third.y);
	gfx_line(offset.x, offset.y, fourth.x, fourth.y);
	gfx_line(offset.x, offset.y, fifth.x, fifth.y);

	// Make recursive calls
	drawSnowflake(first, length/3);
	drawSnowflake(second, length/3);
	drawSnowflake(third, length/3);
	drawSnowflake(fourth, length/3);
	drawSnowflake(fifth, length/3);
}

void drawTree(Coord offset, int length, double theta) {	
	// Base case
	if (length < BASE) { return; }
	double increment = M_PI/6.0;

	Coord first = { offset.x + length*cos(theta), offset.y - length*sin(theta) };
	
	gfx_line(offset.x, offset.y, first.x, first.y);
	
	// Recursive calls
	drawTree(first, 0.75*length, theta + increment);
	drawTree(first, 0.75*length, theta - increment);

}

void drawFern(Coord offset, int length, double theta) {
	// Base case
	if (length < BASE) { return; }
	double increment = M_PI/6.0;

	Coord first = { offset.x + length*cos(theta), offset.y - length*sin(theta) };
	Coord second = { offset.x  + length*cos(theta)/4, offset.y  - length*sin(theta)/4 };
	Coord third = { offset.x  + length*cos(theta)/2, offset.y  - length*sin(theta)/2 };
	Coord fourth = { offset.x  + 3*length*cos(theta)/4, offset.y  - 3*length*sin(theta)/4 };
	
	gfx_line(offset.x, offset.y, first.x, first.y);
	
	// Recursive calls
	drawFern(first, length/3, theta + increment);
	drawFern(first, length/3, theta - increment);
	drawFern(second, length/3, theta + increment);
	drawFern(second, length/3, theta - increment);
	drawFern(third, length/3, theta + increment);
	drawFern(third, length/3, theta - increment);
	drawFern(fourth, length/3, theta + increment);
	drawFern(fourth, length/3, theta - increment);
}

void drawSpiralOfSpirals(Coord offset, int length, double theta) {
	Coord first;
	double increment = M_PI/6;
	
	// Base case
	if (length < 1) { 
		return; 
	}


	first.x = offset.x + length*cos(theta * increment);
	first.y = offset.y - length*sin(theta * increment);
	gfx_point(first.x, first.y);

	// Recursive calls
	drawSpiralOfSpirals(first, 0.275*length, theta + 1);
	drawSpiralOfSpirals(offset, 0.94*length, theta + 1);
}

void drawTriangle(Coord first, Coord second, Coord third) {
	gfx_line(first.x, first.y, second.x, second.y);
	gfx_line(second.x, second.y, third.x, third.y);
	gfx_line(third.x, third.y, first.x, first.y);
}

void drawSquare(Coord first, int length) {
	gfx_line(first.x, first.y, first.x + length, first.y);
	gfx_line(first.x+length, first.y, first.x + length, first.y + length);
	gfx_line(first.x + length, first.y + length, first.x, first.y + length);
	gfx_line(first.x, first.y + length, first.x, first.y);
}

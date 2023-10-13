#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#include "gfx.h"

#define WIDTH 800
#define HEIGHT 500
#define RADIUS 25


typedef struct {
	int x;
	int y;
	int dx;
	int dy;
} PosVel;

void getRandomVelocity(PosVel *);

int main() {
	// Open the window
	gfx_open(WIDTH, HEIGHT, "Bounce");

	PosVel ball;
	int click;
	srand(time(0));
	
	// Set starting position
	ball.x = 250;
	ball.y = 250;

	// Update velocity
	getRandomVelocity(&ball);
	

	while(1) {
		// Clear screen
		gfx_clear();
		
		// Check for mouse input
		if (gfx_event_waiting()) {
			click = gfx_wait();
			if (click == 1) {
				getRandomVelocity(&ball);
				ball.x = gfx_xpos();
				ball.y = gfx_ypos();
			}
		}

		// Update position
		ball.x += ball.dx;
		ball.y += ball.dy;


		// Validate position
		if (ball.x + RADIUS > WIDTH) {
			ball.dx = -ball.dx;
			ball.x = WIDTH - RADIUS - 1;
		} else if (ball.x - RADIUS < 0) {
			ball.dx = -ball.dx;
			ball.x = RADIUS + 1;
		}

		if (ball.y + RADIUS > HEIGHT) {
			ball.dy = -ball.dy;
			ball.y = HEIGHT - RADIUS - 1;
		} else if (ball.y - RADIUS < 0) {
			ball.dy = -ball.dy;
			ball.y = RADIUS + 1;
		}

		// Draw the ball
		gfx_circle(ball.x, ball.y, RADIUS);

		// Flush output
		gfx_flush();

		// Sleep
		usleep(10000);

	}

	return 0;
}

void getRandomVelocity(PosVel *ball) {
	// Generate a random velocity between -5 and 5
	ball->dx = (rand() % 9) - 4;
	ball->dy = (rand() % 9) - 4;
	
	// Make sure velocity is non zero
	if (ball->dx == 0 && ball->dy == 0) {
		getRandomVelocity(ball);
	}
}

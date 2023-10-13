/*
	Anthony Tsiantis
	Fundamentals of Computing
	flappyBlocFunc.c
*/

#include "flappyBlocFunc.h"

void renderPlayer(Coord playerPos) {
	int length = 25;

	gfx_color(255, 255, 255);
	gfx_circle(playerPos.x, playerPos.y, length); // Body

	gfx_circle(playerPos.x + 15, playerPos.y - 5, length/5); // Eye
	
	// Wing
	gfx_line( playerPos.x - 15, playerPos.y, playerPos.x + 5, playerPos.y );
	gfx_line( playerPos.x - 30, playerPos.y + 10, playerPos.x + 5, playerPos.y );
	gfx_line( playerPos.x -15, playerPos.y, playerPos.x - 30, playerPos.y + 10 );
}

void drawObstacle(Coord obsPos, int len) {
	// Top boundary
	gfx_line(obsPos.x, obsPos.y-len, obsPos.x+len, obsPos.y-len);
	gfx_line(obsPos.x+len, obsPos.y-len, obsPos.x+len, obsPos.y-HEIGHT);
	gfx_line(obsPos.x, obsPos.y-len, obsPos.x, obsPos.y-HEIGHT);

	// Bottom Boundary
	gfx_line(obsPos.x, obsPos.y+len, obsPos.x+len, obsPos.y+len);
	gfx_line(obsPos.x+len, obsPos.y+len, obsPos.x+len, obsPos.y+HEIGHT);
	gfx_line(obsPos.x, obsPos.y+len, obsPos.x, obsPos.y+HEIGHT);
}

int collide(Coord playerPos, Coord obstacles[]) {
	// Check if player is reasonablywithin bounds
	if (playerPos.y > HEIGHT + 100 || playerPos.y < -100) {
		return 1;
	}

	int numObstacles = 3;
	int playerRad = 25;
	int obsRad = 100;
	int disPlayerObs;


	// Check if player has collided with an obstacle
	for (int i = 0; i < numObstacles; i++) {
		disPlayerObs = playerPos.x - obstacles[i].x;
		
		if (disPlayerObs >= -playerRad && disPlayerObs <= obsRad+playerRad) {
			if (abs(obstacles[i].y - playerPos.y) > (obsRad-playerRad)) {
				return 1;
			}
		}
	}
	
	return 0;
}

int renderObstacles(Coord obstacles[]) {
	int obsLen = 100;
	int numObs = 3;
	int obsSpeed = 1;
	int updateScore = 0;

	// Check if any obstacles need to be updated
	for (int i = 0; i < numObs; i++) {

		// If obstacle is out of sight update position
		if (obstacles[i].x < -obsLen) {
			obstacles[i].y = (rand() % (HEIGHT - 200)) + 100;
			obstacles[i].x = WIDTH;
			updateScore = 1;
		}

		// Update obstacle positon
		obstacles[i].x -= obsSpeed; 

		// Draw to screen
		drawObstacle(obstacles[i], obsLen);
	}
	if (updateScore) {
		return 1;
	} else {
		return 0;
	}
}

char gameOver() {
	gfx_clear();
	
	// Draw titles
	gfx_color(255, 0, 0);
	gfx_text(WIDTH/2 - 50, HEIGHT/2, "GAME OVER");
	gfx_text(WIDTH/2 - 75, HEIGHT/2 + 50, "Press q to quit");
	gfx_text(WIDTH/2 - 150, HEIGHT/2 + 100, "Press any other key to return to main menu");
	
	gfx_flush();
	char in = gfx_wait();
	return in;
}


void mainMenu() {
	gfx_clear();
	// Draw title
	gfx_color(255, 255, 255);
	gfx_text(WIDTH/2 - 100, HEIGHT/2, "Press any key to start the game...");
	gfx_flush();
	gfx_wait();
}

void playGame() {
	int score = 0;
	Coord playerPos = { 100, HEIGHT/2 };
	srand(time(NULL));

	// Set initial position
	Coord obstacles[3] = {
		{ WIDTH + WIDTH/3, (rand() % (HEIGHT - 200) + 100) },
		{ WIDTH + 2*WIDTH/3, (rand() % (HEIGHT - 200) + 100) },
		{ 2*WIDTH, (rand() % (HEIGHT - 200) + 100) },
	};


	// Positive is downwards
	double playerDy = 0.0; // Player velocity
	double playerDDy = 0.03; // Player Acceleration

	char buf[35];
	
	while(!collide(playerPos, obstacles)) {
		gfx_clear();
		
		// Detect space bar press
		if (gfx_event_waiting()) {
			if (gfx_wait() == ' ') {
				playerDy = -2;
			}
		}



		// Determine if new block needs to be made
		score += renderObstacles(obstacles);

		// update player position and velocity
		playerDy += playerDDy;
		playerPos.y += playerDy;

		// Render Score
		snprintf(buf, 35, "Current Score: %d", score);
		gfx_text(50, 50, buf);

		// Render player
		renderPlayer(playerPos);
		
		gfx_flush();
		
		// Rest
		usleep(3000);
	}

	
}


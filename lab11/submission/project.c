/*
	Anthony Tsiantis
	Fundamentals of Computing
	project.c
*/

#include "flappyBlocFunc.h"

int main() {
	// Open window
	gfx_open(WIDTH, HEIGHT, "Flappy Bloc");

	char in;
	
	// Window loopp
	while(1) {
		mainMenu();
		playGame();
		
		in = gameOver();
		if (in == 'q') {
			return 0;
		}
	}



	return 0;
}

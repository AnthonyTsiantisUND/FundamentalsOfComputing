// ball_s.c
//  using a struct to represent a circle
#include "gfx.h"
#include <unistd.h>

typedef struct {
  float xc, yc;
  int radius;
  float dx, dy;
} Circle;

int main()
{
  int wid = 800, ht = 600;
  gfx_open(wid, ht, "test window");

  Circle ball = {100, 200, 20,  5.5, 1.2};

  while(1) {
    gfx_clear();
    gfx_circle(ball.xc, ball.yc, ball.radius);

    gfx_flush();
    usleep(10000);

    ball.xc += ball.dx; 
    ball.yc += ball.dy; 

    // right wall collision detection
    if ((ball.xc + ball.radius) >= wid) {
      ball.dx = -ball.dx;
      ball.xc = wid - ball.radius; 
    }

    if(gfx_event_waiting()) {
      if (gfx_wait() == 'q') break;
    }
  }

  return 0;
}


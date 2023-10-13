// ball.c
#include "gfx.h"
#include <unistd.h>

int main()
{
  int wid = 800, ht = 600;
  gfx_open(wid, ht, "test window");

  float xc = 100, yc = 200;
  int radius = 20;
  float dx = 5.5, dy = 1.2; 

  while(1) {
    gfx_clear();
    gfx_circle(xc, yc, radius);

    gfx_flush();
    usleep(10000);

    xc += dx; 
    yc += dy; 

    // right wall collision detection
    if ((xc + radius) >= wid) {
      dx = -dx;
      xc = wid - radius; 
    }

    if(gfx_event_waiting()) {
      if (gfx_wait() == 'q') break;
    }
  }

  return 0;
}


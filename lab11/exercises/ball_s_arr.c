// ball_s_arr.c
//  an array of the Circle struct
#include "gfx.h"
#include <unistd.h>

#define SIZE 3

typedef struct {
  float xc, yc;
  int radius;
  float dx, dy;
} Circle;

int main()
{
  int wid = 800, ht = 700;
  gfx_open(wid, ht, "test window");

  Circle ballarr[SIZE] = { {100, 200, 20,  5.5, 1.2},
                           {300, 200, 30,  3.5, 1.1},
                           {200, 400, 15,  4.5, 1.7} };

  while(1) {
    gfx_clear();
    for (int i = 0; i < SIZE; i++) {
      gfx_circle(ballarr[i].xc, ballarr[i].yc, ballarr[i].radius);

      gfx_flush();
      usleep(10000);

      ballarr[i].xc += ballarr[i].dx; 
      ballarr[i].yc += ballarr[i].dy; 

      // right wall collision detection
      if ((ballarr[i].xc + ballarr[i].radius) >= wid) {
        ballarr[i].dx = -ballarr[i].dx;
        ballarr[i].xc = wid - ballarr[i].radius; 
      }
    }

    if(gfx_event_waiting()) {
      if (gfx_wait() == 'q') break;
    }
  }

  return 0;
}


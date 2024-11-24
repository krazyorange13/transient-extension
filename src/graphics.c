#include "graphics.h"

// uses a scuffed implementation of bresenham's algorithm
void window_draw_line
(window *win, window_coord_t x1, window_coord_t y1, window_coord_t x2, window_coord_t y2, color_t c)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1; 
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    for(;;)
    {
        if (x1 >= 0 && y1 >= 0) window_set_pixel(win, x1, y1, c);
        if (x1==x2 && y1==y2) break;
        e2 = err;
        if (e2 >-dx) { err -= dy; x1 += sx; }
        if (e2 < dy) { err += dx; y1 += sy; }
    }
}

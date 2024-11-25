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

void window_draw_rect
(window *win, window_coord_t x1, window_coord_t y1, window_coord_t x2, window_coord_t y2, color_t c)
{
    window_draw_line(win, x1, y1, x2, y1, c);
    window_draw_line(win, x2, y1, x2, y2, c);
    window_draw_line(win, x2, y2, x1, y2, c);
    window_draw_line(win, x1, y2, x1, y1, c);
}

void window_fill_rect
(window *win, window_coord_t x1, window_coord_t y1, window_coord_t x2, window_coord_t y2, color_t c)
{
    int t;
    if (x2 < x1)
    {
        t = x1;
        x1 = x2;
        x2 = t;
    }
    if (y2 < y1)
    {
        t = y1;
        y1 = y2;
        y2 = t;
    }
    window_fill_rect_strict(win, x1, y1, x2, y2, c);
}

// requires x2 >= x1 and y2 >= y1
void window_fill_rect_strict
(window *win, window_coord_t x1, window_coord_t y1, window_coord_t x2, window_coord_t y2, color_t c)
{
    for (int x = x1; x <= x2; x++)
    {
        for (int y = (int)(y1 / 2); y <= (int)(y2 / 2); y++)
        {
            window_index_t i = window_index(win, y, x);
            frag_char fc = {
                {y * 2 >= y1 ? c : win->frag_chars[i].upper.color},
                {(y * 2) + 1 <= y2 ? c : win->frag_chars[i].lower.color}
            };
            win->frag_chars[i] = fc;
        }
    }
}
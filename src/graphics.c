#include <string.h>

#include "graphics.h"

void window_draw_text
(window *win, char *text, window_coord_t x, window_coord_t y, color_t c)
{
    size_t len = strlen(text);
    for (size_t i = 0; i < len; i++)
    {
        window_coord_t _x = x + i * (FONT_WIDTH + 1);
        window_coord_t _y = y;
        window_draw_char(win, text[i], _x, _y, c);
    }
}

void window_draw_char
(window *win, char ch, window_coord_t x, window_coord_t y, color_t c)
{
    uint8_t glyph_i = FONT_CTOG_I(ch);
    if (glyph_i > FONT_GLYPH_COUNT - 1) return;
    glyph_t glyph = FONT_GLYPHS[glyph_i];
    for (uint8_t i = 0; i < FONT_WIDTH * FONT_HEIGHT; i++)
    {
        glyph_t glyph_bit = (glyph >> ((FONT_WIDTH * FONT_HEIGHT - 1) - i)) & 1;
        if (glyph_bit)
        {
            window_coord_t _x = x + (i % FONT_WIDTH);
            window_coord_t _y = y + (i / FONT_HEIGHT);
            window_set_pixel(win, _x, _y, c);
        }
    }
}

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
        window_set_pixel(win, x1, y1, c);
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

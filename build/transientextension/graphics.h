#ifndef TRANSIENT_EXTENSION_GRAPHICS_H
#define TRANSIENT_EXTENSION_GRAPHICS_H

#include "transientfoundation/transientfoundation.h"

void window_draw_line
(window *win, window_coord_t x1, window_coord_t y1, window_coord_t x2, window_coord_t y2, color_t c);
void window_draw_rect
(window *win, window_coord_t x1, window_coord_t y1, window_coord_t x2, window_coord_t y2, color_t c);
void window_fill_rect
(window *win, window_coord_t x1, window_coord_t y1, window_coord_t x2, window_coord_t y2, color_t c);
void window_fill_rect_strict
(window *win, window_coord_t x1, window_coord_t y1, window_coord_t x2, window_coord_t y2, color_t c);

#endif

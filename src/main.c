#include <stdio.h>

#include "transientfoundation/transientfoundation.h"
#include "graphics.h"

int main()
{
    vec2 w = get_console_size();
    window *win;
    create_window(&win, w.y, w.x);
    hide_cursor();
    raw_mode_enable();
    window_fill_color(win, COLOR_BLACK);
    window_draw_line(win, 0, 0, 10, 10, COLOR_GREEN);
    window_fill_rect(win, 7, 6, 3, 3, COLOR_RED);
    render_window_full(win);
    for (;;) {if (was_kbhit()) break;}
    destroy_window(win);
    raw_mode_disable();
    show_cursor();
    reset_cursor();
    erase_screen();
}

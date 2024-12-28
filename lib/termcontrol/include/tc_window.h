#ifndef _TC_WINDOW_H
#define _TC_WINDOW_H

struct Window;

void tc_window_write(struct Window* window, char** content);

struct Point2D tc_window_get_start(struct Window* window);
struct Point2D tc_window_get_end(struct Window* window);
struct Point2D tc_window_get_dim(struct Window* window);

#endif

#ifndef _TC_DISPLAY_H
#define _TC_DISPLAY_H

#include <stddef.h>

#define SIGWINCH 28

struct DisplayInfo;

extern struct DisplayInfo display_info;

void _tc_display_init();
size_t tc_get_display_height();
size_t tc_get_display_width();

#endif

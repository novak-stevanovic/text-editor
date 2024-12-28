#ifndef _TC_STYLE_PRIMS_H
#define _TC_STYLE_PRIMS_H

#define _GRAPHICS_SET_GRAPHICS_MODE_CODE "\e[%dm"
#define _GRAPHICS_RESET_MODE_CODE "\e[0m"

#define _STYLE_BOLD_MODE_CODE "\e[1m"
#define _STYLE_DIM_MODE_CODE "\e[2m"
#define _STYLE_ITALIC_MODE_CODE "\e[3m"
#define _STYLE_UNDERLINE_MODE_CODE "\e[4m"
#define _STYLE_BLINK_MODE_CODE "\e[5m"
#define _STYLE_INVERSE_MODE_CODE "\e[7m"
#define _STYLE_HIDDEN_MODE_CODE "\e[8m"
#define _STYLE_STRIKETHROUGH_MODE_CODE "\e[9m"
#define _STYLE_RESET_CODE "\e[0m"

// Foreground_CODE Colors (Text)
#define _COLOR_BLACK_FG_CODE "\e[30m"
#define _COLOR_RED_FG_CODE "\e[31m"
#define _COLOR_GREEN_FG_CODE "\e[32m"
#define _COLOR_YELLOW_FG_CODE "\e[33m"
#define _COLOR_BLUE_FG_CODE "\e[34m"
#define _COLOR_MAGENTA_FG_CODE "\e[35m"
#define _COLOR_CYAN_FG_CODE "\e[36m"
#define _COLOR_WHITE_FG_CODE "\e[37m"
#define _COLOR_DEFAULT_FG_CODE "\e[39m"

// Background_CODE Colors
#define _COLOR_BLACK_BG_CODE "\e[40m"
#define _COLOR_RED_BG_CODE "\e[41m"
#define _COLOR_GREEN_BG_CODE "\e[42m"
#define _COLOR_YELLOW_BG_CODE "\e[43m"
#define _COLOR_BLUE_BG_CODE "\e[44m"
#define _COLOR_MAGENTA_BG_CODE "\e[45m"
#define _COLOR_CYAN_BG_CODE "\e[46m"
#define _COLOR_WHITE_BG_CODE "\e[47m"
#define _COLOR_DEFAULT_BG_CODE "\e[49m"

#endif

#ifndef _TC_GRAPHICS_H
#define _TC_GRAPHICS_H

// Colors / Graphics Mode
#define GRAPHICS_SET_GRAPHICS_MODE(x) "\e[" #x "m"
#define GRAPHICS_RESET_MODE "\e[0m"

#define STYLE_BOLD_MODE "\e[1m"
#define STYLE_DIM_MODE "\e[2m"
#define STYLE_ITALIC_MODE "\e[3m"
#define STYLE_UNDERLINE_MODE "\e[4m"
#define STYLE_BLINK_MODE "\e[5m"
#define STYLE_INVERSE_MODE "\e[7m"
#define STYLE_HIDDEN_MODE "\e[8m"
#define STYLE_STRIKETHROUGH_MODE "\e[9m"
#define STYLE_RESET          "\033[0m"

// Foreground Colors (Text)
#define COLOR_BLACK_FG       "\033[30m"
#define COLOR_RED_FG         "\033[31m"
#define COLOR_GREEN_FG       "\033[32m"
#define COLOR_YELLOW_FG      "\033[33m"
#define COLOR_BLUE_FG        "\033[34m"
#define COLOR_MAGENTA_FG     "\033[35m"
#define COLOR_CYAN_FG        "\033[36m"
#define COLOR_WHITE_FG       "\033[37m"
#define COLOR_DEFAULT_FG     "\033[39m"

// Background Colors
#define COLOR_BLACK_BG       "\033[40m"
#define COLOR_RED_BG         "\033[41m"
#define COLOR_GREEN_BG       "\033[42m"
#define COLOR_YELLOW_BG      "\033[43m"
#define COLOR_BLUE_BG        "\033[44m"
#define COLOR_MAGENTA_BG     "\033[45m"
#define COLOR_CYAN_BG        "\033[46m"
#define COLOR_WHITE_BG       "\033[47m"
#define COLOR_DEFAULT_BG     "\033[49m"

#endif

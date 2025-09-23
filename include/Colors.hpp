#ifndef COLORS_hpp
#define COLORS_hpp

const char RESET[] = "\x1B[0m";
const char WHITE[] = "\x1B[37m";
const char RED[] = "\x1B[31m";
const char GREEN[] = "\x1B[32m";
const char BLUE[] = "\x1B[34m";
const char YELLOW[] = "\x1B[33m";
const char CYAN[] = "\x1B[36m";
const char PURPLE[] = "\x1B[35m";

enum class Color {
    DEFAULT,
    RED_COLOR,
    GREEN_COLOR,
    BLUE_COLOR,
    YELLOW_COLOR,
    CYAN_COLOR,
    PURPLE_COLOR
};

#endif

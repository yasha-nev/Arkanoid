#ifndef COLORS_hpp
#define COLORS_hpp

#define COLOR_SIZE 6
#define RESET_SIZE 5

/**
 * @brief ANSI terminal colors for text output formatting.
 *
 * These constants allow applying foreground colors to console outputs using ANSI escape sequences.
 */
const char RESET[] = "\x1B[0m"; ///< Reset all styles to default.
const char WHITE[] = "\x1B[37m"; ///< White foreground color.
const char RED[] = "\x1B[31m"; ///< Red foreground color.
const char GREEN[] = "\x1B[32m"; ///< Green foreground color.
const char BLUE[] = "\x1B[34m"; ///< Blue foreground color.
const char YELLOW[] = "\x1B[33m"; ///< Yellow foreground color.
const char CYAN[] = "\x1B[36m"; ///< Cyan foreground color.
const char PURPLE[] = "\x1B[35m"; ///< Purple foreground color.

/**
 * @brief Enumeration type for supported text colors.
 *
 * Used to specify which color scheme applies to certain textual elements.
 */
enum class Color {
    DEFAULT, ///< No explicit color applied. Text Rendered in white
    RED_COLOR, ///< Text rendered in red.
    GREEN_COLOR, ///< Text rendered in green.
    BLUE_COLOR, ///< Text rendered in blue.
    YELLOW_COLOR, ///< Text rendered in yellow.
    CYAN_COLOR, ///< Text rendered in cyan.
    PURPLE_COLOR ///< Text rendered in purple.
};

#endif // COLORS_hpp

#ifndef UTILS_HPP
#define UTILS_HPP

// Define ANSI escape codes for text colors
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

// Define macro to control debug mode
#ifndef DEBUG_MODE
#define DEBUG_MODE 0 // Set to 1 to enable debug mode by default
#endif

#define FLOAT_ARRAY              "0123456789.f-"
#define INT_ARRAY                "0123456789"
#define DOUBLE_ARRAY             "0123456789.-"
#define OUT_OF_BOUNDS            "Out of bounds"
#define MIN_YEAR                 1900
#define INVALID_ARGUMENTS        "Error: invalid arguments"


///Exceptions
#define INVALID_OPERATOR_COUNT  "Error: Not enough operators were found in the argument!"
#define DIVISION_BY_ZERO        "Error: int he argument you tried to divide by 0!"

#if DEBUG_MODE == 1
// Default Messages optimized
#define DEFAULT_CONSTRUCTOR     "[Default Constructor called]       "
#define PARAMTER_CONSTRUCTOR    "[Parameter Constructor called]     "
#define COPY_CONSTRUCTOR        "[Copy Constructor called]          "
#define DESTRUCTOR              "[Destructor called]                "
#define ASSIGMENT_OPERATOR      "[Assigment Operator called]        "
#define CANT_OPEN_FILE          "[Error: could not open file]       "
#else
// Define default messages when debug mode is disabled
#define DEFAULT_CONSTRUCTOR     ""
#define PARAMTER_CONSTRUCTOR    ""
#define COPY_CONSTRUCTOR        ""
#define DESTRUCTOR              ""
#define ASSIGMENT_OPERATOR      ""
#define CANT_OPEN_FILE          "[Error: could not open file]       "
#endif

#endif // COLORS_HPP
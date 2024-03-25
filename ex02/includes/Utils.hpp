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

///Exceptions
#define ILLEGAL_ADD             "[Span elements already full]       "
#define SUCESS_ADD              "[Sucessfully added new element]    "
#define SPAN_TOO_SMALL          "[The span is to small for that op] "
#define SUCESS_SPAN             "[The span was successfully calc]   "
#define SPAN_SIZE_ERROR         "[Span size is invalid]             "

#if DEBUG_MODE == 1
// Default Messages optimized
#define DEFAULT_CONSTRUCTOR     "[Default Constructor called]       "
#define PARAMTER_CONSTRUCTOR    "[Parameter Constructor called]     "
#define COPY_CONSTRUCTOR        "[Copy Constructor called]          "
#define DESTRUCTOR              "[Destructor called]                "
#define ASSIGMENT_OPERATOR      "[Assigment Operator called]        "
#else
// Define default messages when debug mode is disabled
#define DEFAULT_CONSTRUCTOR     ""
#define PARAMTER_CONSTRUCTOR    ""
#define COPY_CONSTRUCTOR        ""
#define DESTRUCTOR              ""
#define ASSIGMENT_OPERATOR      ""
#endif

#endif // COLORS_HPP
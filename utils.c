#include <stdlib.h>

const char* VERSION_SH = "v1.0.0-beta";

const char* RESET = "\033[0m";

const char* RED = "\033[31m";
const char* GREEN = "\033[32m";
const char* YELLOW = "\033[33m";
const char* BLUE = "\033[34m";
const char* MAGENTA = "\033[35m";
const char* CYAN = "\033[36m";
const char* WHITE = "\033[37m";
const char* GRAY = "\033[90m";

const char* ALERT = "\033[90m[\033[31m!\033[90m]\033[0m";
const char* WARNING = "\033[90m[\033[33m!\033[90m]\033[0m";
const char* INFO = "\033[90m[\033[34m!\033[90m]\033[0m";
const char* OK = "\033[90m[\033[32m!\033[90m]\033[0m";

void clear_console() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

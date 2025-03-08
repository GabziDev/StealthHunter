#ifndef UTILS_H
#define UTILS_H

#define MAX_INPUT_SIZE 1024

// Couleurs
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define GRAY "\033[90m"

// Prefix
#define ALERT "\033[90m[\033[31m!\033[90m]\033[0m"
#define WARNING "\033[90m[\033[33m!\033[90m]\033[0m"
#define INFO "\033[90m[\033[34m!\033[90m]\033[0m"
#define OK "\033[90m[\033[32m!\033[90m]\033[0m"

void clear_console();
void print_logo();

#endif //UTILS_H

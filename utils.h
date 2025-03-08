#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

#define MAX_INPUT_SIZE 1024

void clear_console();
void sleep_ms(int milliseconds);
bool is_valid_url(const char *url);
bool is_valid_file(const char *filePath);

#endif //UTILS_H

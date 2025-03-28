#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include "include/utils.h"

// Clear la console selon le systeme d'exploitation
void clear_console() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Fonction pour mettre en pause avec des ms
void sleep_ms(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

// valider une url http
bool is_valid_url(const char *url) {
    return strncmp(url, "http://", 7) == 0 || strncmp(url, "https://", 8) == 0;
}

// valider un fichier si il existe sur le system
bool is_valid_file(const char *filePath) {
    return access(filePath, F_OK) != -1;
}
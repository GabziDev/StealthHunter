#include "check_xss.h"

#include <stdbool.h>

#include "utils.h"
#include <stdio.h>
#include <string.h>

void xss_get_post() {
}

void xss_header() {
}

void xss_cookies() {
}
void xss_local_storage() {
}

void xss_form() {
}

void check_xss_menu() {
    bool menuIsActive = true;
    char inputUser[100];

    while (menuIsActive) {
        clear_console();

        print_logo();
        printf("=> %s Check Cross-site scripting%s\n", YELLOW, RESET);
        printf("1: GET et POST\n");
        printf("2: Header\n");
        printf("3: Cookies\n");
        printf("4: Local Storage\n");
        printf("5: Form\n");
        printf("%sq%s: Return Home\n", RED, RESET);
        printf("-> ");

        if (fgets(inputUser, sizeof(inputUser), stdin) != NULL) {
            inputUser[strcspn(inputUser, "\n")] = 0;

            clear_console();

            if (strcmp(inputUser, "q") == 0) {
                menuIsActive = false;
            } else if (strcmp(inputUser, "1") == 0) {
                xss_get_post();
            } else if (strcmp(inputUser, "2") == 0) {
                xss_header();
            } else if (strcmp(inputUser, "3") == 0) {
                xss_cookies();
            } else if (strcmp(inputUser, "4") == 0) {
                xss_local_storage();
            } else if (strcmp(inputUser, "6") == 0) {
                xss_form();
            } else {
                clear_console();
            }
        } else {
            clear_console();
        }
    }
}

void check_xss() {
    check_xss_menu();
}

/*
TEST

printf("%s You selected option 1 (Check XSS)\n", INFO);

FILE* file = fopen("payloads/xss.plsh", "r");

if (file == NULL) {
printf("%s Impossible d'ouvrir le fichier.", ALERT);
return;
}

char line[BUFFER_SIZE];

while (fgets(line, sizeof(line), file) != NULL) {
printf("%s", line);
}

fclose(file);
*/
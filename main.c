#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "check_nosql_injection.h"
#include "check_sql_injection.h"
#include "check_xss.h"
#include "dirbusting.h"
#include "utils.h"

void menu() {
    char *curl_version();
    bool menuIsActive = true;
    char inputUser[100];

    while (menuIsActive) {
        clear_console();

        print_logo();
        printf("%s Welcome to the StealthHunter Menu ! [D/Gabzdev] (S-H/%s)\n%s [%s]\n", INFO, VERSION_SH, OK, curl_version());
        printf("1: XSS %s(Not Available)%s\n", RED, RESET);
        printf("2: Injection NoSQL %s(Not Available)%s\n", RED, RESET);
        printf("3: Injection SQL %s(Not Available)%s\n", RED, RESET);
        printf("4: Dir Busting\n");
        printf("%sq%s: quit\n", RED, RESET);
        printf("-> ");

        if (fgets(inputUser, sizeof(inputUser), stdin) != NULL) {
            inputUser[strcspn(inputUser, "\n")] = 0;

            clear_console();

            if (strcmp(inputUser, "q") == 0) {
                menuIsActive = false;
            } else if (strcmp(inputUser, "1") == 0) {
                check_xss();
            } else if (strcmp(inputUser, "2") == 0) {
                check_nosql_injection();
            } else if (strcmp(inputUser, "3") == 0) {
                check_sql_injection();
            } else if (strcmp(inputUser, "4") == 0) {
                dirbusting_main();
            } else {
                clear_console();
            }
        } else {
            clear_console();
        }
    }
}

int main(void) {
    menu();

    return 0;
}
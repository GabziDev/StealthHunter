#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "check_nosql_injection.h"
#include "check_sql_injection.h"
#include "check_xss.h"
#include "utils.h"

void logo() {
    printf("%s         ______   ____   ____  ____   ____  _____   ______   _________________      ______        _____   \n", GREEN);
    printf("     ___|\\     \\ |    | |    ||    | |    ||\\    \\ |\\     \\ /                 \\ ___|\\     \\   ___|\\    \\  \n");
    printf("    |    |\\     \\|    | |    ||    | |    | \\ \\    \\| \\     \\\\______     ______/|     \\     \\ |    |\\    \\ \n");
    printf("    |    |/____/||    |_|    ||    | |    |  \\|    \\  \\     |  %s\\(%s /    /  %s)/%s   |     ,_____/||    | |    | \n", YELLOW, GREEN, YELLOW, GREEN);
    printf(" ___|    \\|   | ||    .-.    ||    | |    |   |     \\  |    |   %s'%s |   |   %s'%s    |     \\--'\\_|/|    |/____/ \n", YELLOW, GREEN, YELLOW, GREEN);
    printf("|    \\    \\___|/ |    | |    ||    | |    |   |      \\ |    |     |   |        |     /___/|  |    |\\    \\ \n");
    printf("|    |\\     \\    |    | |    ||    | |    |   |    |\\ \\|    |    /   //        |     \\____|\\ |    | |    | \n");
    printf("|\\ ___\\|_____|   |____| |____||\\___\\_|____|   |____||\\_____/|   /___//         |____ '     /||____| |____| \n");
    printf("| |    |     |   |    | |    || |    |    |   |    |/ \\|   ||  |`   |          |    /_____/ ||    | |    | \n");
    printf(" \\|____|_____|   |____| |____| \\|____|____|   |____|   |___|/  |____|          |____|     | /|____| |____| \n");
    printf("%s    \\(    )/       \\(     )/      \\(   )/       \\(       )/      \\(              \\( %s|_____|/%s   \\(     )/  \n", YELLOW, GREEN, YELLOW);
    printf("     '    '         '     '        '   '         '       '        '               '    )/       '     '   \n");
    printf("                                                                                       '                   \n%s", RESET);
}

void menu() {
    char *curl_version();
    bool menuIsActive = true;
    char inputUser[100];

    while (menuIsActive) {
        clear_console();

        logo();
        printf("%s Welcome to the StealthHunter Menu ! [D/Gabzdev] (S-H/%s)\n%s [%s]\n", INFO, VERSION_SH, OK, curl_version());
        printf("1: XSS\n");
        printf("2: Injection NoSQL\n");
        printf("3: Injection SQL\n");
        printf("q: Quit\n");
        printf("-> ");

        if (fgets(inputUser, sizeof(inputUser), stdin) != NULL) {
            inputUser[strcspn(inputUser, "\n")] = 0;

            clear_console();

            if (strcmp(inputUser, "q") == 0) {
                menuIsActive = false;
            } else if (strcmp(inputUser, "1") == 0) {
                check_xss();
                getchar();
            } else if (strcmp(inputUser, "2") == 0) {
                check_nosql_injection();
                getchar();
            } else if (strcmp(inputUser, "3") == 0) {
                check_sql_injection();
                getchar();
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
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "check_nosql_injection.h"
#include "check_sql_injection.h"
#include "check_xss.h"
#include "dirbusting.h"
#include "colors.h"
#include "utils.h"
#include "version.h"

void menu() {
    char *curl_version();
    bool menuIsActive = true;
    char inputUser[MAX_INPUT_SIZE];

    while (menuIsActive) {
        clear_console();

        print_logo();
        printf("%s Welcome to the StealthHunter Menu ! [D/Gabzdev] (S-H/%s)\n%s [%s]\n", INFO, VERSION_SH, OK, curl_version());
        printf("1: XSS %s(Not Available)%s\n", RED, RESET);
        printf("2: Injection NoSQL %s(Not Available)%s\n", RED, RESET);
        printf("3: Injection SQL %s(Not Available)%s\n", RED, RESET);
        printf("4: Dir Busting %s(Available)%s\n", GREEN, RESET);
        printf("%sq%s: quit\n", RED, RESET);
        printf("-> ");

        if (fgets(inputUser, MAX_INPUT_SIZE, stdin) != NULL) {
            inputUser[strcspn(inputUser, "\n")] = 0;

            if (strcmp(inputUser, "q") == 0) {
                menuIsActive = false;
            } else if (strcmp(inputUser, "1") == 0) {
                clear_console();
                check_xss();
            } else if (strcmp(inputUser, "2") == 0) {
                clear_console();
                check_nosql_injection();
            } else if (strcmp(inputUser, "3") == 0) {
                clear_console();
                check_sql_injection();
            } else if (strcmp(inputUser, "4") == 0) {
                clear_console();
                dirbusting_prompts();
            } else {
                clear_console();
            }
        } else {
            clear_console();
        }
    }
}

void helpMessages() {
    const char *helpMessage[] = {
        " --help or -h                                              Print this help message",
        " --version or -v                                           Print version information",
        " --dirbusting --url <url> --wordlist <path> <delay ms>     Start dirbusting with custom wordlist",
    };

    size_t helpMessageSize = sizeof(helpMessage) / sizeof(helpMessage[0]);

    printf("StealthHunter %s\n", VERSION_SH);
    for (int i = 0; i < helpMessageSize; i++) {
        printf("%s\n", helpMessage[i]);
    }
}

int main(int argc, char * argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
            helpMessages();
        } else if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) {
            printf("StealthHunter version %s\n", VERSION_SH);
        } else if (strcmp(argv[1], "--dirbusting") == 0) {
            if ((argc == 6 || argc == 7) && strcmp(argv[2], "--url") == 0 && strcmp(argv[4], "--wordlist") == 0) {
                int sleepDelay = 0;

                if (argc == 7)
                    sleepDelay = atoi(argv[6]);

                dirbusting_valide_option(argv[3], argv[5], sleepDelay);
            } else {
                helpMessages();
            }
        } else {
            helpMessages();
        }
    } else {
        menu();
    }

    return 0;
}
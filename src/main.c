#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/check_nosql_injection.h"
#include "include/check_sql_injection.h"
#include "include/check_xss.h"
#include "include/dirbusting.h"
#include "include/colors.h"
#include "include/utils.h"
#include "include/version.h"

typedef struct {
    char *title;
    void (*init)(void);
    bool available;
} Module;

static const Module modules[4] = {
        { .title = "XSS", .init = check_xss, .available = false },
        { .title = "Injection NoSQL", .init = check_nosql_injection, .available = false },
        { .title = "Injection SQL", .init = check_sql_injection, .available = false },
        { .title = "Dir Busting", .init = dirbusting_prompts, .available = true }
};

void menu() {
    char *curl_version();
    bool menuIsActive = true;
    char inputUser[MAX_INPUT_SIZE];

    while (menuIsActive) {
        clear_console();

        print_logo();
        printf("%s Welcome to the StealthHunter Menu ! [D/Gabzdev] (S-H/%s)\n%s [%s]\n", INFO, VERSION_SH, OK, curl_version());
        size_t modulesSize = sizeof(modules) / sizeof(modules[0]);
        for (int i = 0; i < modulesSize; i++) {
            if (!modules[i].available) {
                printf("%d: %s %s(Not Available)%s\n", i+1, modules[i].title, RED, RESET);
            } else {
                printf("%d: %s %s(Available)%s\n", i+1, modules[i].title, GREEN, RESET);
            }
        }

        printf("%sq%s: quit\n", RED, RESET);
        printf("-> ");

        if (fgets(inputUser, MAX_INPUT_SIZE, stdin) != NULL) {
            inputUser[strcspn(inputUser, "\n")] = 0;

            int option = atoi(inputUser);
            if (option >= 1 && option <= sizeof(modules) / sizeof(modules[0])) {
                if (modules[option - 1].available) {
                    clear_console();
                    modules[option - 1].init();
                } else {
                    clear_console();
                }
            } else if (inputUser[0] == 'q') {
                menuIsActive = false;
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
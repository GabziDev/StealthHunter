#include "dirbusting.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>

#include "utils.h"

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

void dirbusting_start(const char *url) {
    CURL *curl;
    CURLcode res;
    long http_code = 0;

    const char *dirList[] = {"/admin", "/dashboard", "/.env", "/robots.txt", "/old", NULL};
    const char **dir = dirList;

    curl = curl_easy_init();
    if (curl) {
        while (*dir != NULL) {
            char full_url[2048];

            snprintf(full_url, sizeof(full_url), "%s%s", url, *dir);

            curl_easy_setopt(curl, CURLOPT_URL, full_url);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

            res = curl_easy_perform(curl);
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

            if (res == CURLE_OK) {
                printf("%s (%ld) %s \n", OK, http_code, full_url);
            } else {
                printf("%s (%ld) %s \n", ALERT, http_code, full_url);
            }

            dir++;
            sleep(1);
        }

        curl_easy_cleanup(curl);
    } else {
        printf("\n%s cURL initialization error...\n", ALERT);
    }

    printf("\n%s Press a key to exit...\n", INFO);
    getchar();
}

void dirbusting_prompts() {
    bool menuIsActive = true;
    char inputUser[100];

    while (menuIsActive) {
        print_logo();

        printf("%s==> You selected option 4 (Dir Busting)\n", YELLOW);
        printf("%s Press 'q' to exit\n", INFO);

        printf("\nWebsite URL : ");

        if (fgets(inputUser, sizeof(inputUser), stdin) != NULL) {
            inputUser[strcspn(inputUser, "\n")] = 0;

            if (strcmp(inputUser, "q") == 0) {
                clear_console();
                menuIsActive = false;
            } else if (strncmp(inputUser, "https://", 7) == 0 || strncmp(inputUser, "http://", 7) == 0) {
                menuIsActive = false;
                dirbusting_start(inputUser);
            } else {
                clear_console();
            }
        } else {
            clear_console();
        }
    }
}

void dirbusting_main() {
    dirbusting_prompts();
}

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>

#include "include/dirbusting.h"
#include "include/colors.h"
#include "include/utils.h"

// Callback data reçues par cURL
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

// Lnace le processus de dirbusting en parcourant le fichier wordlist
void dirbusting_start(const char *url, const char *path, int sleepDelay) {
    CURL *curl;
    CURLcode res;
    long http_code = 0;

    FILE* file = fopen(path, "r");

    print_logo();

    if (file == NULL) {
        printf("%s Empty file or not exist.", ALERT);
        return;
    }

    printf("\n<============>\n");
    printf("%s Url : %s\n", INFO, url);
    printf("%s World list : %s\n", INFO, path);
    printf("<============>\n");

    printf("\n%s Press a key to start.\n\n", WARNING);
    getchar();

    char line[2048];

    curl = curl_easy_init();
    if (curl) {
        while (fgets(line, sizeof(line), file) != NULL) {
            line[strcspn(line, "\n")] = 0;

            char full_url[2048];
            snprintf(full_url, sizeof(full_url), "%s%s", url, line); // concatenation de l'url avec un mot de la wordlist

            curl_easy_setopt(curl, CURLOPT_URL, full_url);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

            res = curl_easy_perform(curl); // exec la requete web
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code); // recuperer les infos de la réponse

            if (res == CURLE_OK) {
                printf("%s (%ld) %s \n", OK, http_code, full_url);
            } else {
                printf("%s (%ld) %s \n", ALERT, http_code, full_url);
            }

            if (sleepDelay > 0) {
                sleep_ms(sleepDelay);
            }
        }

        curl_easy_cleanup(curl);
    } else {
        printf("\n%s cURL initialization error...\n", ALERT);
    }

    fclose(file);

    printf("\n%s Press a key to exit...\n", INFO);
    getchar();
}

void dirbusting_valide_option(const char* inputUrl, const char* inputWordlist, int sleepDelay) {
    if (!is_valid_url(inputUrl)) {    // Verifier Input URL
        printf("%s Error: Invalid URL. Please use http:// or https://.\n", ALERT);
    } else if (!is_valid_file(inputWordlist)) {    // Verifier Input Worldlist
        printf("%s Error: Wordlist file does not exist.\n", ALERT);
    } else {
        // lancer le processus
        clear_console();
        dirbusting_start(inputUrl, inputWordlist, sleepDelay);
    }
}

// Prompt pour démarrer un dirbusting
void dirbusting_prompts() {
    char inputUrl[MAX_INPUT_SIZE];
    char inputWordlist[MAX_INPUT_SIZE];
    int inputDelay = 0;

    print_logo();

    printf("%s==> You selected option 4 (Dir Busting)\n", YELLOW);
    printf("%s Press 'q' to exit\n", INFO);

    // Input URL
    printf("\nWebsite URL [ http(s)://domain.com/ ] :");
    scanf("%s", inputUrl);

    // Input Wordlist
    printf("Wordlist Path [ /path/to/wordlist.txt ] : ");
    scanf("%s", inputWordlist);

    // Input Delay
    printf("Delay [ milliseconds ] : ");
    scanf("%d", &inputDelay);

    dirbusting_valide_option(inputUrl, inputWordlist, inputDelay);
}
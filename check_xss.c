#include "check_xss.h"

#include <stdio.h>

#include "utils.h"

void check_xss() {
    printf("%s You selected option 1 (Check XSS)\n", INFO);
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
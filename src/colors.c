#include "include/colors.h"

void print_logo() {
    printf("\n%s         ______   ____   ____  ____   ____  _____   ______   _________________      ______        _____   \n", GREEN);
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
#include "poker.h"
#include "help.h"

int main(void) {
    seed_rand();
    Option options[] = {
        {.msg = (unsigned char *)"1. Play Game", .sequence = (unsigned char *)"1"},
        {.msg = (unsigned char *)"2. Print Rules", .sequence = (unsigned char *)"2"},
        {.msg = (unsigned char *)"3. Exit", .sequence = (unsigned char *)"3"},
    };

    size_t selection;
    do {
        CLEAR_SCREEN();
        puts("To select an option, press the associated number key, use the arrow keys, or press J or K.\n\nThen, press [Enter] to confirm and submit your selection.\n");
        selection = menu(options, (unsigned char *)"Poker Main Menu", 3);
        switch (selection) {
            case 0:
                play_poker();
                break;
            case 1:
                CLEAR_SCREEN();
                puts(CURSOR_OFF);
                help(stdout);
                PAUSE();
                puts(CURSOR_ON);
                break;
            default:
                break;
        }
    } while (selection != 2);
    CLEAR_SCREEN();
    puts("\nThank you for playing poker!");
}
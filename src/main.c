#include "poker.h"

int main(void) {
    seed_rand();
    Option options[] = {
        {.msg = "1. Play Game", .sequence = "1"},
        {.msg = "2. Print Rules", .sequence = "2"},
        {.msg = "3. Exit", .sequence = "3"},
    };

    size_t selection;
    do {
        CLEAR_SCREEN();
        selection = menu(options, "Poker Main Menu", 3);
        switch (selection) {
            case 0:
                play_poker();
                break;
            case 1:
                printf("hi lol");
                PAUSE();
                break;
            default:
                break;
        }
    } while (selection != 2);
    CLEAR_SCREEN();
    puts("\nThank you for playing poker!");
}
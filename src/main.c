#include "ctty/menu/menu.h"

int main(void) {
    Option main_menu_opts[] = {
        {.msg = (unsigned char *)"1. Play Game", (unsigned char *)"1"},
        {.msg = (unsigned char *)"2. Print Rules", (unsigned char *)"2"},
        {.msg = (unsigned char *)"3. Exit", (unsigned char *)"3"},
    };
    menu(main_menu_opts, (unsigned char *)"Poker Main Menu", 3);
    system("clear");
}
#ifndef PLAYER_H
#define PLAYER_H
#include "hand.h"
#include "ctty/menu/menu.h"
#include "ctty/screen/screen.h"
#include <stdio.h>


Hand deal_player(Deck *deck);

char *alloc_card_str(Card card, int index);

#endif
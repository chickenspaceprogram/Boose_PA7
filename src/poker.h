#ifndef POKER_H
#define POKER_H

#include "player.h"
#include "dealer.h"

void play_poker(void); 

void print_hand(Hand *hand);

void print_card(Card card);

void print_hand_type(HandType type);

#endif
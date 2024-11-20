#ifndef DEALER_H
#define DEALER_H


#include "hand.h"

Hand deal_dealer(Deck *deck);

void set_redraws(Hand *hand, HandType type);

void find_redraws(Hand *hand, int *ranks_to_redraw, int num_ranks_redraw);

void clear_redraws(Hand *hand);

#endif
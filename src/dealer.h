#ifndef DEALER_H
#define DEALER_H


#include "hand.h"

/**
 * Function name: deal_dealer
 * Date created: 2024-11-20
 * Date last modified: 2024-11-20
 * Description: Deals the dealer's hand.
 * Inputs: 
 * `deck` : The deck of cards to draw from.
 * Outputs: none
 */
Hand deal_dealer(Deck *deck);

/**
 * Function name: set_redraws
 * Date created: 2024-11-20
 * Date last modified: 2024-11-20
 * Description: Decides which cards to redraw based on the hand that the dealer drew.
 * Inputs: 
 * `hand` : The dealer's hand.
 * `type` : The type of the dealer's hand (how it was scored).
 * Outputs: none
 */
void set_redraws(Hand *hand, HandType type);

/**
 * Function name: find_redraws
 * Date created: 2024-11-20
 * Date last modified: 2024-11-20
 * Description: Finds the cards in `hand` that need to be redrawn, and sets hand.redraw to true for those cards.
 * Inputs: 
 * `hand` : The hand in which to find redraws
 * `ranks_to_redraw` : The ranks of the cards which should be redrawn.
 * `num_ranks_redraw` : The number of elements in `ranks_to_redraw`.
 * Outputs: none
 */
void find_redraws(Hand *hand, int *ranks_to_redraw, int num_ranks_redraw);

/**
 * Function name: clear_redraws
 * Date created: 2024-11-20
 * Date last modified: 2024-11-20
 * Description: Sets every element in hand.redraw to false. 
 * Inputs: 
 * `hand` : The hand to clear.
 * Outputs: none
 */
void clear_redraws(Hand *hand);

#endif
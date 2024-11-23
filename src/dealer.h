#ifndef DEALER_H
#define DEALER_H


#include "hand.h"

/**
 * Function name: deal_dealer
 * Date created: 2024-11-20
 * Date last modified: 2024-11-20
 * Description: 
 * Inputs: 
 * Outputs: none
 */
Hand deal_dealer(Deck *deck);

/**
 * Function name: set_redraws
 * Date created: 2024-11-20
 * Date last modified: 2024-11-20
 * Description: 
 * Inputs: 
 * Outputs: none
 */
void set_redraws(Hand *hand, HandType type);

/**
 * Function name: find_redraws
 * Date created: 2024-11-20
 * Date last modified: 2024-11-20
 * Description: 
 * Inputs: 
 * Outputs: none
 */
void find_redraws(Hand *hand, int *ranks_to_redraw, int num_ranks_redraw);

/**
 * Function name: clear_redraws
 * Date created: 2024-11-20
 * Date last modified: 2024-11-20
 * Description: 
 * Inputs: 
 * Outputs: none
 */
void clear_redraws(Hand *hand);

#endif
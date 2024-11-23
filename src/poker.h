#ifndef POKER_H
#define POKER_H

#include "player.h"
#include "dealer.h"

/**
 * Function name: play_poker
 * Date created: 2024-11-21
 * Date last modified: 2024-11-21
 * Description: Plays a game of Poker.
 * Inputs: none
 * Outputs: none
 */
void play_poker(void); 

/**
 * Function name: print_hand
 * Date created: 2024-11-21
 * Date last modified: 2024-11-21
 * Description: Prints the cards that are in the hand given.
 * Inputs: 
 * `hand` : The hand to be printed
 * Outputs: none
 */
void print_hand(Hand *hand);

/**
 * Function name: print_card
 * Date created: 2024-11-21
 * Date last modified: 2024-11-21
 * Description: Prints a single card.
 * Inputs: 
 * `card` : The card to be printed
 * Outputs: none
 */
void print_card(Card card);

/**
 * Function name: print_hand_type
 * Date created: 2024-11-21
 * Date last modified: 2024-11-21
 * Description: Prints the best scoring combination of the hand.
 * Inputs: 
 * `type` : The scoring combination of the hand.
 * Outputs: none
 */
void print_hand_type(HandType type);

#endif
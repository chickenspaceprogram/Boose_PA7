#ifndef PLAYER_H
#define PLAYER_H
#include "hand.h"
#include "ctty/menu/menu.h"
#include "ctty/screen/screen.h"
#include <stdio.h>

/**
 * Function name: deal_player
 * Date created: 2024-11-21
 * Date last modified: 2024-11-21
 * Description: Deals the player their hand, prompting them for their chosen redraws.
 * Inputs: 
 * `deck` : The deck to draw from.
 * Outputs: The player's hand.
 */
Hand deal_player(Deck *deck);

/**
 * Function name: alloc_card_str
 * Date created: 2024-11-21
 * Date last modified: 2024-11-21
 * Description: Creates strings representing a card, formatted to be displayed in the menu.
 *              Strings are allocated on the heap, so they must be freed with a call to `free()`.
 * Inputs: 
 * `card` : The card to create a string of.
 * `index` : The index of the card.
 * Outputs: A pointer
 */
char *alloc_card_str(Card card, int index);

#endif
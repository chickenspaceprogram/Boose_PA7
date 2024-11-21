#ifndef DECK_H
#define DECK_H

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS NUM_RANKS * NUM_SUITS

#include "rand.h"
#include <stdio.h>

typedef enum suit {
    Clubs,
    Diamonds,
    Hearts,
    Spades,
} Suit;

typedef struct card {
    int rank;
    Suit suit;
} Card;

typedef struct deck Deck;
struct deck {
    Card cards[NUM_CARDS];
    int current_card;

    /**
     * Function name: shuffle
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: An implementation of the Durstenfeld version of the Fisher-Yates shuffle algorithm.
     *              Credit to: https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
     * Inputs: 
     * Outputs: none
     */
    void (*shuffle)(Deck *);

    /**
     * Function name: draw
     * Date created: 2024-11-18
     * Date last modified: 2024-11-18
     * Description: Draws a card off the top of the deck, and returns it.
     * Inputs:
     * `Deck *` : A pointer to the deck to draw from.
     * Outputs: The card that was drawn.
     */
    Card (*draw)(Deck *);
};

/**
 * Function name: newDeck
 * Date created: 2024-11-18
 * Date last modified: 2024-11-18
 * Description: Instantiates a new `Deck`, and shuffles it.
 * Inputs: none
 * Outputs: The new `Deck`.
 */
Deck newDeck(void);

#endif
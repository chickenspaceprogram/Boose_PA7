#ifndef DECK_H
#define DECK_H

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS NUM_RANKS * NUM_SUITS

#include "rand.h"

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

typedef struct deck {
    Card cards[NUM_CARDS];

    /**
     * Function name: Deck.shuffle
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: 
     * Inputs: 
     * Outputs: 
     */
    void (*shuffle)(Deck *);
} Deck;

Deck newDeck(void);

#endif
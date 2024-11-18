#ifndef DECK_H
#define DECK_H

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

#endif
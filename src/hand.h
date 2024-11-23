#ifndef HAND_H
#define HAND_H

#define HAND_SIZE       5
#define NUM_HAND_TYPES  8

#include <stdbool.h>
#include "deck.h"

#include <stdio.h>
#include "ctty/screen/screen.h"

typedef enum hand_type {
    None = 0,
    Pair,
    TwoPairs,
    ThreeKind,
    FourKind,
    FullHouse,
    Flush,
    Straight,
} HandType;

typedef enum states {
    InStraight,
    NotInStraight,
} States;


typedef struct hand Hand;
// i love function pointers
struct hand {
    Card cards[HAND_SIZE];
    bool redraw[HAND_SIZE]; // which cards to redraw
    int frequencies[NUM_RANKS];

    /**
     * Function name: Hand.hand_check[None]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: Checks whether the hand contains at least no combination of cards.
     *              Always returns `true`.
     * Inputs: 
     * `Hand *` : The hand in which to check.
     * Outputs: `true` if the hand has no pair (never returns false)
     */
    /**
     * Function name: Hand.hand_check[Pair]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: Checks whether the hand contains at least one pair.
     * Inputs: 
     * `Hand *` : The hand in which to check.
     * Outputs: `true` if the hand has at least one pair, `false` if it does not
     */
    /**
     * Function name: Hand.hand_check[TwoPairs]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: Checks whether the hand contains two pairs.
     * Inputs: 
     * `Hand *` : The hand in which to check.
     * Outputs: `true` if the hand has two pairs, `false` if it does not
     */
    /**
     * Function name: Hand.hand_check[ThreeKind]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: Checks whether the hand contains at least three-of-a-kind
     * Inputs: 
     * `Hand *` : The hand in which to check.
     * Outputs: `true` if the hand has at least three-of-a-kind, `false` if it does not
     */
    /**
     * Function name: Hand.hand_check[FourKind]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: Checks whether the hand contains at least four-of-a-kind.
     * Inputs: 
     * `Hand *` : The hand in which to check.
     * Outputs: `true` if the hand has four-of-a-kind, `false` if it does not
     */
    /**
     * Function name: Hand.hand_check[FullHouse]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: Checks whether the hand contains a full house.
     * Inputs: 
     * `Hand *` : The hand in which to check.
     * Outputs: `true` if the hand has a full house, `false` if it does not
     */
    /**
     * Function name: Hand.hand_check[Flush]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: Checks whether the hand contains a flush.
     * Inputs: 
     * `Hand *` : The hand in which to check.
     * Outputs: `true` if the hand has a flush, `false` if it does not
     */
    /**
     * Function name: Hand.hand_check[Straight]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: Checks whether the hand contains a straight.
     * Inputs: 
     * `Hand *` : The hand in which to check.
     * Outputs: `true` if the hand has a straight, `false` if it does not
     */
    bool (*hand_check[NUM_HAND_TYPES])(Hand *);  // the function comments make this extra cursed :)

    /**
     * Function name: find_best_hand
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: Checks to see which HandTypes a hand matches, returns the best one.
     * Inputs:
     * `Hand *` : The hand to check
     * Outputs: The best HandType of the hand.
     */
    HandType (*find_best_hand)(Hand *);

    /**
     * Function name: draw_cards
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: If hand->redraw[i] == `true`, a card is redrawn for the space hand->cards[i].
     * Inputs:
     * `Hand *` : The hand to redraw cards for.
     * `Deck *` : The deck to redraw cards from.
     * Outputs: none
     */
    void (*draw_cards)(Hand *, Deck *);

    /**
     * Function name: set_frequencies
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: Calculates the frequencies of the cards in the hand.
     * Inputs:
     * `Hand *` : The hand to calculate the frequencies of.
     * Outputs: none
     */
    void (*set_frequencies)(Hand *);
};

Hand newHand(void);

#endif
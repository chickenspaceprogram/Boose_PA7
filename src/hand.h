#ifndef HAND_H
#define HAND_H

#include <stdbool.h>
#include "deck.h"

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

// i love function pointers
typedef struct hand {
    Card cards[5];
    int freq_tbl[14];

    /**
     * Function name: Hand.hand_check[None]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: 
     * Inputs: 
     * Outputs: `true` if the hand has a pair, `false` if it does not
     */
    /**
     * Function name: Hand.hand_check[Pair]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: 
     * Inputs: 
     * Outputs: `true` if the hand has two pairs, `false` if it does not
     */
    /**
     * Function name: Hand.hand_check[TwoPairs]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: 
     * Inputs: 
     * Outputs: `true` if the hand has three-of-a-kin, `false` if it does not
     */
    /**
     * Function name: Hand.hand_check[ThreeKind]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: 
     * Inputs: 
     * Outputs: 
     */
    /**
     * Function name: Hand.hand_check[FourKind]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: 
     * Inputs: 
     * Outputs: 
     */
    /**
     * Function name: Hand.hand_check[FullHouse]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: 
     * Inputs: 
     * Outputs: 
     */
    /**
     * Function name: Hand.hand_check[Flush]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: 
     * Inputs: 
     * Outputs: 
     */
    /**
     * Function name: Hand.hand_check[Straight]
     * Date created: 2024-11-17
     * Date last modified: 2024-11-17
     * Description: 
     * Inputs: 
     * Outputs: 
     */
    bool (*hand_check[8])(Hand *);  // the function comments make this extra cursed :)
    HandType (*find_best_hand)(Hand *);
    void (*draw_cards)(Hand *);
    void (*set_frequencies)(Hand *);
} Hand;

Hand newHand(void);

#endif
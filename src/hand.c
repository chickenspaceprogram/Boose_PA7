#include "hand.h"

// fn headers are in hand.h
bool hand_is_none(Hand *hand);
bool hand_is_pair(Hand *hand);
bool hand_is_two_pairs(Hand *hand);
bool hand_is_three_kind(Hand *hand);
bool hand_is_four_kind(Hand *hand);
bool hand_is_full_house(Hand *hand);
bool hand_is_flush(Hand *hand);
bool hand_is_straight(Hand *hand);
HandType find_best_hand(Hand *hand);
void draw_cards(Hand *hand, Deck *deck);
void set_frequencies(Hand *hand);

/* private */

/**
 * Function name: set_arr_to_val
 * Date created: 2024-11-17
 * Date last modified: 2024-11-17
 * Description: Sets all values in an array to a certain value.
 * Inputs: 
 * `arr` : The array
 * `val` : The value
 * `len` : The length of the array
 * Outputs: none
 */
static void set_arr_to_val(bool *arr, bool val, int len);

Hand newHand(void) {
    Hand hand;
    set_arr_to_val(hand.redraw, true, HAND_SIZE);

    hand.hand_check[None] = &hand_is_none;
    hand.hand_check[Pair] = &hand_is_pair;
    hand.hand_check[TwoPairs] = &hand_is_two_pairs;
    hand.hand_check[ThreeKind] = &hand_is_three_kind;
    hand.hand_check[FourKind] = &hand_is_four_kind;
    hand.hand_check[FullHouse] = &hand_is_full_house;
    hand.hand_check[Flush] = &hand_is_flush;
    hand.hand_check[Straight] = &hand_is_straight;


    hand.find_best_hand = &find_best_hand;
    hand.draw_cards = &draw_cards;
    hand.set_frequencies = &set_frequencies;
    return hand;
}


bool hand_is_none(Hand *hand) {
    return true; // hand is always none
}

bool hand_is_pair(Hand *hand) {
    hand->set_frequencies(hand);
    for (int i = 0; i < NUM_RANKS; ++i) {
        if (hand->frequencies[i] >= 2) {
            return true;
        }
    }
    return false;
}

bool hand_is_two_pairs(Hand *hand) {
    hand->set_frequencies(hand);
    int num_pairs = 0;
    for (int i = 0; i < NUM_RANKS; ++i) {
        if (hand->frequencies[i] >= 2) {
            ++num_pairs;
            if (num_pairs == 2) {
                return true;
            }
        }
    }
    return false;
}

bool hand_is_three_kind(Hand *hand) {
    hand->set_frequencies(hand);
    for (int i = 0; i < NUM_RANKS; ++i) {
        if (hand->frequencies[i] >= 3) {
            return true;
        }
    }
    return false;
}

bool hand_is_four_kind(Hand *hand) {
    hand->set_frequencies(hand);
    for (int i = 0; i < NUM_RANKS; ++i) {
        if (hand->frequencies[i] >= 4) {
            return true;
        }
    }
    return false;
}

bool hand_is_full_house(Hand *hand) {
    Suit suit = hand->cards[0].suit;
    for (int i = 1; i < NUM_RANKS; ++i) {
        if (suit != hand->cards[i].suit) {
            return false;
        }
    }

    return true;
}

bool hand_is_flush(Hand *hand) {
    hand->set_frequencies(hand);
    for (int i = 0; i < NUM_RANKS; ++i) {
        if (hand->frequencies[i] == 5) {
            return true;
        }
    }
    return false;
}

bool hand_is_straight(Hand *hand) {
    hand->set_frequencies(hand);
    States state = NotInStraight;
    int straight_len = 0;
    for (int i = 0; i < NUM_RANKS; ++i) {
        if (state == InStraight) {
            if (straight_len == 5) {
                return true;
            }
            if (hand->frequencies[i] != 1) {
                return false;
            }
            ++straight_len;
        }
        else if (hand->frequencies[i] == 1) {
            state = InStraight;
            straight_len = 1;
        }
    }
    if (straight_len == 5) {
        return true;
    }
    return false;
}

HandType find_best_hand(Hand *hand) {
    for (int i = NUM_HAND_TYPES - 1; i >= 0; --i) {
        if (hand->hand_check[i](hand)) { // an array of function pointers was an interesting design choice but it paid off here
            return (HandType)i; // the rust programmer in me hates typecasting int -> enum but it is convenient
        }
    }
    return 0; // should never return here
}

void draw_cards(Hand *hand, Deck *deck) {
    for (int i = 0; i < HAND_SIZE; ++i) {
        if (hand->redraw[i]) {
            hand->cards[i] = deck->draw(deck);
        }
    }
}

void set_frequencies(Hand *hand) {
    for (int i = 0; i < NUM_RANKS; ++i) {
        hand->frequencies[i] = 0;
    }

    for (int i = 0; i < HAND_SIZE; ++i) {
        ++(hand->frequencies[hand->cards[i].rank]);
    }
}

/* private */

void set_arr_to_val(bool *arr, bool val, int len) {
    for (int i = 0; i < len; ++i) {
        arr[i] = val;
    }
}
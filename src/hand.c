#include "hand.h"

bool hand_is_none(Hand *hand);
bool hand_is_pair(Hand *hand);
bool hand_is_two_pairs(Hand *hand);
bool hand_is_three_kind(Hand *hand);
bool hand_is_four_kind(Hand *hand);
bool hand_is_full_house(Hand *hand);
bool hand_is_flush(Hand *hand);
bool hand_is_straight(Hand *hand);

int find_best_hand(Hand *hand);

void draw_cards(Hand *hand, Deck *deck);
void set_frequencies(Hand *hand);

/* private */
static int get_straight_len(Hand *hand);
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
    for (int i = 0; i < NUM_RANKS; ++i) {
        if ((hand->frequencies[i] != 3) && (hand->frequencies[i] != 2) && (hand->frequencies[i] != 0)) {
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
    if (get_straight_len(hand) != 5) {
        return false;
    }
    return true;
}

int find_best_hand(Hand *hand) {
    for (int i = NUM_HAND_TYPES - 1; i >= 0; --i) {
        if (hand->hand_check[i](hand)) { // an array of function pointers was an interesting design choice but it paid off here
            return i;
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

int get_straight_len(Hand *hand) {
	int longest_straight_len = 0, current_straight_len = 0;

	for (int i = 0; i < NUM_RANKS; ++i) {
		// if there is at least one die with the current value, increase the straight length
		if (hand->frequencies[i] == 1) {
			++current_straight_len;
		}
		else {
			// otherwise, the straight has ended, so figure out whether it's the longest
			if (current_straight_len > longest_straight_len) {
				longest_straight_len = current_straight_len;
			}
			current_straight_len = 0;
		}
	}
	// we could've ended our loop on a straight, so check how long it is
	if (current_straight_len > longest_straight_len) {
		longest_straight_len = current_straight_len;
	}
	return longest_straight_len;
}

void set_arr_to_val(bool *arr, bool val, int len) {
    for (int i = 0; i < len; ++i) {
        arr[i] = val;
    }
}
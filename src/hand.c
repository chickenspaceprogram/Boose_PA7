#include "hand.h"

static bool hand_is_none(Hand *hand);
static bool hand_is_pair(Hand *hand);
static bool hand_is_two_pairs(Hand *hand);
static bool hand_is_three_kind(Hand *hand);
static bool hand_is_four_kind(Hand *hand);
static bool hand_is_full_house(Hand *hand);
static bool hand_is_flush(Hand *hand);
static bool hand_is_straight(Hand *hand);

static int find_best_hand(Hand *hand);

static void draw_cards(Hand *hand);
static void set_frequencies(Hand *hand);

Hand newHand(void) {
    Hand hand;

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

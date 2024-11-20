#include "dealer.h"

Hand deal_dealer(Deck *deck) {
    // initializing hand
    Hand dealer_hand = newHand();
    dealer_hand.draw_cards(&dealer_hand, deck);

    // checking type, setting redraws
    HandType type = dealer_hand.find_best_hand(&dealer_hand);
    set_redraws(&dealer_hand, type);

    // redrawing
    dealer_hand.draw_cards(&dealer_hand, deck);
    return dealer_hand;
}

void set_redraws(Hand *hand, HandType type) {
    int ranks_to_redraw[5] = {0};
    int counter = 0;
    hand->set_frequencies(hand);
    clear_redraws(hand);
    switch (type) {
        case Straight: case Flush: case FullHouse:
            return;
        case None:
            for (int i = 0; i < 3; ++i) {
                hand->redraw[i] = true;
            }
            return;
        case FourKind:
            for (int i = 0; i < NUM_RANKS; ++i) {
                if (hand->frequencies[i] == 1) {
                    ranks_to_redraw[i] = i;
                    ++counter;
                }
            }
            break;
        case ThreeKind:
            for (int i = 0; i < NUM_RANKS; ++i) {
                if (hand->frequencies[i] > 0 && hand->frequencies[i] != 3) {
                    ranks_to_redraw[i] = i;
                    ++counter;
                }
            }
            break;
        case TwoPairs: case Pair:
            for (int i = 0; i < NUM_RANKS; ++i) {
                if (hand->frequencies[i] > 0 && hand->frequencies[i] != 2) {
                    ranks_to_redraw[i] = i;
                    ++counter;
                }
            }
            break;

    }
    find_redraws(hand, ranks_to_redraw, counter);
}

void find_redraws(Hand *hand, int *ranks_to_redraw, int num_ranks_redraw) {
    for (int i = 0; i < num_ranks_redraw; ++i) {
        for (int j = 0; j < HAND_SIZE; ++j) {
            if (hand->cards[j].rank == ranks_to_redraw[i]) {
                hand->redraw[j] = true;
            }
        }
    }
}

void clear_redraws(Hand *hand) {
    for (int i = 0; i < HAND_SIZE; ++i) {
        hand->redraw[i] = false;
    }
}
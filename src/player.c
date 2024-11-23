#include "player.h"

Hand deal_player(Deck *deck) {
    Hand hand = newHand();
    hand.draw_cards(&hand, deck);
    Option options[HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; ++i) {
        options[i].msg = (unsigned char *)alloc_card_str(hand.cards[i], i + 1);
        if (options[i].msg == NULL) {
            for (int j = 0; j < i; ++i) {
                free(options[i].msg);
            }
            return hand; // yeah itll be broken if malloc fails but malloc will neeever fail, riiiight?
        }
    }
    options[0].sequence = (unsigned char *)"1"; options[1].sequence = (unsigned char *)"2"; options[2].sequence = (unsigned char *)"3"; options[3].sequence = (unsigned char *)"4"; options[4].sequence = (unsigned char *)"5"; // lazy but it works :)
    CLEAR_SCREEN();
    puts("Use the arrow keys or the associated number to navigate to your desired option.\nThen, press [Space] to select that option.\nYou can select up to 3 options.\n\nTo confirm your current selections, press [Enter].\n\n");
    multimenu(options, (unsigned char *)"Redraw Selection", HAND_SIZE, hand.redraw, 3);
    hand.draw_cards(&hand, deck);
    for (int i = 0; i < HAND_SIZE; ++i) {
        free(options[i].msg);
    }
    return hand;

}

char *alloc_card_str(Card card, int index) {
    char *suit, *rank, *output;
    char chr[2];
    switch (card.suit) {
        case Clubs:
            suit = "Clubs";
            break;
        case Diamonds:
            suit = "Diamonds";
            break;
        case Hearts:
            suit = "Hearts";
            break;
        case Spades:
            suit = "Spades";
            break;
    }
    switch (card.rank) {
        case 0:
            rank = "Ace";
            break;
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
            chr[0] = card.rank + '1';
            chr[1] = '\0';
            rank = chr;
            break;
        case 9:
            rank = "10";
            break;
        case 10:
            rank = "Jack";
            break;
        case 11:
            rank = "Queen";
            break;
        case 12:
            rank = "King";
            break;
    }
    if (asprintf(&output, "%d. %s of %s", index, rank, suit) == -1) {// gotta free!
        return NULL;
    }
    return output;
}
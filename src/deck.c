#include "deck.h"

/**
 * Function name: fill_deck_suit
 * Date created: 2024-11-17
 * Date last modified: 2024-11-17
 * Description: 
 * Inputs: 
 * Outputs: 
 */
static void fill_deck_suit(Deck *deck, int start_index, Suit suit);

static void shuffle(Deck *deck);

static Card draw(Deck *deck);

Deck newDeck(void) {
    Deck deck;
    deck.shuffle = &shuffle;
    deck.draw = &draw;
    deck.current_card = 0;

    // couldve used a loop but oh well
    fill_deck_suit(&deck, 0, Clubs);
    fill_deck_suit(&deck, NUM_RANKS, Diamonds); // could've used a static variable inside fill_deck_suit but this is more clear
    fill_deck_suit(&deck, 2 * NUM_RANKS, Hearts);
    fill_deck_suit(&deck, 3 * NUM_RANKS, Spades);
    
    deck.shuffle(&deck);
    return deck;
}

void fill_deck_suit(Deck *deck, int start_index, Suit suit) {
    Card current_card = {.suit = suit, .rank = 0};
    for (int i = 0; i < NUM_RANKS; ++i) {
        current_card.rank = i;
        deck->cards[i + start_index] = current_card;
    }
}

void shuffle(Deck *deck) {
    int rand_index;
    Card temp;
    for (int i = NUM_CARDS - 1; i > 0; --i) {
        rand_index = randint(0, i + 1); // `i` might not move
        temp = deck->cards[i];
        deck->cards[i] = deck->cards[rand_index];
        deck->cards[rand_index] = temp;
    }
}

Card draw(Deck *deck) {
    return deck->cards[(deck->current_card)++];
}
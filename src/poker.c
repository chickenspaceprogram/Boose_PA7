#include "poker.h"

void play_poker(void) {
    Deck deck = newDeck();
    Hand dealer = deal_dealer(&deck);
    Hand player = deal_player(&deck);
    HandType dealer_handtype = dealer.find_best_hand(&dealer);
    HandType player_handtype = player.find_best_hand(&player);
    CLEAR_SCREEN();
    puts("\nDealer cards:\n");
    print_hand(&dealer);
    puts("\nYour cards:\n");
    print_hand(&player);
    puts("\n");
    fputs("The dealer had ", stdout);
    print_hand_type(dealer_handtype);
    fputs("\nYou had ", stdout);
    print_hand_type(player_handtype);
    if (dealer_handtype > player_handtype) {
        puts("\n\nThe dealer won.");
    }
    else if (dealer_handtype == player_handtype) {
        puts("\n\nYou tied with the dealer.");
    }
    else {
        puts("\n\nYou won!");
    }
    puts("\nPress any key to continue . . ."CURSOR_OFF);
    PAUSE();
    fputs(CURSOR_ON, stdout);
}

void print_hand(Hand *hand) {
    for (int i = 0; i < HAND_SIZE; ++i) {
        print_card(hand->cards[i]);
    }
}

void print_card(Card card) {
    char *suit, *rank;
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
    printf("%s of %s\n", rank, suit);
    
    return;
}

void print_hand_type(HandType type) {
    switch (type) {
        case None:
            fputs("no scoring combination", stdout);
            break;
        case Pair:
            fputs("a pair", stdout);
            break;
        case TwoPairs:
            fputs("two pairs", stdout);
            break;
        case ThreeKind:
            fputs("three of a kind", stdout);
            break;
        case FourKind:
            fputs("four of a kind ", stdout);
            break;
        case FullHouse:
            fputs("a full house", stdout);
            break;
        case Flush:
            fputs("a flush", stdout);
            break;
        case Straight:
            fputs("a straight", stdout);
            break;
    }
}
#include "player.h"
#include "dealer.h"

int main(void) {
    seed_rand();
    Deck deck = newDeck();
    Hand dealer = deal_dealer(&deck);
    Hand player = deal_player(&deck);
    
}
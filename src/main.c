#include "player.h"
#include "dealer.h"

int main(void) {
    Deck deck = newDeck();
    Hand dealer = deal_dealer(&deck);
    Hand player = deal_player(&deck);
    
}
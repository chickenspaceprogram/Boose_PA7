#include "rand.h"

void seed_rand(void) {
	srand((unsigned int) time(NULL));
}

int randint(int min, int max) {
    int diff = max - min;
    return (rand() % diff) + min;
}
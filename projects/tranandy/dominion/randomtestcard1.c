// Random unit test for Baron card
// References: testUpdateCoins.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int i, n;
    int p, handCount;
	int pIndex, preBuy, postBuy, preHand, postHand;
    struct gameState G;

    printf ("RANDOM TESTING Baron card:\n");

	// settings for rng
	SelectStream(2);
  	PutSeed(3);

	// randomize gamestate (references testDrawCard.c)
	for (n = 2; n < 4; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
		((char*)&G)[i] = floor(Random() * 256);
		}
		p = floor(Random() * 2);
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);

		// iterate through all players
		for (pIndex = 0; pIndex < n; pIndex++){

			// iterate through all combinations of hands
			for (handCount = 1; handCount <= MAX_HAND; handCount++){

				//iterate boolean for estate
				for (i = 0; i < 2; i++){

					// save pre baron state
					preBuy = G.numBuys;
					preHand = sizeof(G.hand[pIndex]);

					// choice made to discard estate
					if (i == 1){
						myBaronCard(i, G, handCount, pIndex);
						postBuy = G.numBuys;
						postHand = sizeof(G.hand[pIndex]);

						//check buy action increased by 1
						//check that card was discarded
						assert(postBuy == preBuy + 1);
						assert(postHand == preHand - 1);
					}

					// choice made to gain estate
					else {
						myBaronCard(i, G, handCount, pIndex);
						postBuy = G.numBuys;
						postHand = sizeof(G.hand[pIndex]);

						//check buy action increased by 1
						//check that card was gained
						assert(postBuy == preBuy + 1);
						assert(postHand == preHand + 1);
					}
				}
			}
		}
	}

	printf("RANDOM TESTING Baron card - ALL PASS")

    return 0;
}

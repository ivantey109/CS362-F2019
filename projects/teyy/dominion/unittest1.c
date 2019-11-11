// unit test 1

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <time.h>
#include <string.h> 
#include "dominion_helpers.h"
#include <assert.h>
#include "dominion.c"

void cardEffectbaron(struct gameState *state, int choice1, int currentPlayer, int handPos);


int main()
{
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    struct gameState G;
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    int i =0;
    int count = 0;
    int r;
    int choice1;
    int currentPlayer;
    int handPos;
    int card_not_discard;
    memset(&G, 23, sizeof(struct gameState));   // setthe game state

    cardEffectbaron(&G, choice1, currentPlayer, handPos);

    printf("BEgin testing baron discard card \n");


    assert(card_not_discard); // if card_not discard != 1, then error
    assert(handPos);

    printf("Discard card done!\n");

    printf("Being testing baron get coin\n");

    for(i = -5; i< 30; i++) // loop from -5 to 30
    {
        count = getCost(i);

        if(count != 4) //if the get coin is not 4, then something wrong
        {
            break;
        }
    }

    printf("Get Coin Done!!\n"); // finish checking
    printf("Finish testing baron\n");


}

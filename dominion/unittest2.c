// unit test 2

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <time.h>
#include <string.h> 
#include "dominion_helpers.h"
#include <assert.h>
#include "dominion.c"

int cardEffectminion(struct gameState *state, int choice1, int currentPlayer, int handPos, int choice2);


                        // while( state->handCount[i] > 0 )
                        // {
                        //     discardCard(handPos, i, state, 1);
                        //     printf("%d", i); // adding printf here will know that is infinite loop
                        //     x ++;
                        //     if(x == 100) // return if x == 100
                        //         return 1;
                        // }
                        //added into domino.c function
int main()
{
    struct gameState G;
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    int i =0;
    int count = 0;
    int choice1;
    int currentPlayer;
    int handPos;
    int choice2;
    int getReturn;
    memset(&G, 23, sizeof(struct gameState));   // setthe game state
    printf("BEgin testing Minion  \n");
     getReturn = cardEffectminion(&G, choice1, currentPlayer, handPos, choice2);

    assert(getReturn == 1); // we will know when getReturn == 1. then something wrong

    for(i = -5; i< 30; i++) // loop from -5 to 30
    {
        count = getCost(i);

        if(count != 2) //if the get coin is not 2, then something wrong
        {
            break;
            printf("ERROR, get coin is not 2");
        }
    }
    
    printf("Finish testing Minion\n");


}


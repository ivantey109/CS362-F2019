// unit test 2

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <time.h>
#include <string.h> 
#include "dominion_helpers.h"
#include "dominion.c"
#include <assert.h>

int cardEffectambassador(struct gameState *state, int choice1, int currentPlayer, int handPos, int choice2);

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
    printf("BEgin testing Amvassador  \n");
    
    getReturn =  cardEffectambassador(&G, choice1, currentPlayer, handPos, choice2);

    assert(choice2 > 2);
    assert(choice2 < 0); // to know the choice 2 is in the range of the correct amount
    assert(choice1 == handPos); // have to know the choice 1 is same as handPos

    printf("Finish testing Ambassador\n");


}


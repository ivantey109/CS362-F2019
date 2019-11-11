// unit test 2

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <time.h>
#include <string.h> 
#include "dominion_helpers.h"
#include <assert.h>
#include "dominion.c"

int cardEffectmine(struct gameState *state, int choice1, int currentPlayer, int handPos, int choice2, int nextPlayer);

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
    int nextPlayer = currentPlayer +1;
    int currentCoin;
        currentCoin = G.coins;
    memset(&G, 23, sizeof(struct gameState));   // setthe game state
    getReturn = cardEffectmine(&G, choice1, currentPlayer, handPos, choice2, nextPlayer);

    printf("BEgin testing Tribute  \n");

    assert(choice2 < copper);
    assert(choice2 > gold);// we have to check if the choice2 is in the range of copper or gold

   
    printf("Finish testing Tribute\n");


}


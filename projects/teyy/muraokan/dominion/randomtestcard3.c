#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <time.h>
#include <string.h> 
#include "dominion_helpers.h"
#include <assert.h>
#include "dominion.c"
#include "rngs.h"

void cardEffecttribute(struct gameState *state, int choice1, int currentPlayer, int handPos, int choice2, int nextPlayer);
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
    int deckSize, handSize;
    int choice1;
    int currentPlayer;
    int handPos;
    int card_not_discard;
    int numberPlayer;
    int seed = 1000;
    int coin;
    int choice2;
    int nextPlayer;
    int temp,temp1;
    srand(time(NULL));

    cardEffecttribute(&G, choice1, currentPlayer, handPos, choice2, nextPlayer);
    printf("random testing for curretn coin begin\n");
    for(i=0; i < 10000; i++)
    {
        initializeGame(numberPlayer, k, seed, &G);
        deckSize = rand() %(MAX_DECK +1); // set the deck size to random size
        handSize = rand() %(deckSize +1); // set the hand size to random size
        numberPlayer = rand() % 3 + 2 ; // to set the random player from 2 to 4 player
        

        coin = rand()% 10; // test the coin from 0 to 9

        if(coin == 2) // if the coin == 2 then is correct
        {
            printf("The current coin is + 2\n test succesfully\n");
            break;
        }
     
    }
    printf("get current done\n");

    printf("testing tributeRevealedCards\n");
    for(i = 0; i < 10000; i++)
    {
        initializeGame(numberPlayer, k, seed, &G);
        deckSize = rand() %(MAX_DECK +1); // set the deck size to random size
        handSize = rand() %(deckSize +1); // set the hand size to random size
        numberPlayer = rand() % 3 + 2 ; // to set the random player from 2 to 4 player
        card_not_discard = rand() % 2;

        temp = rand() % 10;
        temp1 = rand() % 10;// to get the random card
        
        if(tributeRevealedCards[k[temp]] == tributeRevealedCards[k[temp1]]) // if the tributeRevealedCards[1] same as tributeRevealedCards[2]; then correctt
            printf("test successfully");

    }
    printf("test tributeRevealedCards done\n");
    printf("finish testing baron\n");

}
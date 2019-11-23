#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"

// Random Test function for Tribute card effect
int main(){
    srand((unsigned)time(NULL));// variable for random num generator
    struct gameState* state;
    int numPlayers = 4; // the number of player
    int seed = 100;
    int card[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room}; 

    // 1 to 3 simulates copper, silver, gold and 4 to 8 simulates estate, dutcy, province, gardens, great hall
    int tributeRevealedCards = rand() % 8 + 1;
    int numOfCoins = 0;
    int handsBefore, handsAfter = 0;
    int coinsBefore, coinsAfter = 0;
    int nextPlayerDeckCountBefore = 0;
    int discardCountBefore = 0;
    int supplyCountBefore, supplyCountAfter = state->supplyCount[estate];
    int p = 0;//Iterator for hand!
    int i,j;
    int handPos = 0;
    int numOfActionsBefore, numOfActionsAfter = 0;

    for(i=0; i<1000; i++){ // the number of tests to run

        // initialize the game status
        initializeGame(numPlayers, card, seed, &state);

        // decraling the variable for the Tribute card test
        int currentPlayer, nextPlayer, card_not_discarded;
        currentPlayer = rand() % 1 + 4; // ranges between 1 to 4 for the player
        nextPlayer = currentPlayer-1; //left player from current players position

        // store the number of the coins before conducting the function
        nextPlayerDeckCountBefore =  state-> deckCount[nextPlayer];
        discardCountBefore = state->discardCount[nextPlayer];
        coinsBefore = state->coins;
        handsBefore = state->hand[currentPlayer][p];
        numOfActionsBefore = state->numActions;
        handsBefore = state->playedCardCount;

        // tribute card effect function call
        tributeCardEffect(state, nextPlayer, currentPlayer, tributeRevealedCards, handPos);

        // check whether the program correctly retrieved value for tributeRevealedCards array
        if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1) {
            if (state->deckCount[nextPlayer] > 0) {
                if(state-> deckCount[nextPlayer] != (nextPlayerDeckCountBefore - 1))
                    printf("The deck count is not correct");
            }
            else if(state->discardCount[nextPlayer] > 0){
                if(state-> discardCount[nextPlayer] != (nextPlayerDeckCountBefore - 1))
                    printf("The deck count is not correct");
            }
            else{
                printf("No error condition has detected");
            }
        }

        // checking the condition of Action card, Treasure card, Victory card
        for (i = 0; i < 2; i ++) {
            if(tributeRevealedCards == 1 || tributeRevealedCards == 2 || tributeRevealedCards == 3)
                if(coinsAfter != coinsBefore + 2){
                    printf("The number of coins after function call have some problem");
                }
            else if(tributeRevealedCards == 4 || tributeRevealedCards == 5 || tributeRevealedCards == 6 || tributeRevealedCards == 7 || tributeRevealedCards == 8){
                if(handsAfter != handsBefore + 1){
                    printf("The number of player hands after function call have some problem");
                }
            }
            else{
                if(numOfActionsAfter != numOfActionsBefore + 2){
                    printf("The number of action cards for a player after function call have some problem");
                }
            }
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"

// Unit Test function for Baron card effect
int main(){
    srand((unsigned)time(NULL));// variable for random num generator
    struct gameState* state;
    int numPlayers = 4; // the number of player
    int seed = 100;
    int card[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room}; 
    int numOfCoins = 0;
    int handsBefore, handsAfter = 0;
    int coinsBefore, coinsAfter = 0;
    int discardCountBefore, discardCountAfter = 0;
    int supplyCountBefore, supplyCountAfter = state->supplyCount[estate];
    int p = 0;//Iterator for hand!
    int i;
    int handPos = 0;

    for(i=0; i<1000; i++){ // the number of tests to run

        // initialize the game status
        initializeGame(numPlayers, card, seed, &state);

        // decraling the variable for the Baron card test
        int choice1, currentPlayer, card_not_discarded;
        choice1 = rand() % 1 + 2; // either estate or not
        currentPlayer = rand() % 1 + 4; // ranges between 1 to 4 for the player
        card_not_discarded = rand() % 1 + 2; // either estate or not
        
        // store the number of the coins before conducting the function
        coinsBefore = state->coins;
        handsBefore = state->hand[currentPlayer][p];
        discardCountBefore = state->discardCount[currentPlayer];

        // if player choose to discard 1 estate card
        if(choice1 > 0){
            // function call for barron card effect
            BaronCardEffect(choice1, currentPlayer, state, handPos);

            // checking the number of coins after Barron has played
            coinsAfter = state->coins;
            if(coinsAfter != coinsBefore + 4){
                printf("The number of coins is not correct\n");
            }

            // checking the number of hands current player have after Barron has played
            handsAfter = state->hand[currentPlayer][p];
            if(handsAfter != handsBefore - 1){
                printf("The number of player's hands are not correct\n");
            }
            discardCountAfter = state->discardCount[currentPlayer]++;
            if(discardCountAfter != discardCountBefore++){
                printf("The number of discard count is not correct");
            }
        }
        else{
            // function call for barron card effect
            BaronCardEffect(choice1, currentPlayer, state, handPos);
            supplyCountAfter = state->supplyCount[estate];

            // if supply count has not correctly subtracted
            if(supplyCountAfter != supplyCountBefore - 1){ 
                printf("The number of supply count are not correct\n");
            }
            handsAfter = state->hand[currentPlayer][p];
            if(handsAfter != handsBefore + 1){
                printf("The number of player's hands are not correct\n");
            }
        }
    }
}
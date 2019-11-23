#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"

// Random Test function for Minion card effect
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
    int supplyCountBefore, supplyCountAfter = state->supplyCount[estate];
    int p = 0;//Iterator for hand!
    int i,j;
    int handPos = 0;
    int numOfActionsBefore, numOfActionsAfter = 0;

    for(i=0; i<1000; i++){ // the number of tests to run

        // initialize the game status
        initializeGame(numPlayers, card, seed, &state);

        // decraling the variable for the Baron card test
        int choice1, choice2, currentPlayer, card_not_discarded;
        choice1 = rand() % 1 + 2; 
        choice2 = rand() % 1 + 2;
        currentPlayer = rand() % 1 + 4; // ranges between 1 to 4 for the player
        
        // store the number of the coins before conducting the function
        coinsBefore = state->coins;
        handsBefore = state->hand[currentPlayer][p];
        numOfActionsBefore = state->numActions;

        // if choice 1 has selected
        if(choice1 > 0){
            // function call for card effect
            minionCardEffect(state, currentPlayer, handPos, choice1, choice2);

            // checking the number of coins after Minion has played
            coinsAfter = state->coins;
            if(coinsAfter != coinsBefore + 2){
                printf("The number of coins is not correct\n");
            }
        }
        // choice 2 was selected
        else{
            // function call for barron card effect
            minionCardEffect(state, currentPlayer, handPos, choice1, choice2);
            
            // loop for 4 players
            for(j=0; j<5; j++){
                // if hands count are not correct
                if(handsAfter[j] != 4){ 
                    printf("The number of hands count are not correct\n");
                }
            }
        }
    }
}
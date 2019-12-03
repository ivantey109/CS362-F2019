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
    int card[1] = {mine}; 
    int numOfCoins = 0;
    int handsBefore, handsAfter = 0;
    int coinsBefore, coinsAfter = 0;
    int discardCountBefore, discardCountAfter = 0;
    int supplyCountBefore, supplyCountAfter = state->supplyCount[estate];
    int p = 0;//Iterator for hand!
    int i;
    int handPos = 0;

    for(i=0; i<100; i++){ // the number of tests to run

        // initialize the game status
        initializeGame(numPlayers, card, seed, &state);

        // decraling the variable for the Baron card test
        int choice1, choice2, choice3, currentPlayer, card_not_discarded, coin_bonus;
        choice1 = rand() % 1 + 2; // either estate or not
        choice2 = rand() % 1 + 2; // the card player choose to buy
        choice3 = rand() % 1 + 2; // not being used for mine and tribute but required to call cardEffect()
        currentPlayer = rand() % 1 + 4; // ranges between 1 to 4 for the player
        card_not_discarded = rand() % 1 + 2; // either estate or not
        handPos = rand() % 1 + 4; // hand position
        int p = 1;

        
        // store the number of the coins before conducting the function
        coinsBefore = state->coins;

        // we need to check whether the player hands are discarded or not after play mine or tribute card effect
        handsBefore = state->hand[currentPlayer][p]; // store the current players hands before function call
        discardCountBefore = state->discardCount[currentPlayer]; // store discard count before function call

        for(i=0; i<100; i++){ // the number of tests to run, to cover many possible situations
            // initialize the game status
            initializeGame(numPlayers, card, seed, &state);

            // function call for mine, tribute card effect
            cardEffect(card, choice1, choice2, choice3, state, handPos, coin_bonus);

            // retrieve the number of hands, discard count after function call
            handsAfter = state->hand[currentPlayer][p];
            discardCountAfter = state->discardCount[currentPlayer];

            // if the players card has correctly discarded
            // check the number of hands after mine card effect
            if(handsAfter == handsBefore - 1){
                printf("Test about mine effect has passed!");
            }
            else{
                printf("Test about mine effect has failed!");
            }

            if(discardCountAfter == discardCountBefore){
                printf("Players discard pile count has not incremented!");
            }
            else{
                printf("Something wrong with players discard count pile!");
            }
        }
    }
}
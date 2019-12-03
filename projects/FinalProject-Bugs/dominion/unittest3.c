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
    int card[1] = {remodel}; 
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
        int cost1, cost2 = 0;

        for(i=0; i<100; i++){ // the number of tests to run, to cover many possible situations
            // initialize the game status
            initializeGame(numPlayers, card, seed, &state);

            // function call for mine, tribute card effect
            cardEffect(card, choice1, choice2, choice3, state, handPos, coin_bonus);

            cost1 = getCost(state->hand[currentPlayer][choice1]);
            cost2 = getCost(choice2);

            // retrieve the cost which was used in a function call
            printf("The current cost of card1 is: %d", cost1);
            printf("The current cost of card2 is: %d", cost2);

            if(cost2 == cost1 + 2){
                printf("This should return the error in the mine case effect!");
                exit(0);
            }
            else{
                printf("Reaching here means that there should not be any error in this case!");
            }
        }
    }
}
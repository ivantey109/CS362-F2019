#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"

// Unit Test function for Tribute card effect
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
    int supplyCountBefore, supplyCountAfter = 0;
    int p = 0;//Iterator for hand!
    int i;
    int handPos = 0;
    int tributeRevealedCards[];

    for(i=0; i<1000; i++){ // the number of tests to run

        // initialize the game status
        initializeGame(numPlayers, card, seed, &state);

        // decraling the variable for the Baron card test
        int choice1, choice2, currentPlayer, card_not_discarded;
        choice1 = rand() % 1 + 2; 
        choice2 = rand() % 1 + 2; 
        currentPlayer = 4; // ranges between 1 to 4 for the player
        card_not_discarded = rand() % 1 + 2; // either estate or not
        int nextPlayer = 0;
        int handPos = 0;
        int deckCountBefore, deckCountAfter = 0;

        // store the number of the coins before conducting the function
        coinsBefore = state->coins;
        handsBefore = state->hand[currentPlayer][p];
        discardCountBefore = state->discardCount[currentPlayer];
        supplyCountBefore = state->supplyCount[state->hand[currentPlayer][choice1]];

            // function call for barron card effect
            //TributeCardEffect(state, nextPlayer, currentPlayer, tributeRevealedCards[], handPos);

            // checking the number of coins after Tribute has played
            if(card_discarded == actionsCard){
                deckCountBefore = state->deckCount[nextPlayer]; 

                // function call
                TributeCardEffect(state, nextPlayer, currentPlayer, tributeRevealedCards[], handPos);
                deckCountAfter = state->[nextPlayer][deckCount] -= 2;
                if(deckCountAfter != deckCountBefore + 2){
                    printf("The number of deck count is not correct\n");
                }
            }

            // if the card next player revealed is treasure cards
            else if(card_discarded == treasuresCard){
                deckCountBefore = state->deckCount[nextPlayer]; 

                // function call
                TributeCardEffect(state, nextPlayer, currentPlayer, tributeRevealedCards[], handPos);
                deckCountAfter = state->[nextPlayer][deckCount] -= 2;
                if(deckCountAfter != deckCountBefore + 2){
                    printf("The number of deck count is not correct\n");
                }
            }

            // in case of the victories cards
            else if(card_discarded == victoriesCard){
                deckCountBefore = state->deckCount[nextPlayer]; 

                // function call
                TributeCardEffect(state, nextPlayer, currentPlayer, tributeRevealedCards[], handPos);
                deckCountAfter = state->[nextPlayer][deckCount] -= 2;
                if(deckCountAfter != deckCountBefore + 2){
                    printf("The number of deck count is not correct\n");
                }
            }
            

            
    }
}
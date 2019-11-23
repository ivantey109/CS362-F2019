#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"

// Unit Test function for Mine card effect
int main(){
    srand((unsigned)time(NULL));// variable for random num generator
    struct gameState* state;
    int numPlayers = 4; // the number of player
    int seed = 100;
    int card[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room}; 
    int numOfCoins = 0;
    int currentPlayer = 1;
    int choice1 = 1;
    int choice2 = 1;
    int handsBefore, handsAfter = 0;

    int currentPlayerHands = 1; // cost to simulate the copper
    int targetToTrash = 1;

    handsBefore = state->hand[currentPlayer][choice1];
    mineDiscardTrashedCard(state, currentPlayer, choice1);
    if(handsAfter != handsBefore + 1){
        printf("Invalid number of the player hands");
    }

    // checking the players hands cost
    assert((getCost(currentPlayerHands) + 3) < getCost(choice2));    
}
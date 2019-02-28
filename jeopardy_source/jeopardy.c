/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4 

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
// void show_results(struct player *players, int num_players);

int game_state;




/*
void mystrcpy(char *first, char *second) {
	int smallest = strlen(first);
	if (strlen(second) < smallest)
		smallest = strlen(second);
	int i;
	for (i=0; i < smallest; i++) first[i] = second[i];
	first[i] = 0;
}
*/


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    struct player players[NUM_PLAYERS];


    char *name;
    name = (char *)calloc(BUFFER_LEN, sizeof(char));
    // EXAMPLE: player 1 is named Fred
	// players[0].name = "Fred";
    for(int i = 0; i < NUM_PLAYERS; i++){
        printf("Enter player %d name: ", i+1);
        scanf("%s", name);
        // printf("%s", name);
        strcpy(players[i].name, name);
        players[i].score = 0;
        // printf("Player: %s ,Score: %d \n", players[i].name, players[i].score);
    }
    free(name);
    // Buffer for user input
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    
    // initialize each of the players in the array

    // Perform an infinite loop getting command input from users until game ends
    game_state = 1;
    int questions_answered = 0;
    char *current_player, *current_category;
    int value = 0;
    current_player = calloc(BUFFER_LEN, sizeof(char));
    current_category = calloc(BUFFER_LEN, sizeof(char));
    while (game_state)
    {
        // Enter users name to answer question loop unitl valid name
        while(!player_exists(players, NUM_PLAYERS, current_player)){
            printf("Enter player's name to answer question: ");
            scanf("%s", current_player);
        }
        printf("Current Player: %s\n",current_player);


        // Choose category 
        while(!already_answered(current_category, value)){
            printf("Enter Category and value: ");
            scanf("%s %d", current_category, &value);
        }
        printf("Question: Category: %s, Value: %d\n", current_category, value);
        // EXAMPLE: This line gets a line of input from the user
        fgets(buffer, BUFFER_LEN, stdin);



        printf("[before]%s[after]", buffer);

		if (strcmp(buffer, "hello") == 0) printf(":)\n");
		if (strcmp(buffer, "world\n") == 0) printf(":)\n");

        // Call functions from the questions and players source files

        // Execute the game until all questions are answered
        if(questions_answered == NUM_QUESTIONS){
            break;
        }else{
            free(current_category);
            free(current_category);
        }
        // Display the final results and exit
    }

    return EXIT_SUCCESS;
}

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
#define NUM_TOKENS 20
#define BUF_LENGTH 256

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char tokens[NUM_TOKENS][BUF_LENGTH]);


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


int main()
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    struct player players[NUM_PLAYERS];
    char tokens[NUM_TOKENS][BUF_LENGTH] = {"0", "0", "0"};

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
    

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    
    // initialize each of the players in the array

    // Perform an infinite loop getting command input from users until game ends
    game_state = 1;
    int questions_answered = 0;
    char *current_player, *current_category, *current_answer, *winner;
    int value = 0, topScore = 0;
    current_player = calloc(BUFFER_LEN, sizeof(char));
    current_category = calloc(BUFFER_LEN, sizeof(char));
    current_answer = calloc(BUFFER_LEN, sizeof(char));
    while (game_state)
    {
        display_categories();
        // Enter users name to answer question loop unitl valid name
        do{
            printf("Enter player's name to answer question: ");
            scanf("%s", current_player);
        }while(!player_exists(players, NUM_PLAYERS, current_player));
        
        printf("Current Player: %s\n",current_player);


        // Choose category 
        do{
            printf("Enter Category and value: ");
            scanf("%s %d", current_category, &value);
            if (already_answered(current_category, value)){
                printf("Sorry, that question has already been attempted\n");
            }
            getchar();
        }while(already_answered(current_category, value));

        printf("Question: Category: %s, Value: %d\n", current_category, value);
        // EXAMPLE: This line gets a line of input from the user

        // Print question
        display_question(current_category, value);

        //Get user's answer
        printf("Your answer: ");
        fgets(current_answer, BUF_LENGTH, stdin);
        current_answer[strcspn(current_answer, "\n")] = 0;
        questions_answered++;

        //Tokenizes current_answer so we can use tokens[2] in valid_answer
        tokenize(current_answer, tokens);

        if (!strcmp(tokens[0],"what") || !strcmp(tokens[0],"who") && !strcmp(tokens[1],"is")){
            
            if (valid_answer(current_category, value, tokens[2])){
                update_score(players, NUM_PLAYERS, current_player, value);
            }
            printf("Current Scores: \n");
            for(int i = 0; i < NUM_PLAYERS; i++){
                printf("%s - %d points \n", players[i].name, players[i].score);
            }
        } else {
            printf("Sorry, incorrect. No points\n");
        }
            

        // Call functions from the questions and players source files

        // Execute the game until all questions are answered
        if (questions_answered == 12) {
            printf("And that's game!\n\n");

            // Display the final results and exit
            printf("Current Scores: \n");
            
            for(int i = 0; i < NUM_PLAYERS; i++){
                if (players[i].score > topScore) {
                    topScore = players[i].score;
                    winner = players[i].name;
                }
                printf("%s - %d points \n", players[i].name, players[i].score);
            }
            printf("The winner is: %s!\n", winner);

            printf("Press any key and enter to end game");
            getchar();
            game_state = 0;

        }
    }
    free(current_player);
    free(current_category);

    return EXIT_SUCCESS;
}
// Perform string tokenization
void tokenize(char *input, char tokens[NUM_TOKENS][BUF_LENGTH]){
    int tokenNum = 0;
    int tokenIndex = 0;
    for(int i = 0; i < strlen(input); i++){
        if (input[i] != ' '){
            tokens[tokenNum][tokenIndex] = input[i];
            tokenIndex++;
        }
        else {
            tokens[tokenNum][tokenIndex] = '\0';
            tokenNum++;
            tokenIndex = 0;
        }
    }
}
    




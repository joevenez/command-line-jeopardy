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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    printf("Welcome to the game\n");
    display_categories();
    // Make Questions 

    // Programming Question
    // Q1
    question q1;
    q1.answered = false;
    q1.value = 10;
    strcpy(q1.category ,"programming");
    strcpy(q1.question , "What is the name of this programming language?");
    strcpy(q1.answer, "C");
    questions[0] = q1;
    // Q2
    question q2;
    q2.answered = false;
    q2.value = 20;
    strcpy(q2.category ,"programming");
    strcpy(q2.question , "What is the first name of the man who developed C?");
    strcpy(q2.answer, "Dennis");
    questions[1] = q2;
    // Q3
    question q3;
    q3.answered = false;
    q3.value = 30;
    strcpy(q3.category ,"programming");
    strcpy(q3.question , "What is the last name of the man known as the father of java?");
    strcpy(q3.answer, "Gosling");
    questions[2] = q3;
    // Q4
    question q4;
    q4.answered = false;
    q4.value = 40;
    strcpy(q4.category ,"programming");
    strcpy(q4.question , "What is the name of this programming language?");
    strcpy(q4.answer, "C");
    questions[3] = q4;
    
    // Algorithm Question
    // Database Question
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    for(int i = 0; i < NUM_CATEGORIES; i++){
        printf("Question Category: %s, Question Dollar Values:", categories[i]);
        for(int j = 0; j < NUM_QUESTIONS / NUM_CATEGORIES; j++){
            printf(" %d" , (j * 10) + 10);
        } 
        printf("\n");
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    for(int i = 0; i < NUM_QUESTIONS; i++){
        if(strcmp(category, questions[i].category) == 0 && !questions[i].answered ){
            return true;
        }
    }
    return false;
}

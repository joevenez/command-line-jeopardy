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
    // Make Questions 

    // Programming Question
    // Q1
    question q1;
    q1.answered = false;
    q1.value = 10;
    strcpy(q1.category ,"programming");
    strcpy(q1.question , "What is the name of the programming language used to make this game?");
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
    // Q5
    question q5;
    q5.answered = false;
    q5.value = 10;
    strcpy(q5.category ,"algorithms");
    strcpy(q5.question , "Which data structure uses the methodology of First in First out?");
    strcpy(q5.answer, "stack");
    questions[4] = q5;
    // Q6
    question q6;
    q6.answered = false;
    q6.value = 20;
    strcpy(q6.category ,"algorithms");
    strcpy(q6.question , "Which data structure uses the methodology of Last in First out?");
    strcpy(q6.answer, "queue");
    questions[5] = q6;
    // Q7
    question q7;
    q7.answered = false;
    q7.value = 30;
    strcpy(q7.category ,"algorithms");
    strcpy(q7.question , "What kind of time complexity is Binary Search Tree?");
    strcpy(q7.answer, "logarithmic");
    questions[6] = q7;
    // Q8
    question q8;
    q8.answered = false;
    q8.value = 40;
    strcpy(q8.category ,"algorithms");
    strcpy(q8.question , "Acronym for Breadth First Search?");
    strcpy(q8.answer, "BFS");
    questions[7] = q8;
    // Database Question
    // Q9
    question q9;
    q9.answered = false;
    q9.value = 10;
    strcpy(q9.category ,"databases");
    strcpy(q9.question , "Acronym for Structure Query Language?");
    strcpy(q9.answer, "SQL");
    questions[8] = q9;
    // Q10
    question q10;
    q10.answered = false;
    q10.value = 20;
    strcpy(q10.category ,"databases");
    strcpy(q10.question , "Keyword used to add constraints on a query?");
    strcpy(q10.answer, "WHERE");
    questions[9] = q10;
     // Q11
    question q11;
    q11.answered = false;
    q11.value = 30;
    strcpy(q11.category ,"databases");
    strcpy(q11.question , "Symbol used to denote all?");
    strcpy(q11.answer, "*");
    questions[10] = q11;
     // Q12
    question q12;
    q12.answered = false;
    q12.value = 40;
    strcpy(q12.category ,"databases");
    strcpy(q12.question , "Keyword used to select items from a specific table?");
    strcpy(q12.answer, "FROM");
    questions[11] = q12;
    
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    for(int i = 0; i < NUM_CATEGORIES; i++){
        printf("Question Category: %s, Question Dollar Values:", categories[i]);
        for(int j = 0; j < NUM_QUESTIONS; j++){
            if (!strcmp(questions[j].category,categories[i]) && !questions[j].answered){
                 printf(" %d" , questions[j].value);
            }
           
        } 
        printf("\n");
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{

    for(int i = 0; i < NUM_QUESTIONS; i++){
        if(strcmp(questions[i].category,category) == 0 && value == questions[i].value){
            printf("%s\n", questions[i].question);
            questions[i].answered = true;
            break;
        }
    }
    
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    for(int i = 0; i < NUM_QUESTIONS; i++){
        if(strcmp(questions[i].category,category) == 0 && value == questions[i].value && strcmp(questions[i].answer, answer) == 0){
            printf("Your answer of \"%s\" is correct! %d points awarded!\n", answer, questions[i].value);
            return true;
        }
    }
    printf("Sorry, incorrect. No points. \n");
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    for(int i = 0; i < NUM_QUESTIONS; i++){
        if(strcmp(category, questions[i].category) == 0 && (value == questions[i].value) && questions[i].answered){
            return true;
        }
    }
    return false;
}

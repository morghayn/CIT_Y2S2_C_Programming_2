#ifndef QUIZ_H
#define QUIZ_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h> // for debug
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "linked_list.h"
#include "utility.h"

typedef enum
{
	F, T
} boolean;

typedef struct interchange
{
	char* question;
	char* answer;
	boolean correct;
} interchange;

interchange* create_interchange(char* question, char* answer);
boolean split_question(char line[], char* array[]);
node* build_quiz(const char* filepath);

interchange* get_interchange(int current_question, node* head);
void shuffle_question_queue(int* question_queue, int question_quantity);

char* generate_clue(int difficulty, char* current_answer);
boolean check_guess(interchange* current_interchange, char* guess);

void print_round_summary(node* head);

void store_results(char file_path[], int incorrect_answers, int question_quantity, int difficulty);
void release_quiz(node* head);

#endif
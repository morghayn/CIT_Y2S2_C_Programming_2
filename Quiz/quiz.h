#ifndef QUIZ_H
#define QUIZ_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h> // for debug
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#include "utility.h"

typedef struct interchange
{
	char* question;
	char* answer;
} interchange;

typedef enum
{
	F, T
} boolean;

interchange* create_interchange(char* question, char* answer);
boolean split_question(char line[], char* array[]);
node* build_quiz(const char* filepath);

interchange* get_interchange(int current_question, node* head);
void shuffle_question_queue(int* question_queue, int question_quantity);

char* generate_clue(int difficulty, char* current_answer);
void print_score();

void store_results();
void release_quiz(node* head);
void debug_print_quiz(node* head);

#endif
#ifndef QUIZ_H
#define QUIZ_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h> // for debug
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

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

char* generate_clue(int difficulty);
void print_score();

void release_quiz(node* head);
void debug_print_quiz(node* head);

#endif
#ifndef MAIN_H
#define MAIN_H
#define _CRT_SECURE_NO_WARNINGS

#include "quiz.h"
#include <stdio.h>
#include <stdlib.h> // for system("pause")
#include <string.h>
#include <assert.h>

typedef enum 
{
    F, T
}
boolean;

void random();
void read_file(const char* filepath);
void print_question_quantity();
void generate_clue();
void print_score();
void store_results();
boolean split_question(char line[], char* array[]);
void test();

#endif
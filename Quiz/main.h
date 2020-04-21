#ifndef MAIN_H
#define MAIN_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // for system("pause")
#include <string.h>

void random();
void read_file(const char* filepath);
void print_question_quantity();
void generate_clue();
void print_score();
void store_results();

#endif
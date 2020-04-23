#ifndef MAIN_H
#define MAIN_H
#define _CRT_SECURE_NO_WARNINGS

#include "quiz.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h> // for system("pause")
#include <string.h>
#include <assert.h>

void shuffle_array();
void random(int lower, int upper, int count); // To go in a utility class
void store_results();

#endif
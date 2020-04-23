#ifndef UTILITY_H
#define UTILITY_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h> // for debug

// Fisher–Yates int shuffle algorithm
void swap(int* a, int* b);
void shuffle_array(int arr[], int n);

// Fisher–Yates char shuffle algorithm
void swap_char_pointer(char* a, char* b);
void shuffle_char_array(char arr[], int n);

int random(int lower, int upper);

#endif
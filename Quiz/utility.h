#ifndef UTILITY_H
#define UTILITY_H

#include <stdlib.h>
#include <time.h>

// Fisher–Yates shuffle algorithm
void swap(int* a, int* b);
void shuffle_array(int arr[], int n);

int random(int lower, int upper);

#endif
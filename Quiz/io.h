#ifndef IO_H
#define IO_H

#include <stdlib.h>
#include <stdio.h>

void clear_buffer();
int input_number(int lower, int upper, char* message);
char* input_word(char* message);

#endif
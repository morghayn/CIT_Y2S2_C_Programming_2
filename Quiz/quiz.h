#ifndef QUIZ_H
#define QUIZ_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h> // for debug
#include <stdio.h>
#include <string.h>
//#include "linked_list.h"

typedef struct interchange
{
	char* question;
	char* answer;
} interchange;

void create_interchange();

/*
int length(struct node* head);

//void print_nodes(struct node* head);
void release_nodes(struct node* head);
*/

#endif
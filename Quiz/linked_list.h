#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // TODO remove after debug
#include <stdlib.h>

typedef struct node
{
	struct data* data;
	struct node* next;
} node;

node* create_node(struct data* data);
node* insert_front(node* head, struct data* data);
//node* get_next();

int length(node* head);

//void print_nodes(struct node* head);
void release_nodes(node* head);

#endif
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // TODO remove after debug
#include <stdlib.h>

typedef struct node
{
	struct node* next;
	void* data;
} node;

node* create_node(void* data);
node* insert_front(node* head, void* data);
node* get_node(node* head, int position);

int length(node* head);

#endif
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // TODO remove after debug
#include <stdlib.h>

typedef struct node
{
	void* data;
	struct node* next;
} node;

node* create_node(void* data);
node* insert_front(node* head, void* data);

int length(node* head);

void print_linked_list(node* head);
void release_linked_list(node* head);

#endif
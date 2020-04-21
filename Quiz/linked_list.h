#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

struct node
{
	char* string;
	struct node* head;
};

struct node* insert_front(struct node* head, char* str);
struct node* create_node(char* str);

void print_nodes(struct node* head);
void release_nodes(struct node* head);

#endif
#include "linked_list.h"

struct node* create_node(char* string)
{
	struct node* temp;

	temp = (struct node*) malloc(sizeof(struct node));
	temp->string = string;
	temp->head = NULL;

	return temp;
}

struct node* insert_front(struct node* head, char* string)
{
	char* new_str = (char*)malloc((strlen(string) + 1) * sizeof(char));
	strcpy(new_str, string);

	struct node* temp = create_node(new_str);
	temp->head = head;

	return temp;
}

void print_nodes(struct node* head)
{
	while (head != NULL)
	{
		printf(head->string);
		head = head->head;
	}
}

int length(struct node* head)
{
	int length = 0;

	while (head != NULL)
	{
		length++;
	}

	return length;
}

void release_nodes(struct node* head)
{
	struct node* temp;

	while (head != NULL)
	{
		temp = head;
		head = head->head;
		free(temp->string);
		free(temp);
	}
}
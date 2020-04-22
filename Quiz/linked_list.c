#include "linked_list.h"

node* create_node(struct data* data)
{
	struct node* temp;

	temp = (node*) malloc(sizeof(node));
	temp->next = NULL;
	temp->data = data;

	return temp;
}

node* insert_front(node* head, struct data* data)
{
	struct node* temp = create_node(data);
	temp->next = head;

	return temp;
}

int length(node* head)
{
	int length = 0;

	while (head != NULL)
	{
		length++;
		head = head->next;
	}

	return length;
}

// TODO is this needed?
void release_nodes(node* head)
{
	struct node* temp;
	printf("release attempt\n\n"); // TODO remove debug

	while (head != NULL)
	{
		printf("release node\n"); // TODO remove debug
		temp = head;
		head = head->next;
		free(temp->data);
		free(temp);
	}
}

/*
void print_nodes(struct node* head)
{
	while (head != NULL)
	{
		printf(head->question);
		head = head->next;
	}
}
*/
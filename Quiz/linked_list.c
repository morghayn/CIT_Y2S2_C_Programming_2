#include "linked_list.h"

struct node* create_node(char* str)
{
	struct node* temp;

	temp = (struct node*) malloc(sizeof(struct node));
	temp->str = str;
	temp->next = NULL;

	return temp;
}

struct node* insert_front(struct node* head, char* str)
{
	char* new_str = (char*)malloc((strlen(str) + 1) * sizeof(char));
	strcpy(new_str, str);

	struct node* temp = create_node(new_str);
	temp->next = head;

	return temp;
}

void print_nodes(struct node* head)
{
	while (head != NULL)
	{
		printf(head->str);
		head = head->next;
	}
}

void release_nodes(struct node* head)
{
	struct node* temp;
	//printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}

	//printf("\n> all nodes have been released.\n");
	//printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
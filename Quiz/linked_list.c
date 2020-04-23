#include "linked_list.h"

node* create_node(void* data)
{
	struct node* temp = (node*) malloc(sizeof(node));
	// printf("> Linked-List: %p\n", temp); /* uncomment for debub output */
	temp->next = NULL;
	temp->data = data;
	return temp;
}

node* insert_front(node* head, void* data)
{
	struct node* temp = create_node(data);
	temp->next = head;
	return temp;
}

node* get_node(node* head, int position)
{
	while (position != 0 && head != NULL)
	{
		position--;
		head = head->next;
	}

	return head;
}

/*

TODO maybe add a delete node at n

*/

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

void print_linked_list(node* head)
{
	while (head != NULL)
	{
		printf("%p->", head);
		head = head->next;
	}

	printf("NULL");
}

void release_linked_list(node* head)
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
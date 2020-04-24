#include "linked_list.h"

node* create_node(void* data)
{
	struct node* temp = (node*) malloc(sizeof(node));
	// printf("> Linked-List: %p\n", temp); /* uncomment for debub output */
	if (!temp)
	{
		return NULL;
	}
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
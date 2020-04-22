#include "main.h"

int main(void)
{	
	printf("> 1. Start\n> 3. Scoreboard\n> 2. Quit\n> Input option:\n");
	//char* buffer;
	//buffer = _getcwd(NULL, 0); // get the current directory
	//buffer = (char*)realloc(buffer, 25);
	//strcat(buffer, "test");
	//printf(buffer);

	//char* clue = malloc(3 * sizeof(char));
	//clue[2] = '\0';
	//printf("\nsize of clue:%d\n", strlen(clue));
		
	node* head = NULL;
	head = build_quiz("test");

	debug_print_quiz(head);
	printf("\n\n\n");
	release_quiz(head);
	printf("\n");
	system("pause");
	return 0;
}

void random()
{
	 ///The questions are asked in random order.
}

// at the end store the results in a file quiz_history.txt by appending to the file one line containing:
void store_results()
{
	// name of the quiz file
	// number of questions answered correctly
	// total number of questions
	// difficulty level
}

void test()
{
	/*
	node* head = NULL;
	printf("> Will have to free the following...\n");

	char question[] = "Hello World?";
	char answer[] = "No thanks";
	interchange* test = create_interchange(question, answer);
	head = insert_front(head, test);

	char question2[] = "Hello World?";
	char answer2[] = "No thanks";
	interchange* test2 = create_interchange(question2, answer2);
	head = insert_front(head, test2);

	char question3[] = "Hello World?";
	char answer3[] = "No thanks";
	interchange* test3 = create_interchange(question3, answer3);
	head = insert_front(head, test3);

	char question4[] = "Hello World?";
	char answer4[] = "No thanks";
	interchange* test4 = create_interchange(question4, answer4);
	head = insert_front(head, test4);

	printf("List length should be four: %d\n", length(head));
	print_linked_list(head);


	release_quiz(head);
	//release_nodes(head);
	*/
}
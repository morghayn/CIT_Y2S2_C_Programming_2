#include "main.h"

int main(void)
{	
	printf("> 1. Start\n> 3. Scoreboard\n> 2. Quit\n> Input option:\n");
		
	node* head = NULL;
	head = build_quiz("test");
	//interchange* interchange = head->data;
	random(0, 5, 100);


	debug_print_quiz(head);
	printf("\n\n\n");
	release_quiz(head);
	printf("\n");
	system("pause");
	return 0;
}

void random(int lower, int upper, int count)
{
	for (int i = 0; i < count; i++) 
	{
		srand(rand());
		int num = (rand() % (upper - lower + 1)) + lower;
		printf("%d, ", num);
	}
}

// at the end store the results in a file quiz_history.txt by appending to the file one line containing:
void store_results()
{
	// name of the quiz file
	// number of questions answered correctly
	// total number of questions
	// difficulty level
}

/*
char* buffer;
buffer = _getcwd(NULL, 0); // get the current directory
buffer = (char*)realloc(buffer, 25);
strcat(buffer, "test");
*/
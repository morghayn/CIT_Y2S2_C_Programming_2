#include "main.h"

int main(void)
{	
	int difficulty;
	/*
	at start 
		– load the questions and answers from the ﬁle 
		– print out the number of questions in the quiz 
	start asking questions 
		– for each question, display a clue (if available, see below); the user has one attempt only, and the program is case insensitive (accepts both lower and upper case answers) 
		– after each question display the number of questions asked and the number of correctly answered questions so far. Example: Score: 5/7
	at the end store the results in a ﬁle quiz_history.txt by appending to the ﬁle one line containing: 
		– name of the quiz ﬁle 
		– number of questions answered correctly 
		– total number of questions 
		– diﬃculty level
	*/

	difficulty = input_number(1, 6, "> Choose a difficulty [1-6]: ");
	printf("> Difficulty '%d' chosen\n", difficulty);


	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("size of n:%d\n", n);
	shuffle_array(arr, n);

	/*
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
	*/
	return 0;
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
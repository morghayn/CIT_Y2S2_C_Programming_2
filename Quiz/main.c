#include "main.h"

int main(void)
{
	int menu_selection;
	char* file_path;
	node* head = NULL;
	int question_quantity;
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

	// Menu Selection
	printf("> 1. Start\n> 2. Scoreboard\n> 3. Quit\n");
	menu_selection = input_number(1, 3, "> Make menu selection [1-3]: ");

	// WIP get file path and concate to message below
	//char* buffer(getcwd(NULL, 0));
	//char* hello = "yo dawg";
	//strcat(hello, buffer);
	//printf("%s\n\n", buffer);

	file_path = input_word("> Input file location:\n>\\");
	printf("\nfile_path : %p\n", file_path);
	head = build_quiz(file_path);
	free(file_path);

	// Return if file path not found here

	// Counting quantity of questions
	question_quantity = length(head);
	printf("> There are exactly '%d' questions in this quiz.\n", question_quantity);

	// Setting difficulty
	difficulty = input_number(1, 6, "> Choose a difficulty [1-6]: ");
	printf("> Difficulty '%d' chosen\n", difficulty);

	int* queue;
	queue = (int*)malloc(question_quantity * sizeof(int*));
	for (int i = 0; i < question_quantity; i++)
	{
		queue[i] = i;
	}
	shuffle_array(queue, question_quantity);
	print_array(queue, question_quantity);
	ask_questions(queue, question_quantity, head);

	/*
	node* head = NULL;
	head = build_quiz("test");
	//interchange* interchange = head->data;
	random(0, 5, 100);


	debug_print_quiz(head);
	release_quiz(head);
	system("pause");
	*/
	return 0;
}

void print_array(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%d\n", n, arr[i]);
	}
}

void ask_questions(int arr[], int n, node* head)
{
	node* temp;
	interchange* interchange;
	char* current_question;

	for (int i = 0; i < n; i++)
	{
		temp = get_node(head, arr[i]);
		interchange = temp->data;
		current_question = interchange->question;
		printf("%s?\n", current_question);
	}
}

/*
char* buffer;
buffer = _getcwd(NULL, 0); // get the current directory
buffer = (char*)realloc(buffer, 25);
strcat(buffer, "test");
*/
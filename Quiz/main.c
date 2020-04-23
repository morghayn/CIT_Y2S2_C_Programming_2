#include "main.h"

int main(void)
{
	int menu_selection;
	char* file_path;
	node* head = NULL;
	int question_quantity;
	int* question_queue;
	int difficulty;
	interchange* current_interchange = NULL;
	char* current_clue;

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

	// Getting file path and then freeing file path once quiz has been built
	file_path = input_word("> Input file location:\n> \\");
	head = build_quiz(file_path);
	free(file_path);

	// Return if file path not found here

	// Counting quantity of questions
	question_quantity = length(head);
	printf("> There are exactly '%d' questions in this quiz.\n", question_quantity);

	// Initizializing and shuffling question queue
	question_queue = (int*)malloc(question_quantity * sizeof(int*)); // Must free when queue is finished
	shuffle_question_queue(question_queue, question_quantity);

	// Setting difficulty
	difficulty = input_number(1, 6, "> Choose a difficulty [1-6]: ");
	printf("> Difficulty '%d' chosen\n", difficulty);

	for (int i = 0; i < question_quantity; i++)
	{
		current_interchange = get_interchange(question_queue[i], head);
		current_clue = generate_clue(difficulty, current_interchange->answer);
		printf("%s? %s\n", current_interchange->question, current_clue);
		free(current_clue);
	}

	release_quiz(head);
	/*
	debug_print_quiz(head);
	release_quiz(head);
	system("pause");
	*/
	return 0;
}

/*
char* buffer;
buffer = _getcwd(NULL, 0); // get the current directory
buffer = (char*)realloc(buffer, 25);
strcat(buffer, "test");
*/
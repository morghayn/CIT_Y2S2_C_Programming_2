#include "main.h"

/*
implement this at some stage
char* buffer;
buffer = _getcwd(NULL, 0); // get the current directory
buffer = (char*)realloc(buffer, 25);
strcat(buffer, "test");
*/

int main(void)
{
	char border_top[] = "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	char border_bottom[] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	int menu_selection;
	boolean quit = F;

	while (quit == F)
	{
		printf("\n\n> 1. Start\n> 2. Scoreboard\n> 3. Quit\n");
		menu_selection = input_number(1, 3, "> Make menu selection [1-3]: ");

		switch (menu_selection)
		{
		case 1:
			printf(border_top);
			quiz();
			printf(border_bottom);
			break;
		case 2:
			printf(border_top);
			print_scoreboard();
			printf(border_bottom);
			break;
		case 3:
			quit = T;
			break;
		default:
			printf("Something appears to have gone gravely wrong. o,,o");
			break;
		}
	}

	system("pause");

	return 0;
}

void quiz()
{
	char* file_path;
	node* head = NULL;
	int question_quantity;
	int* question_queue;
	int difficulty;
	interchange* current_interchange = NULL;
	char* current_clue;
	int incorrect_answers = 0;

	// Getting file path and then freeing file path once quiz has been built
	file_path = input_word("> Input file location:\n> \\");
	head = build_quiz(file_path);

	if (head == NULL)
	{
		free(file_path);
		return;
	}

	// Counting quantity of questions
	question_quantity = length(head);
	printf("> There are exactly '%d' questions in this quiz.\n", question_quantity);

	// Initizializing and shuffling question queue
	question_queue = (int*)malloc(question_quantity * sizeof(int*)); // Must free when queue is finished
	shuffle_question_queue(question_queue, question_quantity);

	// Setting difficulty
	difficulty = input_number(1, 6, "> Choose a difficulty [1-6]: ");
	printf("> Difficulty '%d' chosen\n\n\n", difficulty);

	// Each interchange is an iteration of this loop
	for (int i = 0; i < question_quantity; i++)
	{
		current_interchange = get_interchange(question_queue[i], head);
		current_clue = generate_clue(difficulty, current_interchange->answer);

		printf("> %s? %s\n", current_interchange->question, current_clue);
		incorrect_answers += (check_guess(current_interchange, input_word("\n> Input answer: ")) == 1 ? 0 : 1);
		printf("> Questions asked: %d\n> Incorrect answers: %d\n\n", i + 1, incorrect_answers);

		free(current_clue);
	}

	if (input_number(0, 1, "> Would you like to see a round summary [1 = Yeah; 0 = No]? ") == 1)
	{
		print_round_summary(head);
	}

	store_results(file_path, incorrect_answers, question_quantity, difficulty);
	release_quiz(head);
	free(file_path);
	free(question_queue);
}

void print_scoreboard()
{
	FILE* file;
	char c;
	file = fopen("quiz_history.txt", "r");

	if (file == NULL)
	{
		printf("\n> Scoreboard file not found. o,,o\n\n");
		return;
	}

	c = fgetc(file);
	printf("\n");

	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(file);
	}

	fclose(file);
}
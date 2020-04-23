#include "quiz.h"

interchange* create_interchange(char* question, char* answer)
{
	interchange* temp = (interchange*)malloc(sizeof(interchange));
	temp->question = _strdup(question);
	temp->answer = _strdup(answer);
	temp->correct = F;
	// printf("> Interchange: %p\t\t%p\t%p\n", temp, temp->question, temp->answer); /* uncomment for debub output */
	return temp;
}

boolean split_question(char line[], char* array[])
{
	char* token = strtok(line, "?");
	boolean is_valid = 0;

	for (int i = 0; token != NULL && i < 2; i++)
	{
		is_valid = i == 1 ? 1 : is_valid;

		array[i] = token;
		token = strtok(NULL, " \n");
	}

	return is_valid;
}

node* build_quiz(const char* filepath)
{
	node* head = NULL;
	FILE* file;

	fopen_s(&file, filepath, "r");

	if (file == NULL)
	{
		printf("\n> File does not exist @ \\%s. Returning to the main menu.\n\n", filepath);
	}
	else
	{
		char* q_and_a[2];
		const size_t line_size = 300;
		char* line = malloc(line_size);

		while (fgets(line, line_size, file) != NULL)
		{
			if (split_question(line, q_and_a) == 1)
			{
				head = insert_front(head, 
					create_interchange(q_and_a[0], q_and_a[1])
				);
			}
		}

		free(line);
		fclose(file);
	}

	return head;
}

void shuffle_question_queue(int* question_queue, int question_quantity)
{
	for (int i = 0; i < question_quantity; i++)
	{
		question_queue[i] = i;
	}
	shuffle_array(question_queue, question_quantity);
}

interchange* get_interchange(int current_question, node* head)
{
	return get_node(head, current_question)->data;
}

// start asking questions
char* generate_clue(int difficulty, char* current_answer)
{
	char* clue;
	int length = strlen(current_answer);
	char temp[] = "?";
	int i, j;

	switch (difficulty)
	{
		case 1:
			clue = _strdup(temp);
			break;

		case 2:
			clue = _strdup(current_answer);
			memset(clue, '-', length * sizeof(char));
			break;

		case 3:
			clue = generate_clue(2, current_answer);
			memcpy(clue, current_answer, 1);
			memcpy(clue + (length) - 1, current_answer + (length) - 1, 1);
			break;

		case 4:
			clue = generate_clue(2, current_answer);
			i = random(0, length - 1);

			do
			{
				j = random(0, length - 1);
			} while (i == j);

			memcpy(clue + i, current_answer + i, 1 * sizeof(char));
			memcpy(clue + j, current_answer + j, 1 * sizeof(char));
			break;

		case 5:
			clue = _strdup(current_answer);
			shuffle_char_array(clue, length);
			break;

		case 6:
			clue = generate_clue(random(1, 5), current_answer);
			break;

		default:
			printf("Something appears to have gone wrong. o,,o");
			clue = malloc(sizeof(char));
			clue = "\0";
			break;
	}

	return clue;
}

boolean check_guess(interchange* current_interchange, char* guess)
{
	int i;
	int x = 0;
	boolean is_correct = F;
	char* lowercase_guess = _strdup(guess);
	char* lowercase_answer = _strdup(current_interchange->answer);

	if (strlen(lowercase_answer) == strlen(lowercase_answer))
	{
		// -> swap out to utility.c "make_lowercase()" ?? maybe
		for (i = 0; lowercase_guess[i] != '\0'; i++)
		{
			lowercase_guess[i] = tolower(lowercase_guess[i]);
		}
		for (i = 0; lowercase_answer[i] != '\0'; i++)
		{
			lowercase_answer[i] = tolower(lowercase_answer[i]);
		}
		for (i = 0; lowercase_answer[i] != '\0'; i++)
		{
			if (lowercase_answer[i] != lowercase_guess[i])
			{
				x++;
			}
		}

		is_correct = x == 0 ? T : F;
	}
	else
	{
		is_correct = F;
	}

	current_interchange->correct = is_correct;
	free(lowercase_answer);
	free(lowercase_guess);

	return is_correct;
}

void print_round_summary(node* head)
{
	struct node* temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		interchange* interchange = temp->data;
		printf("\n> Question:\t%s? You were %s.\n> Answer:\t%s\n", interchange->question, (interchange->correct == F ? "Incorrect" : "Correct"), interchange->answer);
	}
}

void store_results()
{
	// name of the quiz file
	// number of questions answered correctly
	// total number of questions
	// difficulty level
}

void release_quiz(node* head)
{
	struct node* temp;
	// printf("\n\n\n> Freeing what needed to be freed....\n"); /* uncomment for debub output */
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		interchange* interchange = temp->data;
		// printf("> Linked-List: %p\n> Interchange: %p\t\t%p\t%p\n", temp, interchange, interchange->question, interchange->answer); /* uncomment for debub output */
		free(interchange->question);
		free(interchange->answer);
		free(interchange);
		free(temp);
	}
}
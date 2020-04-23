#include "quiz.h"

interchange* create_interchange(char* question, char* answer)
{
	interchange* temp = (interchange*)malloc(sizeof(interchange));
	temp->question = _strdup(question);
	temp->answer = _strdup(answer);
	printf("> Interchange: %p\t\t%p\t%p\n", temp, temp->question, temp->answer); // For debug
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
	interchange* interchange = NULL;
	node* head = NULL;
	FILE* file;

	fopen_s(&file, filepath, "r");

	if (file == NULL)
	{
		printf("\n> File does not exist @ %s.\n> Returning to the main menu.", filepath);
		// fclose(file); <-- this little guy will throw a kernel error if uncommented
		return head;
	}

	const size_t line_size = 300;
	char* line = malloc(line_size);

	while (fgets(line, line_size, file) != NULL)
	{
		char* q_and_a[2];	// Char pointer array for both the question and answer
		boolean is_valid;	// Prevents an access violation

		is_valid = split_question(line, q_and_a);
		if (is_valid == 1)
		{
			char* question = q_and_a[0];
			char* answer = q_and_a[1];
			interchange = create_interchange(question, answer);
			head = insert_front(head, interchange);
		}
	}

	free(line);
	fclose(file);
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
	node* temp;
	temp = get_node(head, current_question);
	return temp->data;
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

void print_score()
{
	// after each question display the number of questions asked and the number of correctly answered questions so far. Example: Score: 5/7 
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
	printf("\n\n\n> Freeing what needed to be freed....\n"); // For debug
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		interchange* interchange = temp->data;

		printf("> Linked-List: %p\n> Interchange: %p\t\t%p\t%p\n", temp, interchange, interchange->question, interchange->answer); // For debug

		free(interchange->question);
		free(interchange->answer);
		free(interchange);
		free(temp);
	}
}

void debug_print_quiz(node* head)
{
	struct node* temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		interchange* interchange = temp->data;
		printf("Question:\t%s\nAnswer:\t\t%s\n", interchange->question, interchange->answer);
	}
}
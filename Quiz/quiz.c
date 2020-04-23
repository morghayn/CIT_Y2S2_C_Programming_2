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
		token = strtok(NULL, " ");
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

// start asking questions
char* generate_clue(int difficulty)
{
	char* clue;

	switch (difficulty)
	{
	case 1:
		/*
		1. No clue is given and only a ‘?’ is shown.
		Example: What is the capital of France? ?
		*/
		clue = "?";
		break;
	case 2:
		/*
		2. A set of blank dashes seprated by spaces is displayed, one for every letter in the answer.
		Example: What is the capital of France? - - - -
		*/
		break;
	case 3:
		/*
		The ﬁrst and the last letters are shown.
		Example: What is the capital of France? P - - - S
		*/
		break;
	case 4:
		/*
		Two random letters from the answer are shown in their correct position.
		Example: What is the capital of France? P - R -
		*/
		break;
	case 5:
		/*
		All letters are shown but in random order.
		Example: What is the capital of France? R S I P A
		*/
		break;
	case 6:
		/*
		The type of clue is randomly selected from the 5 types listed above.
		*/
		// clue = generate_clue(random(1, 5))
		break;
	default:
		printf("Something appears to have gone wrong. o,,o");
		break;
	}
	// for each question, display a clue (if available, see below); the user has one attempt only, and the program is case insensitive (accepts both lower and upper case answers) 
	return "";
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
#include <stdio.h>
#include <queue.h>

int main(void)
{	
	// -> Start
	// Select quiz
	// Select  

	while (1 == 1)
	{
		printf("> 1. Start\n> 2. Quit\n> Input option: ");

		//printf("> Hello and welcome to the Quiz game\n");
		//printf("> Please enter a number between 1 and 6: \n");
		//printf("> Start?\n");
		system("pause");
	}

	return 0;
}

void random()
{
	 ///The questions are asked in random order.
}

// initiation
void load_question_file()
{
	// load questions from file
}

void print_question_quantity()
{
	// print out number of questions from file
}

// start asking questions
void generate_clue()
{
	int difficulty; // (temporary will be in header file)

	switch (difficulty)
	{
		case 1:
				/*
				1. No clue is given and only a ‘?’ is shown. 
				Example: What is the capital of France? ?
				*/
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
				break;
		default:
				printf("Something appears to have gone wrong. o,,o")
				break;
	}
	// for each question, display a clue (if available, see below); the user has one attempt only, and the program is case insensitive (accepts both lower and upper case answers) 
}

void print_score()
{
	// after each question display the number of questions asked and the number of correctly answered questions so far. Example: Score: 5/7 
}

// at the end store the results in a file quiz_history.txt by appending to the file one line containing:
void store_results()
{
	// name of the quiz file
	// number of questions answered correctly
	// total number of questions
	// difficulty level
}
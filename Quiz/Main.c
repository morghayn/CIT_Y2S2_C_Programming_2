#include "main.h"

int main(void)
{	
	// -> Start
	// Select quiz
	// Select  

	//while (1 == 1)
	//{
		printf("> 1. Start\n> 3. Scoreboard\n> 2. Quit\n> Input option: ");

		//char* buffer;
		//buffer = _getcwd(NULL, 0); // get the current directory
		//buffer = (char*)realloc(buffer, 25);
		//strcat(buffer, "test");
		//printf(buffer);


		//char* clue = malloc(3 * sizeof(char));
		//clue[2] = '\0';
		//printf("\nsize of clue:%d\n", strlen(clue));



		
		//strcat(buffertwo, buffer);
		//read_file("test");
		str_split();


		//printf(buffer);
		//printf("> Hello and welcome to the Quiz game\n");
		//printf("> Please enter a number between 1 and 6: \n");
		//printf("> Start?\n");
		printf("\n");
		system("pause");
	//}

	return 0;
}

void random()
{
	 ///The questions are asked in random order.
}

// initiation
void read_file(const char* filepath)
{
	// open and get the file handle
	FILE* file;
	fopen_s(&file, filepath, "r");

	// check whether file exists
	if (file == NULL)
	{
		printf("\n> File does not exist @ %s.\n> Returning to the main menu.", filepath);
		return;
	}

	// read lines consecutively
	const size_t line_size = 300;
	char* line = malloc(line_size);

	while (fgets(line, line_size, file) != NULL)
	{
		printf(line);
	}

	free(line);    // dont forget to free heap memory
}

// Got from https://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c will learn code and work out a problem to fit my thing
void str_split()
{
		char st[] = "Hello world? No";
		char* ch;
		ch = strtok(st, "?");
		while (ch != NULL) {
			printf("%s\n", ch);
			ch = strtok(NULL, " ,"); // what does strtok do
		}
		//getch();
}

void print_question_quantity()
{
	// print out number of questions from file
}

// start asking questions
void generate_clue()
{
	int difficulty = 0; // (temporary will be in header file)

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
			printf("Something appears to have gone wrong. o,,o");
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
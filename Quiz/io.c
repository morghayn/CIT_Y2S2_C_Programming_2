#include "io.h"

void clear_buffer()
{
	int c = '0';
	while ((c = getchar()) != '\n' && c != EOF);
}

int input_number(int lower, int upper, char *message)
{
    int temp;

    do
    {
		printf(message);
		if (scanf_s("%d[^\n]", &temp) == 0) 
		{
			clear_buffer();
		}
    } while (temp < lower || temp > upper);

	clear_buffer();
    return temp;
}

char* input_word(char* message)
{
	char* string = malloc(1);
	char* temp;
	int i = 0;
	int c;

	printf(message);
	
	while ((c = getchar()) != '\n' && c != EOF)
	{
		string[i++] = c;
		temp = realloc(string, (i * sizeof(char)) + 1);

		// Prevent memory leak
		if (temp == NULL)
		{
			printf("\nExiting!!");
			free(temp);
			exit(0);
		}
		else
		{
			string = temp;
		}

	}
	string[i] = '\0';  // Null terminate the string
	printf("\string : %p\n", string);

	return string;
}

/*
char* get_word()
{
	/* WIP
	printf("> Input selection:\t\t"); // TODO replace with char* message as parameter
	if (fgets(word, NUMBER + 1, stdin))
	{
		char* p;

		if (p = strchr(word, '\n'))
		{
			*p = 0;
		}
		else
		{
			scanf("%*[^\n]");
			scanf("%*c");
		}
	}

	for (int i = 0; word[i]; i++)
	{
		word[i] = tolower(word[i]);
	}
}
	*/
#include "io.h"

int input_number(int lower, int upper, char *message)
{
    int temp;
	char c = '0';

    do
    {
		printf(message);
		if (scanf_s("%d[^\n]", &temp) == 0) 
		{
			while ((c = getchar()) != '\n' && c != EOF);
		}
    } while (temp < lower || temp > upper);

    return temp;
}

/* ~ C-ify this function
int get_number()
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
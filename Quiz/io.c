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
	char* string = malloc(1 * sizeof(char));
	int i = 0;
	int c;

	printf(message);

	while ((c = getchar()) != '\n' && c != EOF)
	{
		if (!string)
		{
			free(string);
			return "Something appears to have gone gravy wrong. o,,o";
		}
		string[i++] = c;
		char* temp;
		temp = realloc(string, (i * sizeof(char)) + 1);
		if (!temp)
		{
			free(string);
			return "Something appears to have gone gravy wrong. o,,o";
		}
		string = temp;
		string[i] = '\0';
	}

	return string;
}
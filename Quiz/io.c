
/* ~ C-ify this function
private static int inputNumber(int smallerThan, int largerThan, String message)
{
    int num;

    do
    {
        System.out.print(message);

        while (!sc.hasNextInt())
        {
            System.out.print(message);
            sc.next();
        }

        num = sc.nextInt();
    } while (num < smallerThan || num > largerThan);

    sc.nextLine();

    return num;
}
*/

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
	*/
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
	*/
}
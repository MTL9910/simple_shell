#include "shell.h"

char *getUserInput(void)
{
	char *text = NULL;
	size_t size = 0;
	ssize_t getNewLine;

	getNewLine = getline(&text, &size, stdin);

	if (getNewLine == -1)
	{
		free(text);
		return (NULL);
	}

	return (text);
	
}

#include "shell.h"

char **line_spliter(char *str)
{
	int i = 0, j = 0;
	char *tok, *temp, **list = NULL, delims[] = " \n\t";

	if (str == NULL)
		return (NULL);

	temp = _strdup(str);
	tok = strtok(temp, delims);
	if (!tok)
	{
		free(str);
		free(temp);
		return (NULL);
	}
	while (tok)
	{
		j++;
		tok = strtok(NULL, delims);
	}
	free(temp);
	list = malloc(sizeof(char *) * (j + 1));
	tok = strtok(str, delims);
	while (tok)
	{
		list[i++] = _strdup(tok);
		tok = strtok(NULL, delims);
	}
	free(str);
	list[i] = NULL;
	return (list);
}

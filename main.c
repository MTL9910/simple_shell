#include "shell.h"

int main(int ac, char **params)
{
	char *str = NULL, **cmmd = NULL;
	int Mode = 0, pos = 0;
	(void) ac;

	while (1 != 0)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		str = input_line();
		if (str == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (Mode);
		}

		pos++;
		cmmd = line_spliter(str);


		if (!cmmd)
			continue;


		Mode = exec_cmd(cmmd, params, pos); 
	}
}

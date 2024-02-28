#include "shell.h"


void invertString(char *str, int len)
{
	char temp;
	int begin = 0;
	int Finale = len - 1;

	while (begin < Finale)
	{
		temp = str[begin];
		str[begin] = str[Finale];
		str[Finale] = temp;
		begin++;
		Finale--;
	}
}

char *_itoa(int n)
{
	char buffer[20];
	int j = 0;

	if (n == 0)
		buffer[j++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[j++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[j] = '\0';
	invertString(buffer, j);

	return (_strdup(buffer));
}

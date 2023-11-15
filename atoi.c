#include "simpleshell.h"

/**
 * interactive - return true if shell is in interactive mode
 * @info: struct address
 *
 * Return: return 1 if interactive mode, 0 if otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Checks whether char is a delimeter
 * @chr: the char to check
 * @delim: this is the delimeter string
 * Return: return 1 if true, 0 if otherwise
 */
int is_delim(char chr, char *delim)
{
	while (*delim)
		if (*delim++ == chr)
			return (1);
	return (0);
}

/**
 * _isalpha - this will check for alphabetic character
 * @chr: The char to input
 * Return: Return 1 if c is alphabetic, otherwise return 0
 */

int _isalpha(int chr)
{
	if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - function  will convert the chr string to an integer
 * @strg: the string to be converted
 * Return: return 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *strg)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; strg[i] != '\0' && flag != 2; i++)
	{
		if (strg[i] == '-')
			sign *= -1;

		if (strg[i] >= '0' && strg[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (strg[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

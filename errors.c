#include "simpleshell.h"

/**
 * _eputs - print an input string val
 * @strg: string to be printed
 *
 * Return: return Nothing
 */
void _eputs(char *strg)
{
	int i = 0;

	if (!strg)
		return;
	while (strg[i] != '\0')
	{
		_eputchar(strg[i]);
		i++;
	}
}

/**
 * _eputchar - the char c to stderr
 * @chr: the character to print
 *
 * Return: return 1 On success
 * On error, -1 is returned, and errno is set properly.
 */
int _eputchar(char chr)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (chr == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (chr != BUF_FLUSH)
		buf[i++] = chr;
	return (1);
}

/**
 * _putfd - writes the character chr to valfd
 * @chr: The char to print
 * @valfd: this is the filedescriptor to write into
 *
 * Return: Return 1 on success
 * On error, -1 is returned, and errno is set properly
 */
int _putfd(char chr, int valfd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (chr == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(valfd, buf, i);
		i = 0;
	}
	if (chr != BUF_FLUSH)
		buf[i++] = chr;
	return (1);
}

/**
 * _putsfd - prints an string value
 * @strg: this is the string to be printed
 * @valfd: the filedescriptor to write into
 *
 * Return: the number of chars put
 */
int _putsfd(char *strg, int valfd)
{
	int i = 0;

	if (!strg)
		return (0);
	while (*strg)
	{
		i += _putfd(*strg++, valfd);
	}
	return (i);
}

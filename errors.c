#include "simpleshell.h"

/**
 * _eputs - Print an input string to stderr.
 * @strg: String to be printed.
 *
 * Return: Nothing.
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
 * _eputchar - Print the character to stderr.
 * @chr: Character to print.
 *
 * Return: 1 on success, -1 on error (sets errno properly).
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
 * _putfd - Write the character to a file descriptor.
 * @chr: The character to print.
 * @valfd: File descriptor to write into.
 *
 * Return: 1 on success, -1 on error (sets errno properly).
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
 * _putsfd - Print a string to a file descriptor.
 * @strg: The string to be printed.
 * @valfd: File descriptor to write into.
 *
 * Return: The number of characters written.
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

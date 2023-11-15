#include "simpleshell.h"

/**
 * _erratoi - function that converts a string to an integer
 * @strg: the string to be changed
 * Return: return 0 if no numbers in string, converted number otherwise
 * -1 on error
 */
int _erratoi(char *strg)
{
	int i = 0;
	unsigned long int result = 0;

	if (*strg == '+')
		strg++;
	for (i = 0;  strg[i] != '\0'; i++)
	{
		if (strg[i] >= '0' && strg[i] <= '9')
		{
			result *= 10;
			result += (strg[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - print error message
 * @info: the parameter and the return info struct
 * @estr: string stores the exact error type
 * Return: return 0 if no numbers in string, changed number otherwise
 * -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function that print a decimal
 * @input: input val
 * @valfd: file_descriptor to write to
 *
 * Return: return number of char printed
 */
int print_d(int input, int valfd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (valfd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - number converter function
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: return string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function that replace comment with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always return 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

#include "simpleshell.h"

/**
 * _strncpy - Copy a string.
 * @dest: Destination to be copied to.
 * @src: Source string.
 * @nm: Number of characters to be copied.
 * Return: Return the concatenated string.
 */
char *_strncpy(char *dest, char *src, int nm)
{
	int i, j;
	char *strg = dest;

	i = 0;
	while (src[i] != '\0' && i < nm - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < nm)
	{
		j = i;
		while (j < nm)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (strg);
}

/**
 * _strncat - Concatenate two strings.
 * @dest: First string.
 * @src: Second string.
 * @nm: Number of bytes to be used.
 * Return: The concatenated string.
 */
char *_strncat(char *dest, char *src, int nm)
{
	int i, j;
	char *strg = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nm)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < nm)
		dest[i] = '\0';
	return (strg);
}

/**
 * _strchr - Find a character in a string.
 * @strg: String to be passed.
 * @chr: The character to look for.
 * Return: A pointer to the memory area s.
 */
char *_strchr(char *strg, char chr)
{
	do {
		if (*strg == chr)
			return (strg);
	} while (*strg++ != '\0');

	return (NULL);
}

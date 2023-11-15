#include "simpleshell.h"

/**
 **_strncpy - function to copy  string
 *@dest: destination to be copied to
 *@src: source string
 *@nm: number of char to be copied
 *Return: return the concatenated string
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
 **_strncat - concatenating two strings
 *@dest: first string
 *@src: second string
 *@nm: number of bytes to be used
 *Return: the concatenated string
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
 **_strchr - func to find a char in a string
 *@strg: string to be passed
 *@chr: the char to look for
 *Return: return (s) a pointer to the memory area s
 */
char *_strchr(char *strg, char chr)
{
	do {
		if (*strg == chr)
			return (strg);
	} while (*strg++ != '\0');

	return (NULL);
}

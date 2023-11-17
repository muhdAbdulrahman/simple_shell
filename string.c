#include "simpleshell.h"

/**
* _strlen - Returns the length of a string.
* @s: String to check.
*
* Return: The integer length of the string.
*/
int _strlen(char *s)
{
int i = 0;

if (!s)
return (0);

while (*s++)
i++;
return (i);
}

/**
* _strcmp - Performs lexicographic comparison of two strings.
* @s1: First string.
* @s2: Second string.
*
* Return: Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2.
*/
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
* starts_with - Checks if a string starts with another.
* @haystack: String to search.
* @needle: Substring to find.
*
* Return: Address of the next character of haystack else NULL.
*/
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
* _strcat - Concatenates strings.
* @dest: Destination buffer.
* @src: Source buffer.
*
* Return: Pointer to buffer location.
*/
char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}

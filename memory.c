#include "simpleshell.h"

/**
 * bfree - fxn that NULLs the address and free pointer
 * @ptr: pointer address
 *
 * Return: Return 1 if freed, Return 0 if otherwise
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

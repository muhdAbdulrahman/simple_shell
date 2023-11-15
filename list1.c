#include "simpleshell.h"

/**
 * list_len - fxn that shows length of list
 * @f: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *f)
{
	size_t i = 0;

	while (f)
	{
		f = f->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - fxn that return array of strings
 * @head: pointer to first node
 *
 * Return: return array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - fxn of elements of a linkedlist
 * @f: pointer to the first node
 *
 * Return: return size of lthe ist
 */
size_t print_list(const list_t *f)
{
	size_t i = 0;

	while (f)
	{
		_puts(convert_number(f->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(f->str ? f->str : "(nil)");
		_puts("\n");
		f = f->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - fxn that return node string that begins with prefix
 * @node: pointer head
 * @prefix: prefix string
 * @nextc: next character after prefix to be match
 *
 * Return: return match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char nextc)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((nextc == -1) || (*p == nextc)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - fxn to get index of a node
 * @head: points to head
 * @node: points to the node
 *
 * Return: return index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

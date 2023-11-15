#include "simpleshell.h"

/**
 * _myhistory - shows the history
 * @info: Struct having potential args.
 *  Return: Always return 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - set alias to a string value
 * @info: parameter struct
 * @str: string alias
 *
 * Return: Always return 0 on success, 1 if otherwise
 */
int unset_alias(info_t *info, char *str)
{
	char *a, b;
	int ret;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	b = *a;
	*a = 0;
	ret = delete_node_at_index(&(info->alias),
				   get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*a = b;
	return (ret);
}

/**
 * set_alias - set alias to a string value
 * @info: parameter struct
 * @str: string alias
 *
 * Return: Always return 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *a;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - print alias string value
 * @node: alias node
 *
 * Return: Always return 0 on success, 1 if void
 */
int print_alias(list_t *node)
{
	char *a = NULL, *c = NULL;

	if (node)
	{
		a = _strchr(node->str, '=');
		for (c = node->str; c <= a; c++)
		_putchar(*c);
		_putchar('\'');
		_puts(a + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - funtion that copies the alias builtin
 * @info: Struct having potential args.
 *  Return: Always return 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *a = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		a = _strchr(info->argv[i], '=');
		if (a)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

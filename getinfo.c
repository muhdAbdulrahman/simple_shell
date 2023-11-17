#include "simpleshell.h"

/**
 * clear_info - Initialize the info_t struct.
 * @info: Struct address.
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - Set the info_t struct.
 * @info: Struct address.
 * @av: Argument vector.
 */
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - Free info_t struct fields.
 * @info: Struct address.
 * @fld: 1 if all fields are freed, 0 otherwise.
 */
void free_info(info_t *info, int fld)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (fld)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)


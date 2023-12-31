#include "simpleshell.h"

/**
* get_environ - Return an array of strings.
* @info: Struct containing potential args.
* Return: Always return 0.
*/
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}

return (info->environ);
}

/**
* _unsetenv - Remove an environment variable.
* @info: Struct containing potential args.
* @var: The string environment variable property.
* Return: 1 on delete, otherwise return 0.
*/
int _unsetenv(info_t *info, char *var)
{
list_t *node = info->env;
size_t i = 0;
char *a;

if (!node || !var)
return (0);

while (node)
{
a = starts_with(node->str, var);
if (a && *a == '=')
{
info->env_changed = delete_node_at_index(&(info->env), i);
i = 0;
node = info->env;
continue;
}
node = node->next;
i++;
}
return (info->env_changed);
}

/**
* _setenv - Initialize a new environment variable or modify if exists.
* @info: Struct containing potential args.
* @var: The string environment variable property.
* @value: The string environment variable value.
* Return: Always return 0.
*/
int _setenv(info_t *info, char *var, char *value)
{
char *buf = NULL;
list_t *node;
char *a;

if (!var || !value)
return (0);

buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return (1);
_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);
node = info->env;
while (node)
{
a = starts_with(node->str, var);
if (a && *a == '=')
{
free(node->str);
node->str = buf;
info->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(info->env), buf, 0);
free(buf);
info->env_changed = 1;
return (0);
}

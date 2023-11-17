#include "simpleshell.h"

/**
* list_len - Function to determine the length of a linked list.
* @head: Pointer to the first node.
*
* Return: Size of the list.
*/
size_t list_len(const list_t *head)
{
size_t count = 0;

while (head)
{
head = head->next;
count++;
}
return (count);
}

/**
* list_to_strings - Function to convert a linked list of strings into an array of strings.
* @head: Pointer to the first node.
*
* Return: Array of strings.
*/
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t len = list_len(head), index;
char **str_array;
char *str;

if (!head || !len)
return (NULL);

str_array = malloc(sizeof(char *) * (len + 1));
if (!str_array)
return (NULL);

for (index = 0; node; node = node->next, index++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
while (index-- > 0)
free(str_array[index]);
free(str_array);
return (NULL);
}

str = _strcpy(str, node->str);
str_array[index] = str;
}

str_array[index] = NULL;
return (str_array);
}

/**
* print_list - Function to print elements of a linked list.
* @head: Pointer to the first node.
*
* Return: Size of the list.
*/
size_t print_list(const list_t *head)
{
size_t count = 0;

while (head)
{
_puts(convert_number(head->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(head->str ? head->str : "(nil)");
_puts("\n");
head = head->next;
count++;
}

return (count);
}

/**
* node_starts_with - Function to return the node whose string begins with a given prefix.
* @node: Pointer to the first node.
* @prefix: Prefix string.
* @next_char: Next character after the prefix to match.
*
* Return: Node that matches the criteria, or NULL if none found.
*/
list_t *node_starts_with(list_t *node, char *prefix, char next_char)
{
char *str_ptr = NULL;

while (node)
{
str_ptr = starts_with(node->str, prefix);
if (str_ptr && ((next_char == -1) || (*str_ptr == next_char)))
return (node);
node = node->next;
}

return (NULL);
}

/**
* get_node_index - Function to get the index of a node in a linked list.
* @head: Points to the head of the list.
* @node: Points to the node.
*
* Return: Index of the node or -1 if not found.
*/
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t index = 0;

while (head)
{
if (head == node)
return (index);
head = head->next;
index++;
}

return (-1);
}

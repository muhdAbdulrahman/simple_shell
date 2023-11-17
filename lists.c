#include "simpleshell.h"

/**
 * add_node - Function to add a node to the start of the list.
 * @head: Address of pointer to head node.
 * @str: Node string.
 * @num: Node index used by history.
 *
 * Return: Pointer to the newly added node.
 */
list_t *add_node(list_t **head, const char *str, int num)
{
    list_t *new_node;

    if (!head)
        return (NULL);

    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);

    _memset((void *)new_node, 0, sizeof(list_t));
    new_node->num = num;

    if (str)
    {
        new_node->str = _strdup(str);
        if (!new_node->str)
        {
            free(new_node);
            return (NULL);
        }
    }

    new_node->next = *head;
    *head = new_node;
    return (new_node);
}

/**
 * add_node_end - Function to add a node to the end of the list.
 * @head: Address of pointer to head node.
 * @str: Node string.
 * @num: Node index used by history.
 *
 * Return: Pointer to the newly added node.
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
    list_t *new_node, *node;

    if (!head)
        return (NULL);

    node = *head;
    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);

    _memset((void *)new_node, 0, sizeof(list_t));
    new_node->num = num;

    if (str)
    {
        new_node->str = _strdup(str);
        if (!new_node->str)
        {
            free(new_node);
            return (NULL);
        }
    }

    if (node)
    {
        while (node->next)
            node = node->next;
        node->next = new_node;
    }
    else
    {
        *head = new_node;
    }

    return (new_node);
}

/**
 * print_list_str - Function to print the str element of a list_t.
 * @head: Pointer to the first node.
 *
 * Return: Size of the list.
 */
size_t print_list_str(const list_t *head)
{
    size_t count = 0;

    while (head)
    {
        _puts(head->str ? head->str : "(nil)");
        _puts("\n");
        head = head->next;
        count++;
    }

    return (count);
}

/**
 * delete_node_at_index - Function to delete a node at a specific index.
 * @head: Pointer to pointer to the first node.
 * @index: Index of the node to delete.
 *
 * Return: 1 on success, 0 if void.
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
    list_t *node, *prev_node;
    unsigned int i = 0;

    if (!head || !*head)
        return (0);

    if (!index)
    {
        node = *head;
        *head = (*head)->next;
        free(node->str);
        free(node);
        return (1);
    }

    node = *head;
    while (node)
    {
        if (i == index)
        {
            prev_node->next = node->next;
            free(node->str);
            free(node);
            return (1);
        }
        i++;
        prev_node = node;
        node = node->next;
    }

    return (0);
}

/**
 * free_list - Function to free nodes of a list.
 * @head_ptr: Pointer to pointer to head node.
 *
 * Return: Void.
 */
void free_list(list_t **head_ptr)
{
    list_t *node, *next_node, *head;

    if (!head_ptr || !*head_ptr)
        return;

    head = *head_ptr;
    node = head;
    while (node)
    {
        next_node = node->next;
        free(node->str);
        free(node);
        node = next_node;
    }

    *head_ptr = NULL;
}
